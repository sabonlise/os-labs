#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;


int compare(const Process *p1, const Process *p2) {
    return p1->arrival_time < p2->arrival_time ? -1 : 1;
}


int main() {
    int n;
    long double total_waiting_time = 0, total_turnaround_time = 0;

    fscanf(stdin, "%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of the process %d: \n", i + 1);
        fscanf(stdin, "%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    qsort(&processes, sizeof(processes) / sizeof(Process), sizeof(Process), (int (*) (const void *, const void *)) &compare);
    
    for (int i = 0; i < n; i++) {
        processes[i].completion_time = ((i == 0) || (processes[i].arrival_time >= processes[i - 1].completion_time)) ?
                processes[i].arrival_time + processes[i].burst_time :
                processes[i - 1].completion_time + processes[i].burst_time;

        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        printf("%d process:\n", i + 1);
        printf("\tCompletion time: %d\n", processes[i].completion_time);
        printf("\tTurnaround time: %d\n", processes[i].turnaround_time);
        printf("\tWaiting time: %d\n", processes[i].waiting_time);
    }

    printf("Average Turnaround time: %.3Lf\n", total_turnaround_time / n);
    printf("Average waiting time: %.3Lf\n", total_waiting_time / n);
}
