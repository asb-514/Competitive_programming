set -e 
bash compile.sh
for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > inp
    ./main < inp > out1
    ./brute < inp > out2
    diff -w out1 out2 || break
    # diff -w <(./main < inp) <(./brute < inp) || break
done

echo "Failed for test case :"
cat inp
echo "Main output"
cat out1
echo "Brute ouput"
cat out2
