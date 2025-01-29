TARGET := main
EXECUTE := ./$(TARGET)
CLEAN_TARGETS := $(TARGET)
DEBUG := true

CXX := clang++
PCH := ~/Documents/contest/pch/bits/stdc++.h
PCH_PCH := $(PCH).pch
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -pedantic -Wshadow 
DEBUG_CXXFLAGS := -DONPC -g -fsanitize=address -fsanitize=undefined -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow 
DEBUG_CXXFLAGS += -fno-sanitize-recover=all -fstack-protector-all -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC


CLEAN_TARGETS += $(PCH_PCH)
ifeq ($(DEBUG),true)
CXXFLAGS += $(DEBUG_CXXFLAGS)
endif

INPUT := $(wildcard test/*.in)
OUTPUT := $(INPUT:.in=.out)
RESULT := $(INPUT:.in=.res)
TESTRULE := $(INPUT:.in=.res_compare) 

all : $(TARGET) test
.PHONY: all

clean:
	-rm -rf $(CLEAN_TARGETS) $(TARGET).dSYM
.PHONY: clean

veryclean:
	-rm -rf $(CLEAN_TARGETS) $(TARGET).dSYM brute* gen* s.sh compile.sh in* out*
.PHONY: veryclean

$(PCH_PCH): $(PCH)
	$(CXX) -x c++-header $(CXXFLAGS) $< -o $@

$(TARGET): $(TARGET).cpp $(PCH_PCH) 
	$(CXX) $(CXXFLAGS) -include-pch $(PCH_PCH) $< -o $@

export TIME=\n  real\t%es\n  user\t%Us\n  sys\t%Ss\n  mem\t%MKB

run: $(TARGET)
	\time $(EXECUTE)
ifeq ($(DEBUG),true)
	@echo "Built with DEBUG flags enabled, code may be slower than normal"
endif
.PHONY: run

%.res: $(TARGET) %.in
	\time $(EXECUTE) < $*.in > $*.res
ifeq ($(DEBUG),true)
	@echo "Built with DEBUG flags enabled, code may be slower than normal"
endif

%.res_compare: %.res %.out
	-diff $*.res $*.out

test: $(RESULT) $(TESTRULE)
.PHONY: test
