sleep 3 | date
mkdir root | echo "Creating root folder"
sleep 3 | date
ls -tr / > root/root.txt | echo "Creating root.txt file"
sleep 3 | date
mkdir home
echo "Creating home folder"
sleep 3 | date
ls -tr ~ > home/home.txt
echo "Creating home.txt file"
sleep 3 | date
echo "Displaying contents of root folder"
ls root
echo "Displaying contents of root.txt"
cat root/root.txt
echo "Displaying contents of home folder"
ls home
echo "Displaying contents of home.txt"
cat home/home.txt
