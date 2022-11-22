sudo dd if=/dev/zero of=lofs.img bs=50MB count=1
sudo losetup -f lofs.img
path=$(losetup -j lofs.img | cut -d ":" -f 1)
sudo mkfs.ext4 $path
mkdir lofsdisk
sudo mount $path lofsdisk
