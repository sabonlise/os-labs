#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0


typedef struct Process {
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int id;
} Process;


int compare(const Process *p1, const Process *p2) {
    return (p1->arrival_time < p2->arrival_time || (p1->arrival_time == p2->arrival_time && p1->id < p2->id)) ? -1 : 1;
    // added stability to quicksort but i think it is not really necessary
}


int main() {
    int n;
    short int quantum;
    long double total_waiting_time = 0, total_turnaround_time = 0;

    printf("Enter the number of processes: ");
    fscanf(stdin, "%d", &n);

    printf("Enter the quantum value: ");
    fscanf(stdin, "%hd", &quantum);

    Process processes[n];
    int local_burst[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of the process %d: \n", i + 1);
        fscanf(stdin, "%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i;
    }

    qsort(&processes, sizeof(processes) / sizeof(Process), sizeof(Process), (int (*) (const void *, const void *)) &compare);

    for (int i = 0; i < n; i++) {
        local_burst[i] = processes[i].burst_time;
    }

    unsigned int completed = True;
    int current_process = n;

    for (int i = 0, current_time = 0; current_process != 0;) {

        if (quantum >= local_burst[i] && local_burst[i] != 0) {
            current_time += local_burst[i];
            local_burst[i] = 0;
            completed = True;
        } else if (local_burst[i] > 0) {
            local_burst[i] -= quantum;
            current_time += quantum;
        }

        if (local_burst[i] == 0 && completed == True) {
            processes[i].turnaround_time = current_time - processes[i].arrival_time;
            processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
            processes[i].completion_time = current_time;

            printf("%d) Process #%d:\n", n - current_process + 1, processes[i].id + 1);
            printf("\tCompletion time: %d\n", processes[i].completion_time);
            printf("\tTurnaround time: %d\n", processes[i].turnaround_time);
            printf("\tWaiting time: %d\n", processes[i].waiting_time);

            total_waiting_time += processes[i].waiting_time;
            total_turnaround_time += processes[i].turnaround_time;

            completed = False;
            current_process--;
        }

        if (processes[i + 1].arrival_time <= current_time) i++;
        else if (i == n - 1) i = 0;
    }

    printf("Average Turnaround time: %.3Lf\n", total_turnaround_time / n);
    printf("Average waiting time: %.3Lf\n", total_waiting_time / n);
}
