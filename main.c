#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <strings.h>

char *to_char(int num);

int main() {
    int max_len;
    printf("Enter max number length : ");
    scanf("%d", &max_len);
    char num1[max_len];
    memset(&num1, 0, max_len * sizeof(char));
    char num2[max_len];
    memset(&num2, 0, max_len * sizeof(char));
    char *res = (char *) malloc(max_len * max_len * sizeof(char));
    memset(res, 0, max_len * max_len * sizeof(char));
    printf("Enter first number : ");
    scanf("%s", &num1);
    printf("Enter second number : ");
    scanf("%s", &num2);
    int i = max_len - 1, j, count, k, l, m;
    for (m = 0; i >= 0; i--, m++) {
        char c1 = *(num1 + i);
        if (c1 == 0)
            continue;
        count = m;
        int i1 = c1 - '0';
        for (j = max_len - 1; j >= 0; j--) {
            char c2 = *(num2 + j);
            if (c2 == 0)
                continue;
            int i2 = c2 - '0';
            int i3 = i1 * i2;
            if (i3 != 0) {
                char *tmp = to_char(i2 * i1);
                for (k = (int) log10(i3), l = 0; k >= 0; k--, l++) {
                    char *next = res + count + l;
                    char *next_plus = res + count + l + 1;
                    if (*next == 0)
                        *next = '0';
                    int i4 = (((*next) - '0') + (*(tmp + k) - '0'));
                    if (i4 >= 10) {
                        *next = (char) ((i4 % 10) + '0');
                        if (*next_plus == 0)
                            *next_plus = '0';
                        *next_plus = (char) ((((*next_plus) - '0') + (i4 / 10)) + '0');
                    } else {
                        *next = (char) (i4 + '0');
                    }
                    int mn = 0;
                }
            }
            count++;
        }
    }
    printf("result = ");
    for (i = max_len * max_len; i >= 0; i--) {
        if (*(res + i) == 0)
            continue;
        printf("%c", *(res + i));
    }
    printf("\n");
}

char *to_char(int num) {
    int len = (int) log10((double) num);
    char *tmp = (char *) malloc(len * sizeof(char));
    int i = len, j = 0;
    for (; i >= 0; i--, j++) {
        *(tmp + j) = (char) ((num / (int) pow(10, i)) + '0');
        num = num % (int) pow(10, i);
    }
    return tmp;
}