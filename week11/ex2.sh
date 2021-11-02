#sh ex1.sh

directory=lofsdisk
echo "Konstantin" >> $directory/file1.txt
echo "Smirnov" >> $directory/file2.txt

sudo chmod 777 $directory/

#sudo cp file1 lofsdisk/  # Firas created the files in week11 and then copied them to lofsdisk for some reason


# EXAMPLE
# mkdir folder2
# sudo chroot folder2

sudo mkdir -p $directory/{bin,lib64,lib} #create folders for bash commands
sudo cp /bin/{bash,ls,cat,echo} $directory/bin # copy bash commands to the new filesystem
# cd lofsdisk
# ldd /bin/bash
# sudo cp /bin/bash/ lofsdisk/bin
# ldd ex2.out # get the shared libraries of the file
# paths=$(ldd /bin/bash | grep '/' | awk '/[/]/{print $3}') #find all paths to the libraries
# echo "$paths" | while IFS= read -r line ;
# do
#     cp -v $line $(awk '//*//{print}');
# done
list="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp "$i" "${directory}${i}"; done

list="$(ldd /bin/cat | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp "$i" "${directory}${i}"; done

list="$(ldd /bin/echo | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp "$i" "${directory}${i}"; done

list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp "$i" "${directory}${i}"; done

# sudo chroot lofsdisk/ bash # still won't work
# sudo mkdir lofsdisk/usr/lib/
# sudo cp /usr/lib/libreadline.so.8 lofsdisk/ # copy the shared libraries for the command should do it for all shared libraries, just loop through

# sudo cp /bin/ls lofsdisk/bin
# sudo chroot lofsdisk/ #execute the default command (bash, then you can execute bash commands)

#then in bash you execute ls and print all the folders
sudo gcc -o ex2.out ex2.c
# sudo chroot lofsdisk/ ./ex2  # changes the root directory and executes the command

sudo cp ./ex2.out $directory/

echo "~~~~~~Changing the root~~~~~~" > ex2.txt
sudo chroot $directory ./ex2.out >> ex2.txt

echo "~~~~~~Without changing the root~~~~~~" >> ex2.txt
./ex2.out >> ex2.txt
#output should be like >ls /

# sudo umount $directory
#remove (detach) the loop device
# losetup -d <path>
# sudo umount /dev/loop19



