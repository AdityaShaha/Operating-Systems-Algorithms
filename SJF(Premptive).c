/*
    Author:Aditya Shaha <15BCE0227>
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50
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
        return (p1->requireTime - p2->requireTime);
}

/*
    Implementing Queue Data Structure for the code
*/

struct Process queue_array[MAX];
int rear = - 1;
int front = - 1;

void EnQueue(struct Process add_item)
{
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} /*End of insert()*/

void deQueue()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        front = front + 1;
    }
} /*End of delete() */

int main() {

int executionTime = 0;
int sumBurstTime = 0;
int elapsedTime = 0;
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

for(i=0;i<processNumber;i++){
    sumBurstTime += ProcessInput[i].requireTime;
    ProcessInput[i].remainingTime = ProcessInput[i].requireTime;
};

for(i=0;i<processNumber;i++){
        printf("Process Name : P%d",ProcessInput[i].processName);
        printf("\n");
        printf("Arrival Time: %d",ProcessInput[i].arrivalTime);
        printf("\n");
        printf("Required Time: %d",ProcessInput[i].requireTime);
        printf("\n");
};

if(ProcessInput[0].arrivalTime/timeQuantum !=0) {
    elapsedTime = ceil(ProcessInput[0].arrivalTime/timeQuantum);
    elapsedTime*=timeQuantum;
}
// Queuing the first Process
EnQueue(ProcessInput[0]);
printf("\n %d \n",queue_array[0].processName);
return 0;
}
