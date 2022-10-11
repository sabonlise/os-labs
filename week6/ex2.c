#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int id;
} Process;


int compare(const Process *p1, const Process *p2) {
    return (p1->arrival_time < p2->arrival_time || (p1->arrival_time == p2->arrival_time && p1->burst_time < p2->burst_time)) ? -1 : 1;
}

void swap(int *x, int *y) {
    if (*x == *y) return;
    *x = (*x * *y) / (*y = *x);
}


int main() {
    int n;

    long double total_waiting_time = 0, total_turnaround_time = 0;
    printf("Enter the number of processes: ");
    fscanf(stdin, "%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of the process %d: \n", i + 1);
        fscanf(stdin, "%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i;
    }

    qsort(&processes, sizeof(processes) / sizeof(Process), sizeof(Process), (int (*) (const void *, const void *)) &compare);
    /** test from lab
       14
       0 1
       0 1
       0 1
       3 1
       3 2
       3 3
       7 3
       7 2
       7 1
       13 1
       13 2
       13 3
       17 1
       17 2
     */

    unsigned int min = 0xFFFFFFFF, index;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].completion_time = processes[i].arrival_time + processes[i].burst_time;
        } else {
            for (int j = i; j < n; j++) {
                if (processes[i - 1].completion_time >= processes[j].arrival_time) {
                    if (processes[j].burst_time < min) {
                        min = processes[j].burst_time;
                        index = j;
                    }
                }
            }

            swap(&processes[i].id, &processes[index].id);
            swap(&processes[i].arrival_time, &processes[index].arrival_time);
            swap(&processes[i].burst_time, &processes[index].burst_time);

            min = 0xFFFFFFFF;

            processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
        }

        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        printf("%d) Process #%d:\n", i + 1, processes[i].id + 1);
        printf("\tCompletion time: %d\n", processes[i].completion_time);
        printf("\tTurnaround time: %d\n", processes[i].turnaround_time);
        printf("\tWaiting time: %d\n", processes[i].waiting_time);
    }

    printf("Average Turnaround time: %.3Lf\n", total_turnaround_time / n);
    printf("Average waiting time: %.3Lf\n", total_waiting_time / n);
}
