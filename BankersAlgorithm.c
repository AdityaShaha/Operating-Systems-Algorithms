/*
    Author: Aditya Shaha <15BCE0227>
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("/*\n\tAuthor: Aditya Shaha <15BCE0227>\n\n*/\n");
int i,j,resourceNumber,processNumber;
//printf("Enter the number of processes \n");
scanf("%d",&processNumber);
//printf("Enter the number of Resources Available \n");
scanf("%d",&resourceNumber);
int ResourceMatrix[processNumber][resourceNumber];
int AllocationMatrix[processNumber][resourceNumber];
int AvailabeResource[resourceNumber];
int NeedMatrix[processNumber][resourceNumber];
int processComplete[processNumber];

printf("\nThe number of processes are %d and number of resources are %d\n",processNumber,resourceNumber);
//printf("Enter the Available resources\n");
for(i=0;i<resourceNumber;i++) {
    scanf("%d",&AvailabeResource[i]);
}
printf("\nThe available Matrix is \n");

for(i=0;i<resourceNumber;i++) {
    printf(" %d ",AvailabeResource[i]);
}
printf("\n");
//printf("Enter the Allocation Matrix\n");
for(i=0;i<processNumber;i++) {
    for(j=0;j<resourceNumber;j++) {
        scanf("%d",&AllocationMatrix[i][j]);
    }
}

//printf("Enter the Maximum Matrix\n");
for(i=0;i<processNumber;i++) {
    for(j=0;j<resourceNumber;j++) {
        scanf("%d",&ResourceMatrix[i][j]);
    }
}

for(i=0;i<processNumber;i++) {
    for(j=0;j<resourceNumber;j++) {
        NeedMatrix[i][j] = ResourceMatrix[i][j] - AllocationMatrix[i][j];
    }
}
printf("The Allocation Matrix is \n");
for(i=0;i<processNumber;i++) {
    for(j=0;j<resourceNumber;j++) {
        printf("%d  ",AllocationMatrix[i][j]);
    }
    printf("\n");
}
printf("\n");
printf("The Maximum Resource Matrix is \n");
for(i=0;i<processNumber;i++) {
    for(j=0;j<resourceNumber;j++) {
        printf("%d  ",ResourceMatrix[i][j]);
    }
    printf("\n");
}
printf("\n");
printf("The Need Matrix is \n");
for(i=0;i<processNumber;i++) {
    for(j=0;j<resourceNumber;j++) {
        printf("%d  ",NeedMatrix[i][j]);
    }
    printf("\n");
}
for(i=0;i<processNumber;i++) {
    processComplete[i]=0;
}
int completeCount=0,unsafe =  0;
int changed = 1;
printf("\n");
while(changed==1 && completeCount<5) {



    for(i=0;i<processNumber;i++) {

        unsafe =0;
        if(processComplete[i]==0) {


            for(j=0;j<resourceNumber;j++) {

                if(NeedMatrix[i][j]>AvailabeResource[j]) {

                    unsafe =1;

                    break;
                }

            }

            if(j == resourceNumber) {

                completeCount++;

                changed = 1;
                printf("The available resource are\n");
                for(j=0;j<resourceNumber;j++) {
                    AvailabeResource[j] += NeedMatrix[i][j];
                    printf("%d ",AvailabeResource[j]);
                }
                processComplete[i] = completeCount;
                printf("\n");

            } else {
                changed = 0;
            }
        }

    }

}

if(changed ==0 && completeCount < processNumber) {
    printf("No safe Sequence Exists ! The processes will enter into a deadlock\n");
    return 0;
}


printf("\nThe Safe Sequence is\n\n");
for(i=0;i<processNumber;i++) {
    printf("\tProcess[%d] - > %d\n",i,processComplete[i]);
}
printf("\n");
return 0;
}
