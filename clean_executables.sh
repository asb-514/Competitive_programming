cd atcoder
find . -maxdepth 2 -mindepth 2 -type d \( ! -name . \) -exec bash -c "cd '{}' && make veryclean" \;
cd ..
cd codeforces
find . -maxdepth 2 -mindepth 2 -type d \( ! -name . \) -exec bash -c "cd '{}' && make veryclean" \;
cd ..
cd codechef
find . -maxdepth 2 -mindepth 2 -type d \( ! -name . \) -exec bash -c "cd '{}' && make veryclean" \;
cd ..
