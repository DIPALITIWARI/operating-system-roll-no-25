#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[100], bt[100], rt[100], ct[100], wt[100], tat[100];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival and burst time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    int t = 0, completed = 0;
    while (completed < n) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0) {
                done = 0;
                if (rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    rt[i] = 0;
                    ct[i] = t;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    completed++;
                }
            }
        }
        if (done) t++;
    }
    printf("\nRound Robin Scheduling\nP\tAT\tBT\tWT\tTAT\n");
    double sw = 0, st = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
        sw += wt[i]; st += tat[i];
    }
    printf("Average WT=%.2f\nAverage TAT=%.2f\n", sw / n, st / n);
    return 0;
}
