gcc subscriber.c -o subscriber
gcc publisher.c -o publisher

for i in $(seq 1 $1); do
	gnome-terminal -- ./subscriber "$1"
done
./publisher
