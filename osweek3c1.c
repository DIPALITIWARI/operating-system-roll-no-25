#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[100], bt[100], ct[100], tat[100], wt[100];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival and burst time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t < at[i]) t = at[i];
        ct[i] = t + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        t = ct[i];
    }
    printf("\nFCFS Scheduling\nP\tAT\tBT\tWT\tTAT\n");
    double sw = 0, st = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
        sw += wt[i]; st += tat[i];
    }
    printf("Average WT=%.2f\nAverage TAT=%.2f\n", sw / n, st / n);
    return 0;
}
