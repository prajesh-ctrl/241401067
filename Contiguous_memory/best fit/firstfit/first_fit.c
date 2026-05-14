#include <stdio.h>

int main(){
    int m,n;

    printf("Enter number of memory blocks:\n");
    scanf("%d",&m);

    int blockSize[m],remainingSize[m];

    printf("Enter size of each block:\n");
    for (int i=0;i<m;i++){
        scanf("%d",&blockSize[i]);
        remainingSize[i] = blockSize[i];
    }

    printf("Enter number of processes:\n");
    scanf("%d",&n);

    int processSize[n];

    printf("Enter size of each process:\n");
    for (int i=0;i<n;i++){
        scanf("%d",&processSize[i]);
    }

    for (int i=0;i<n;i++){
        int allocated = 0;

        for (int j=0;j<m;j++){
            if (remainingSize[j] >= processSize[i]){
                
                int fragment = remainingSize[j]-processSize[i];

                printf("Process %d of size %d is allocated to Block %d of size %d with fragment %d\n",
                       i+1,processSize[i],j+1,blockSize[j],fragment);

                remainingSize[j] -= processSize[i];
                allocated = 1;

                break;
            }
        }

        if (!allocated){
            printf("Process %d of size %d is not allocated\n",
                   i+1,processSize[i]);
        }
    }

    return 0;
}
