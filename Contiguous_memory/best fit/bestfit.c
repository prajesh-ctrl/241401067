#include <stdio.h>

int main() {
    int m,n;

    printf("Enter number of memory blocks:\n");
    scanf("%d",&m);

    int blockSize[m],remaining[m];

    printf("Enter size of each block:\n");
    for (int i=0;i<m;i++) {
        scanf("%d",&blockSize[i]);
        remaining[i] = blockSize[i];
    }

    printf("Enter number of processes:\n");
    scanf("%d",&n);

    int processSize[n];

    printf("Enter size of each process:\n");
    for (int i=0;i<n;i++) {
        scanf("%d",&processSize[i]);
    }

    for (int i=0;i<n;i++) {
        int bestIndex = -1;

        for (int j=0;j<m;j++) {
            if (remaining[j] >= processSize[i]) {

                if (bestIndex == -1 || remaining[j] < remaining[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            int frag = remaining[bestIndex] - processSize[i];

            printf("Process %d of size %d is allocated to Block %d of size %d with fragement %d\n",
                   i+1, processSize[i], bestIndex+1, blockSize[bestIndex], frag);

            remaining[bestIndex] -= processSize[i];
        }
        else {
            printf("Process %d of size %d is not allocated\n",
                   i+1, processSize[i]);
        }
    }

    return 0;
}
