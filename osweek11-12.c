#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, temp, head = 50, total;
    printf("Enter number of disk requests : ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the disk requests : ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);

    // FCFS
    total = 0;
    for (i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
    }
    printf("Total seek movement (FCFS) : %d\n", total);

    // SCAN
    head = 50;
    int r[n + 1], pos;
    for (i = 0; i < n; i++) r[i] = req[i];
    r[n] = head;
    n++;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (r[i] > r[j]) { temp = r[i]; r[i] = r[j]; r[j] = temp; }
    for (i = 0; i < n; i++) if (r[i] == head) { pos = i; break; }

    total = 0;
    for (i = pos; i < n - 1; i++) total += abs(r[i + 1] - r[i]);
    total += abs(199 - r[n - 1]);
    total += abs(199 - r[pos - 1]);
    for (i = pos - 1; i > 0; i--) total += abs(r[i] - r[i - 1]);
    printf("Total seek movement (SCAN) : %d\n", total);

    // C-SCAN
    head = 50;
    for (i = 0; i < n; i++) r[i] = req[i];
    r[n - 1] = head;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (r[i] > r[j]) { temp = r[i]; r[i] = r[j]; r[j] = temp; }
    for (i = 0; i < n; i++) if (r[i] == head) { pos = i; break; }

    total = 0;
    for (i = pos; i < n - 1; i++) total += abs(r[i + 1] - r[i]);
    total += abs(199 - r[n - 1]);
    total += 199;
    for (i = 0; i < pos - 1; i++) total += abs(r[i + 1] - r[i]);
    printf("Total seek movement (C-SCAN) : %d\n", total);

    return 0;
}
