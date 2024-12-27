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

clean:
	rm -f main $(PCH_PCH)


# +-----------------------+
# |                       |
# |   RUNNING / TESTING   |
# |                       |
# +-----------------------+
export TIME=\n  real\t%es\n  user\t%Us\n  sys\t%Ss\n  mem\t%MKB

run: main 
	./main

test: main
	@GREEN="\033[1;32m"; \
	RED="\033[1;31m"; \
	RESET="\033[0m"; \
	for infile in test/*.in; do \
		outfile=$$(echo $$infile | sed 's/\.in$$/.out/'); \
		printf "Running tests on $$infile "; \
		./main < $$infile > tmp.out 2> tmp.err; \
		if diff -Z -q tmp.out $$outfile > /dev/null; then \
			printf "$${GREEN}passed$${RESET}\n"; \
		else \
			printf "$${RED}failed$${RESET}\n"; \
		fi; \
	done; \
	rm -f tmp.out tmp.err

debug-test: main
	@GREEN="\033[1;32m"; \
	RED="\033[1;31m"; \
	RESET="\033[0m"; \
	for infile in test/*.in; do \
		outfile=$$(echo $$infile | sed 's/\.in$$/.out/'); \
		echo "----------------Running test (debug mode): $$infile -----------------"; \
		./main < $$infile > tmp.out 2> tmp.err; \
		echo "Input:"; \
		cat $$infile; \
		if [ -s tmp.err ]; then \
			echo "\nCaptured stderr:"; \
			cat tmp.err; \
		fi; \
		echo "\nYour output:"; \
		cat tmp.out; \
		echo "\nCorrect output:"; \
		cat $$outfile; \
		if diff -Z -q tmp.out $$outfile > /dev/null; then \
			printf "$${GREEN}passed$${RESET}\n"; \
		else \
			printf "$${RED}failed$${RESET}\n"; \
			echo "\nDifference:"; \
			diff -Z --color='always' tmp.out $$outfile ; \
		fi; \
	done; \
	rm -f tmp.out tmp.err
