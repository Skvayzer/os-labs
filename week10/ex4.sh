if [ ! -d ./tmp ]; then
  mkdir -p ./tmp;
fi
cd tmp
touch file1
touch file2
FILE=./link1
if [ ! -f "$FILE" ]; then
    ln file1 link1
fi
cd ..
gcc -o ex4 ex4.c
./ex4 > ex4.txt
