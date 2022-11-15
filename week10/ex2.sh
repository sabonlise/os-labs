link ../week01/file.txt  _ex2.txt
inode=$(ls -i ../week01/file.txt | cut -d " " -f 1)
find ../week01/file.txt -inum $inode > ex2.txt
find ../week01/file.txt -inum $inode -exec rm {} \; >> ex2.txt
