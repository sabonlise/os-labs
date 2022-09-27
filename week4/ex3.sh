gcc ex3.c -o ex3
./ex3 3 &

printf "Running program for n = 3:\n"
for i in $(seq 1 3); do
        pstree $$
        if [ "$i" != 3 ]; then 
                sleep 5
        fi
done

printf "\nRunning program for n = 5:\n"
./ex3 5 &
for i in $(seq 1 5); do
        pstree $$
        if [ "$i" != 5 ]; then
                 sleep 5
        fi
done
