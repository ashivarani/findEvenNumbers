#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int f[10] = {0};

    for (int i = 0; i < digitsSize; i++) {
        f[digits[i]]++;
    }
    int* res = (int*)malloc(450 * sizeof(int));
    if (!res) return NULL;
    *returnSize = 0;

    for (int num = 100; num <= 998; num += 2) {
        int h = num / 100;
        int t = (num / 10) % 10;
        int u = num % 10;

        int c[10] = {0};
        c[h]++;
        c[t]++;
        c[u]++;
        int val = 1;
        for (int d = 0; d < 10; d++) {
            if (c[d] > f[d]) {
                val = 0;
                break;
            }
        }
        if (val) {
            res[*returnSize] = num;
            (*returnSize)++;
        }
    }
    int* tmp = realloc(res, (*returnSize) * sizeof(int));
    if (tmp) res = tmp;
    return res;
}

int main() {
    int digits[] = {2, 1, 3, 0};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize = 0;

    int* result = findEvenNumbers(digits, digitsSize, &returnSize);

    printf("Valid 3-digit even numbers:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
