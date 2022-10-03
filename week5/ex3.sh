gcc -pthread ex3.c -o ex3

echo 'time for 1 thread:'
time ./ex3 10000000 1
echo 'time for 2 threads:'
time ./ex3 10000000 2
echo 'time for 4 threads:'
time ./ex3 10000000 4
echo 'time for 10 threads:'
time ./ex3 10000000 10
echo 'time for 100 threads:'
time ./ex3 10000000 100
