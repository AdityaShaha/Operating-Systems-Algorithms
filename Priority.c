/*
    Author:Aditya Shaha <15BCE0227>
*/
#include <stdio.h>
#include <stdlib.h>
struct Process {
        int arrivalTime; //AT
        int processName; // Process Name
        int requireTime; // Burst Time
        int completionTime; // CT
        int priority;
        int waitingTime; //WT
        int turnAroundTime;//TAT
};

int cmpfunc(const void*a, const void *b){
        struct Process *p1 = (struct Process *)a;
        struct Process *p2 = (struct Process *)b;
        if(p1->priority == p2->priority) {
            return (p1->arrivalTime - p2->arrivalTime);
        }
        return (p1->priority - p2->priority);
}

int main() {

int executionTime = 0;
int processNumber,i;

printf("/*\n\tAuthor:Aditya Shaha <15BCE0227>\n*/\n\n\n");

printf("Enter then number of processes\n");
scanf("%d",&processNumber);

struct Process ProcessInput[processNumber];

for(i=0;i<processNumber;i++) {
        printf("Enter the name of the process\n");
        scanf("%d",&ProcessInput[i].processName);
        printf("Enter the arrival time of process\n",i);
        scanf("%d",&ProcessInput[i].arrivalTime);
        printf("Enter the time required to finish the process\n");
        scanf("%d",&ProcessInput[i].requireTime);
        printf("Enter the priority of the process\n");
        scanf("%d",&ProcessInput[i].priority);
};

for(i=0;i<processNumber;i++){
        printf("Process Name : P%d",ProcessInput[i].processName);
        printf("\n");
        printf("Arrival Time: %d",ProcessInput[i].arrivalTime);
        printf("\n");
        printf("Required Time: %d",ProcessInput[i].requireTime);
        printf("\n");
};

qsort(ProcessInput,processNumber,sizeof(struct Process),cmpfunc);

printf("\n");
printf("\n");
printf("\n");

printf("Process Name\tArrival Time\tBurstTime\tPriority\tCompletionTime\tTurnAround\tWaitTime");
printf("\n");
for(i=0;i<processNumber;i++){

    if(ProcessInput[i].arrivalTime > executionTime) {
        executionTime += (ProcessInput[i].arrivalTime - executionTime);
    }

    ProcessInput[i].completionTime = ProcessInput[i].requireTime + executionTime;
    ProcessInput[i].turnAroundTime = ProcessInput[i].completionTime - ProcessInput[i].arrivalTime;
    ProcessInput[i].waitingTime = ProcessInput[i].turnAroundTime - ProcessInput[i].requireTime;
    executionTime +=ProcessInput[i].requireTime;
};

for(i=0;i<processNumber;i++){
    printf("P%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t %d\t\t %d\n",ProcessInput[i].processName,ProcessInput[i].arrivalTime,ProcessInput[i].requireTime,ProcessInput[i].priority,ProcessInput[i].completionTime,ProcessInput[i].turnAroundTime,ProcessInput[i].waitingTime);
};
return 0;
}

