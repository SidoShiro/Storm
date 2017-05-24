/* First Come First Serve Scheduling */

#include <stdio.h>
#include <stdlib.h>

/* Std Process Structure */
struct process {
    int ID;
    int burstTime;
    int totalTime;
    int waitTime;
};


/* Main Fun */
int main() {
    int i;
    int j;
    int k;
    int number;
    int totalTurnTime = 0;
    int totalWaitTime = 0;

    float averageTurnTime;
    float averageWaitTime;

    printf("\n Scheduling \n\n");

    /* Number of process selection */
    printf("Number of processes ? :>");
    scanf("%d", &number);
    printf("\n");

    /* CAlloc Array of processes */
    struct process *process = (struct process*)calloc(number, 
            sizeof(struct process));

    /* Burst time and ID attribution */
    for(i = 0; i < number; i++) {
        scanf("%d", &(process[i].burstTime));
        process[i].ID = i + 1;
    }
    printf("\n");

    process[0].waitTime = 0;
    process[0].totalTime = process[0].burstTime;

    /* waitTime and TotalTime calculation */
    for(i = 1; i < number; i++) { /* start at 1, 0 already done 1 line up */
        process[i].waitTime = process[i - 1].totalTime;
        process[i].totalTime = process[i].waitTime + process[i].burstTime;
    }

    /* */
    for(i = 0; i < number; i++) {
        totalWaitTime += process[i].waitTime;
        totalTurnTime += process[i].totalTime;
    }

    averageWaitTime = (float) totalWaitTime / number;
    averageTurnTime = (float) totalTurnTime / number;

    printf("\n FCFS Scheduling \n");

    i = 32;
    while(i--){
        printf("-");
    }
    printf("\n");

    printf("Process\t W-Time\t B-Time\t T-Time\t \n");

    i = 32;
    while(i--) {
        printf("-");
    }
    printf("\n");

    for(i = 0; i < number; i++) {
        printf("%4s%d\t %6d\t %6d\t %6d\t \n", 
                "P", 
                process[i].ID, 
                process[i].waitTime, 
                process[i].burstTime, 
                process[i].totalTime);
    }

    i = 32;
    while(i--) {
        printf("-");
    }
    printf("\n");

    printf("\n");
    printf("Gantt Chart \n\n");

    i = totalTurnTime - totalWaitTime + number * 2 + 1;
    
    printf("|");
    for(i = 0; i < number; i++) {
        k = process[i].burstTime / 2;
        for(j = 0; j < k; j++) {
            printf(" ");
        }
        printf("P%d", process[i].ID);
        for(j = k + 1; j < process[i].burstTime; j++) {
            printf(" ");
        }
        printf("|");
    }

    i = totalTurnTime - totalWaitTime + number * 2 + 1;
    printf("\n%d", 0);

    for(i = 0; i < number; i++) {
        for(j = 0; j < process[i].burstTime; j++) {
            printf(" ");
        }
        printf("%2d", process[i].totalTime);
    }
    printf("\n");

    printf("\nAverage Wait Time : %.2f ms \n", averageWaitTime);
    printf("Average TurnAround Time : %.2f ms \n\n", averageTurnTime);

    return 0;

}
