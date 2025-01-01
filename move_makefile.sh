cd atcoder
find . -maxdepth 2 -mindepth 2 -type d \( ! -name . \) -exec bash -c "cd '{}' && cp ../../../Makefile ./" \;
cd ..
cd codeforces
find . -maxdepth 2 -mindepth 2 -type d \( ! -name . \) -exec bash -c "cd '{}' && cp ../../../Makefile ./" \;
cd ..
cd codechef
find . -maxdepth 2 -mindepth 2 -type d \( ! -name . \) -exec bash -c "cd '{}' && cp ../../../Makefile ./" \;
cd ..
