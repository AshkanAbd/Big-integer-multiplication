#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

char *to_char(int num);

int main() {
    char num1[100];
    memset(&num1, 0, 100 * sizeof(char));
    char num2[100];
    memset(&num2, 0, 100 * sizeof(char));
    char *res = (char *) malloc(100 * 100 * sizeof(char));
    memset(res, 0, 100 * 100 * sizeof(char));
    scanf("%s", &num1);
    scanf("%s", &num2);
    int i = 99, j, count, k, l, m;
    for (m = 0; i >= 0; i--, m++) {
        char c1 = *(num1 + i);
        if (c1 == 0)
            continue;
        count = m;
        int i1 = c1 - '0';
        for (j = 99; j >= 0; j--) {
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
                }
            }
            count++;
        }
    }
    printf("result = ");
    for (i = 100 * 100; i >= 0; i--) {
        if (*(res + i) == 0)
            continue;
        printf("%c", *(res + i));
    }
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