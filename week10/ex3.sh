touch _ex3.txt
echo "Konstantin Smirnov" > _ex3.txt
chmod a-x _ex3.txt > ex3.txt
stat ./_ex3.txt >> ex3.txt
echo -en '\n' >> ex3.txt

chmod uo+rwx _ex3.txt >> ex3.txt
stat ./_ex3.txt >> ex3.txt
echo -en '\n' >> ex3.txt

chmod g=u _ex3.txt >> ex3.txt
stat ./_ex3.txt >> ex3.txt
echo -en '\n' >> ex3.txt

echo "660 is -w--w-r--" >> ex3.txt
echo "775 is r-----rwx" >> ex3.txt
echo "777 is r----x--x" >> ex3.txt
