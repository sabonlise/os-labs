gcc subscriber.c -o subscriber
gcc publisher.c -o publisher

gnome-terminal -- ./subscriber
./publisher
