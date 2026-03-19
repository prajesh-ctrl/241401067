#include <stdio.h>
#include <stdbool.h>

#define MAX_P 10
#define MAX_R 10

void calculateNeed(int need[MAX_P][MAX_R], int max[MAX_P][MAX_R], int alloc[MAX_P][MAX_R], int n, int r) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

bool checkSafety(int n, int r, int alloc[MAX_P][MAX_R], int need[MAX_P][MAX_R], int avail[MAX_R], int seq[]) {
    int work[MAX_R];
    bool finish[MAX_P] = {false};
    int count = 0;

    for (int i = 0; i < r; i++) work[i] = avail[i];

    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < r; j++) {
                    if (need[p][j] > work[j]) break;
                }

                if (j == r) {
                    for (int k = 0; k < r; k++) 
                        work[k] += alloc[p][k];
                    seq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    int n, r;
    int alloc[MAX_P][MAX_R], max[MAX_P][MAX_R], need[MAX_P][MAX_R], avail[MAX_R];
    int safe_sequence[MAX_P];

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &r);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++) scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++) scanf("%d", &max[i][j]);

    printf("Enter Available Resources: ");
    for (int i = 0; i < r; i++) scanf("%d", &avail[i]);

    calculateNeed(need, max, alloc, n, r);

    if (checkSafety(n, r, alloc, need, avail, safe_sequence)) {
        printf("\nSafe sequence is: ");
        for (int i = 0; i < n; i++) {
            printf("P%d ", safe_sequence[i]);
        }
        printf("\n");
    } else {
        printf("\nSystem is in unsafe state! May occur the deadlock\n");
    }

    return 0;
}
