#include <stdio.h>

int main() {
    FILE* fp;
    int a[] = {0,1,2};
    int a_read[3];
    char b[] = "ABC";
    char b_read[4];
    float c[] = {1.1,1.2,1.3};
    float c_read[3];
    fp = fopen("a.bin", "wb+");
    fwrite(a, sizeof(a), 1, fp);
    fwrite(b, sizeof(b), 1, fp);
    fwrite(c, sizeof(c), 1, fp);
    fseek(fp, 0, SEEK_SET);
    fread(a_read, sizeof(a), 1, fp);
    fread(b_read, sizeof(b), 1, fp);
    fread(c_read, sizeof(c), 1, fp);
    for (int i=0; i<3; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int j=0; j<3; j++) {
        printf("%c ", b[j]);
    }
    printf("\n");
    for (int k=0; k<3; k++) {
        printf("%f ", c[k]);
    }
    printf("\n");
    return 0;
}
