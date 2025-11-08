#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[100], bt[100], pr[100], ct[100], tat[100], wt[100], done[100] = {0};
    for (int i = 0; i < n; i++) {
        printf("Enter arrival, burst, priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }
    int rem = n, t = 0;
    while (rem) {
        int idx = -1, maxp = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= t && pr[i] > maxp) {
                maxp = pr[i];
                idx = i;
            }
        }
        if (idx == -1) {
            t++;
            continue;
        }
        ct[idx] = t + bt[idx];
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        t = ct[idx];
        done[idx] = 1;
        rem--;
    }
    printf("\nPriority Scheduling\nP\tAT\tBT\tPR\tWT\tTAT\n");
    double sw = 0, st = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);
        sw += wt[i]; st += tat[i];
    }
    printf("Average WT=%.2f\nAverage TAT=%.2f\n", sw / n, st / n);
    return 0;
}
