#include <stdio.h>
#include <string.h>

int main() {
    FILE *f1 = fopen("dipali_tiwari.txt", "w");
    FILE *f2 = fopen("friend_dipali_tiwari.txt", "w");
    char s1[100], s2[100];
    fprintf(f1, "Dipali Tiwari\nCSE\nA2\n");
    fprintf(f2, "Dipali Tiwari\nCSE\nA3\n");
    fclose(f1);
    fclose(f2);
    f1 = fopen("dipali_tiwari.txt", "r");
    f2 = fopen("friend_dipali_tiwari.txt", "r");
    while (fgets(s1, sizeof(s1), f1) && fgets(s2, sizeof(s2), f2))
        if (strcmp(s1, s2) == 0) printf("%s", s1);
    fclose(f1);
    fclose(f2);
    return 0;
}
