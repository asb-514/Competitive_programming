CXX := clang++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -pedantic -Wshadow 
DEBUG_CXXFLAGS := -DONPC -g -fsanitize=address -fsanitize=undefined -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize-recover=all -fstack-protector-all
DEBUG_CXXFLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC

PCH := ~/Documents/contest/pch/bits/stdc++.h
PCH_PCH := $(PCH).pch

all: $(PCH_PCH) main

pch: $(PCH)
	$(CXX) -x c++-header $(CXXFLAGS) $(DEBUG_CXXFLAGS) $< -o $(PCH_PCH)

$(PCH_PCH): $(PCH)
	$(CXX) -x c++-header $(CXXFLAGS) $(DEBUG_CXXFLAGS) $< -o $@

main: main.cpp $(PCH_PCH)
	$(CXX) $(CXXFLAGS) $(DEBUG_CXXFLAGS) -include-pch $(PCH_PCH) main.cpp -o main

test: main
	@for infile in test/*.in; do \
		outfile=$$(echo $$infile | sed 's/\.in$$/.out/'); \
		echo "Running test: $$infile"; \
		./main < $$infile > tmp.out; \
		if diff -q tmp.out $$outfile > /dev/null; then \
			echo "Test $$infile passed"; \
		else \
			echo "Test $$infile failed"; \
			diff $$outfile tmp.out; \
		fi; \
	done
	rm -f tmp.out

clean:
	rm -f main $(PCH_PCH)
