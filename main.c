#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

char *to_char(int num);

int leading_zero(const char *num, int size);

int get_length(const char *num);

int main() {
    unsigned int max_len;
    printf("Enter max number length : ");
    scanf("%u", &max_len);
    char *num1_tmp = calloc(max_len, sizeof(char));
    char *num2_tmp = calloc(max_len, sizeof(char));
    printf("Enter first number : ");
    scanf("%s", num1_tmp);
    printf("Enter second number : ");
    scanf("%s", num2_tmp);
    int len1 = get_length(num1_tmp);
    int lead1 = leading_zero(num1_tmp, len1);
    len1 -= lead1;
    int len2 = get_length(num2_tmp);
    int lead2 = leading_zero(num2_tmp, len2);
    len2 -= lead2;
    char *num1 = malloc(len1 * sizeof(char));
    memcpy(num1, num1_tmp + lead1, len1 * sizeof(char));
    char *num2 = malloc(len2 * sizeof(char));
    memcpy(num2, num2_tmp + lead2, len2 * sizeof(char));
    free(num1_tmp);
    free(num2_tmp);
    char *res = calloc((len1 + len2), sizeof(char));
    int i = len1 - 1, j, count, k, l, m = 0;
    for (; i >= 0;) {
        count = m++;
        char i1 = *(num1 + i--) - '0';
        for (j = len2 - 1; j >= 0;) {
            char i2 = *(num2 + j--) - '0';
            char i3 = i1 * i2;
            if (i3 != 0) {
                char *tmp = to_char(i2 * i1);
                for (k = (int) log10(i3), l = 0; k >= 0;) {
                    char *next = res + count + l++;
                    char *next_plus = next + 1;
                    if (*next == 0)
                        *next = '0';
                    char i4 = (((*next) - '0') + (*(tmp + k--) - '0'));
                    if (i4 >= 10) {
                        *next = (char) ((i4 % 10) + '0');
                        if (*next_plus == 0)
                            *next_plus = '0';
                        *next_plus = (char) ((((*next_plus) - '0') + (i4 / 10)) + '0');
                    } else {
                        *next = (char) (i4 + '0');
                    }
                }
            } else {
                if (*(res + count) == 0) {
                    *(res + count) = '0';
                }
            }
            count++;
        }
    }
    free(num1);
    free(num2);
    printf("result = ");
    for (i = (len1 + len2) - 1, j = 0; i >= 0;) {
        char tmp = *(res + i--);
        if (tmp == 0)
            continue;
        printf("%c", tmp);
    }
    printf("\n");
}

int leading_zero(const char *num, int size) {
    int i = 0, result = 0;
    for (; i < size;) {
        if (*(num + i++) != '0')
            break;
        result++;
    }
    return result;
}

char *to_char(int num) {
    int len = (int) log10((double) num);
    char *tmp = malloc(len * sizeof(char));
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