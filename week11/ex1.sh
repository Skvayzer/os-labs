if [ ! -f ./lofs.img ]; then
    sudo fallocate -l 50M lofs.img #allocate 50MB for the file
    # check: if there's no loop device for lofs.img
fi
sudo losetup -f lofs.img #find a free loop device

# losetup -a #look at all loop devices


# sudo mkfs . #existing filesystems
device=$(losetup -a | grep 'lofs.img' | awk '{print $1}' | tr -d :) # find the path of the created loop device and delete : symbol


sudo mkfs.ext4 device # create filesystem for the loop device

if [ ! -d ./lofsdisk ]; then
    mkdir lofsdisk # directory for mounting
fi
sudo mount $device lofsdisk/ #mount the device to the directory

#losetup -d <path> #remove (detach) the loop device
