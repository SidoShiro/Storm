/* Round Robin Scheduling */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Std Process Structure */
struct process {
    int ID;
    int burstTime;
    int totalTime;
    int waitTime;
    int burstDone;
};

struct list {
    struct process* elmt;
    struct list * next;
};

void add(int ID, int burst, struct list* head) {
    struct list* jojo = head;
    for(; jojo->next; jojo = jojo->next)
        continue;
    jojo->next = (struct list*)malloc(sizeof(struct list));
    jojo->next->elmt = (struct process*)malloc(sizeof(struct process));
    jojo->next->elmt->ID = ID;
    jojo->next->elmt->burstTime = burst;
    jojo->next->elmt->totalTime = 0;
    jojo->next->elmt->waitTime = 0;
    jojo->next->elmt->burstDone = 0;
    jojo->next->next = NULL;
    return;
}

void rem(int ID, struct list* head) {
    struct list* jojo = head->next;
    struct list* last = head;
    for(; jojo->next && jojo->elmt->ID != ID; jojo = jojo->next, last = last->next)
        continue;
    if(jojo && jojo->elmt->ID == ID) {
        /* Find to RM */
        free(jojo->elmt);
        last->next = jojo->next;
        free(jojo);
    }
    return;
}

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

    int quantuum = 4;
    
    printf("\n Scheduling \n\n");

    /* Number of process selection */
    printf("Number of processes ? :>");
    scanf("%d", &number);
    printf("\n");

    /* List create */
    struct list* head = malloc(sizeof(struct list));
    head->next = NULL;
    head->elmt = NULL;

    /* Burst time and ID attribution */
    for(i = 0; i < number; i++) {
        scanf("%d", &j);
        add(i + 1, j, head);
    }
    printf("\n");

    /* Number of process selection */
    printf("Quantuum (CPU alloc time) (Need int) ? :>");
    scanf("%d", &quantuum);
    printf("\n");

    /* Gantt Graph Sched */
    printf("Sheduling ! \n\n");
   
    char info[1024];
    int c = 0; // follow info placements incre
    int r = 0;
    printf("Gantt Chart \n\n");
    struct list* p = head->next;
    struct list* parc = head->next;
    /* Scheduling !!! */
    printf("P:|");
    info[c++] = 'T';
    info[c++] = ':';
    info[c++] = '0';
    while(head->next) {
        printf("%d", p->elmt->ID);
        for(i = 0, j = 0, k = 1; p->elmt->burstDone != p->elmt->burstTime && j < quantuum; j++) {
            p->elmt->burstDone++;
            p->elmt->totalTime++;
            i++;
            totalTurnTime++;
            /* Gant Chart Store here process in execution */
            if(k < j) {
                printf(" ");
            }
        }
        printf("|");
        for(k = 0; k < i - r - 1; k++)
            info[c++] = ' ';
        if(totalTurnTime > 10) {
            r = 1;
            info[c++] = (totalTurnTime / 10) + '0';
            info[c++] = (totalTurnTime % 10) + '0';
        }
        else {
            r = 0;
            info[c++] = (totalTurnTime) + '0';
        }
        /* waited time for others is i */
        /* save current ID and add time to all others in j */
        j = p->elmt->ID;
        for(parc = head->next; parc; parc = parc->next) {
            if(parc->elmt->ID != j) {
                parc->elmt->waitTime += i;
                parc->elmt->totalTime += i;
            }
        }
        /* Remove if process done "TERMINATED" */
        if(p->elmt->burstDone >= p->elmt->burstTime) {
            if(p->next)
                p = p->next;
            else
                p = head->next;
            rem(j, head);
        }
        else {
            if(p->next) {
                p = p->next; 
            }
            else {
                p = head->next;
            }
        }
    } 
    info[c++] = '\0';
    printf("\n");
    for(k = 0; info[k] != '\0'; k++)
        printf("%c", info[k]);

    /* All Process done */
    free(head);
    printf("\n\n");

    return 0;
}

