/*
    Author: Aditya Shaha <15BCE0227>
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("/*\n\tAuthor: Aditya Shaha <15BCE0227>\n\n*/\n");
int i,j,processNumber;
//printf("Enter the number of processes \n");
scanf("%d",&processNumber);
//printf("Enter the number of Resources Available \n");

int ResourceMatrix[processNumber];
int AllocationMatrix[processNumber];
int AvailabeResource;
int NeedMatrix[processNumber];
int processComplete[processNumber];

printf("\nThe number of processes are %d and number of resource is %d\n",processNumber,1);
//printf("Enter the Available resources\n");

scanf("%d",&AvailabeResource);

printf("\nThe number of available Resource is %d\n",AvailabeResource);

printf("\n");
//printf("Enter the Allocation Matrix\n");
for(i=0;i<processNumber;i++) {
    scanf("%d",&AllocationMatrix[i]);
}

//printf("Enter the Maximum Matrix\n");
for(i=0;i<processNumber;i++) {
    scanf("%d",&ResourceMatrix[i]);
}

for(i=0;i<processNumber;i++) {
    NeedMatrix[i] = ResourceMatrix[i] - AllocationMatrix[i];
}
printf("The Allocation Matrix is \n");

for(i=0;i<processNumber;i++) {
    printf("%d  ",AllocationMatrix[i]);
}

printf("\n");

printf("The Maximum Resource Matrix is \n");
for(i=0;i<processNumber;i++) {
    printf("%d  ",ResourceMatrix[i]);
}
printf("\n");
printf("The Need Matrix is \n");
for(i=0;i<processNumber;i++) {
        printf("%d  ",NeedMatrix[i]);
}

for(i=0;i<processNumber;i++) {
    processComplete[i]=0;
}
int completeCount=0,unsafe =  0;
int changed = 1;
printf("\n");
while(changed==1 && completeCount<processNumber) {

    for(i=0;i<processNumber;i++) {
        if(processComplete[i]==0 && NeedMatrix[i]<=AvailabeResource) {
            AvailabeResource+=NeedMatrix[i];
            changed = 1;
            processComplete[i]=++completeCount;
        } else {
            changed = 0;
        }

    }

}

if(changed ==0 && completeCount < processNumber) {
    printf("No safe Sequence Exists ! The processes will enter into a deadlock\n");
    return 0;
}

//printf("%d",completeCount);
printf("\nThe Safe Sequence is\n\n");
for(i=0;i<processNumber;i++) {
    printf("\tProcess[%d] - > %d\n",i,processComplete[i]);
}
printf("\n");
return 0;
}
