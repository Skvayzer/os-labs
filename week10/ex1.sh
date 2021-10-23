touch _ex1.txt
echo "Konstantin Smirnov" > _ex1.txt
FILE=_ex1_1.txt
if [ ! -f "$FILE" ]; then
    ln _ex1.txt _ex1_1.txt
fi
FILE=_ex1_2.txt
if [ ! -f "$FILE" ]; then
    ln _ex1.txt _ex1_2.txt
fi
ls -i | awk '$2 == "_ex1.txt" {print}' >> ex1.txt
ls -i | awk '$2 == "_ex1_1.txt" {print}' >> ex1.txt
ls -i | awk '$2 == "_ex1_2.txt" {print}' >> ex1.txt
