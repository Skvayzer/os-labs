if [ ! -d ./week1 ]; then
  mkdir -p ./week1;
fi
touch ./week1/file.txt
echo "Konstantin Smirnov" > ./week1/file.txt
if [ ! -d ./week10 ]; then
  mkdir -p ./week10;
fi
FILE=./week10/_ex2.txt
if [ ! -f "$FILE" ]; then
    link ./week1/file.txt ./week10/_ex2.txt
fi

find ./week10/_ex2.txt -inum $(ls -i ./week10/_ex2.txt | awk '{print $1}') > ex2.txt
find ./week10/_ex2.txt -inum $(ls -i ./week10/_ex2.txt | awk '{print $1}') -exec rm {} \; >> ex2.txt
