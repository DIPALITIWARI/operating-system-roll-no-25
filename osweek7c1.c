#include <stdio.h>
int main() {
    int n, f, pages[30], frames[10], count = 0, flag, faults = 0, i, j;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) frames[i] = -1;
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++)
         if (frames[j] == pages[i]) flag = 1;
        if (!flag) {
            frames[count] = pages[i];
            count = (count + 1) % f;
            faults++;
        }
        printf("\n");
        for (j = 0; j < f; j++) printf("%d ", frames[j]);
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
