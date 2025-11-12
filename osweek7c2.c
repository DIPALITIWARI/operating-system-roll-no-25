#include <stdio.h>
int main() {
    int n, f, pages[30], frames[10], time[10], count = 0, faults = 0, i, j, k, pos, min;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) frames[i] = -1;
    for (i = 0; i < n; i++) {
        int flag = 0;
        for (j = 0; j < f; j++) if (frames[j] == pages[i]) { flag = 1; time[j] = count++; }
        if (!flag) {
            if (i < f) { frames[i] = pages[i]; time[i] = count++; }
            else {
                min = time[0]; pos = 0;
                for (k = 1; k < f; k++) if (time[k] < min) { min = time[k]; pos = k; }
                frames[pos] = pages[i]; time[pos] = count++;
            }
            faults++;
        }
        printf("\n");
        for (j = 0; j < f; j++) printf("%d ", frames[j]);
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}

