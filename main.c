#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

char *to_char(int num);

int get_length(const char *num);

int main() {
    unsigned int max_len;
    printf("Enter max number length : ");
    scanf("%u", &max_len);
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
    int len1 = get_length(num1);
    int len2 = get_length(num2);
    int i = len1 - 1, j, count, k, l, m;
    for (m = 0; i >= 0; i--, m++) {
        count = m;
        int i1 = *(num1 + i) - '0';
        for (j = len2 - 1; j >= 0; j--) {
            int i2 = *(num2 + j) - '0';
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
    for (i = len1 * len2; i >= 0; i--) {
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

int get_length(const char *num) {
    int i = 0;
    while (1) {
        if (*(num + i++) == 0) break;
    }
    return i - 1;
}