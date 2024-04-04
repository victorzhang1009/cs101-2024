#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generate_lotto_numbers(int n) {
    FILE *fp;
    fp = fopen("lotto.txt", "w");
    srand(1);
    printf("========= lotto649 =========\n");
    fprintf(fp, "========= lotto649 =========\n");
    for (int i = 1; i <= n; ++i) {
        printf("[%d]: ", i);
        fprintf(fp, "[%d]: ", i);
        int lotto[7];
        for (int j = 0; j < 7; ++j) {
            lotto[j] = rand() % 69 + 1;
            for (int k = 0; k < j; ++k) {
                if (lotto[j] == lotto[k]) {
                    --j;
                    break;
                }
            }
        }
        for (int j = 0; j < 7; ++j) {
            printf("%02d", lotto[j]);
            fprintf(fp, "%02d", lotto[j]);
            if (j != 6) {
                printf(" ");
                fprintf(fp, " ");
            }
        }
        printf("\n");
        fprintf(fp, "\n");
    }
    // 補充未使用的行數
    for (int i = n + 1; i <= 5; ++i) {
        printf("[%d]: __ __ __ __ __ __ __\n", i);
        fprintf(fp, "[%d]: __ __ __ __ __ __ __\n", i);
    }
    printf("========= csie@CGU =========\n");
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);
}
int main() {
    int num_tickets;
    scanf("%d", &num_tickets);
    if (num_tickets < 1 || num_tickets > 5) {
        return 1;
    }
    generate_lotto_numbers(num_tickets);
    return 0;
}
