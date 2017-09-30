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
        int waitingTime; //WT
        int turnAroundTime;//TAT
        int remainingTime;
};

int cmpfunc(const void*a, const void *b){
        struct Process *p1 = (struct Process *)a;
        struct Process *p2 = (struct Process *)b;
        return (p1->arrivalTime - p2->arrivalTime);
}

int main() {

int executionTime = 0;
int sumBurstTime = 0;
int processNumber,i,timeQuantum;

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
};

printf("Enter then time Quantum(TQ)\n");
scanf("%d",&timeQuantum);

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

int maxArrivalTime = 0;
for(i=0;i<processNumber;i++){
    if(ProcessInput[i].arrivalTime > maxArrivalTime){
        maxArrivalTime = ProcessInput[i].arrivalTime;
    }
    sumBurstTime += ProcessInput[i].requireTime;
    ProcessInput[i].remainingTime = ProcessInput[i].requireTime;
};
while(sumBurstTime >0) {


    for(i=0;i<processNumber;i++){
        if(ProcessInput[i].remainingTime>0) {

           if(ProcessInput[i].remainingTime >= timeQuantum) {

                ProcessInput[i].remainingTime-= timeQuantum;

                executionTime+=timeQuantum;
                sumBurstTime-=timeQuantum;
                printf("P%d -> %d -> %d ->%d\n",ProcessInput[i].processName,ProcessInput[i].remainingTime,executionTime,sumBurstTime);
           } else {

                executionTime+=(timeQuantum-ProcessInput[i].remainingTime);
                sumBurstTime-=(timeQuantum-ProcessInput[i].remainingTime);
                ProcessInput[i].remainingTime = 0;

                printf("P%d -> %d -> %d\n",ProcessInput[i].processName,ProcessInput[i].remainingTime,executionTime,sumBurstTime);

           }
           if(ProcessInput[i].remainingTime ==0) {
                ProcessInput[i].completionTime = executionTime;
           }
        }
    };
}


printf("Process Name\tArrival Time\tBurstTime\tCompletionTime\tTurnAround\tWaitTime");
printf("\n");
for(i=0;i<processNumber;i++){

    if(ProcessInput[i].arrivalTime > executionTime) {
        executionTime += (ProcessInput[i].arrivalTime - executionTime);
    }

    ProcessInput[i].turnAroundTime = ProcessInput[i].completionTime - ProcessInput[i].arrivalTime;
    ProcessInput[i].waitingTime = ProcessInput[i].turnAroundTime - ProcessInput[i].requireTime;
    executionTime +=ProcessInput[i].requireTime;
};

for(i=0;i<processNumber;i++){
    printf("P%d\t\t %d\t\t %d\t\t\t %d\t %d\t\t %d\n",ProcessInput[i].processName,ProcessInput[i].arrivalTime,ProcessInput[i].requireTime,ProcessInput[i].completionTime,ProcessInput[i].turnAroundTime,ProcessInput[i].waitingTime);
};
return 0;
}

