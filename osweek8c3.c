#include <stdio.h>

int main() {
    int b, p, i, j;
    scanf("%d", &b);
    int block[b];
    for(i=0;i<b;i++)
        scanf("%d", &block[i]);
    scanf("%d", &p);
    int process[p];
    for(i=0;i<p;i++)
        scanf("%d", &process[i]);

    int allocated[p];
    for(i=0;i<p;i++)
        allocated[i] = -1;

    for(i=0;i<p;i++) {
        int best = -1;
        for(j=0;j<b;j++) {
            if(block[j] >= process[i]) {
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }
        if(best != -1) {
            allocated[i] = best;
            block[best] -= process[i];
        }
    }

    for(i=0;i<p;i++) {
        if(allocated[i] != -1)
            printf("%d - %d\n", process[i], allocated[i]+1);
        else
            printf("%d - no free block available\n", process[i]);
    }

    return 0;
}
