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
    char *num1_tmp = calloc(max_len, sizeof(char));
    char *num2_tmp = calloc(max_len, sizeof(char));
    printf("Enter first number : ");
    scanf("%s", num1_tmp);
    printf("Enter second number : ");
    scanf("%s", num2_tmp);
    int len1 = get_length(num1_tmp);
    int len2 = get_length(num2_tmp);
    char *num1 = malloc(len1 * sizeof(char));
    memcpy(num1, num1_tmp, len1 * sizeof(char));
    char *num2 = malloc(len2 * sizeof(char));
    memcpy(num2, num2_tmp, len2 * sizeof(char));
    free(num1_tmp);
    free(num2_tmp);
    char *res = malloc((len1 + len2) * sizeof(char));
    memset(res, 0, (len1 + len2) * sizeof(char));
    int i = len1 - 1, j, count, k, l, m;
    for (m = 0; i >= 0; i--, m++) {
        count = m;
        char i1 = *(num1 + i) - '0';
        for (j = len2 - 1; j >= 0; j--) {
            char i2 = *(num2 + j) - '0';
            char i3 = i1 * i2;
            if (i3 != 0) {
                char *tmp = to_char(i2 * i1);
                for (k = (int) log10(i3), l = 0; k >= 0; k--, l++) {
                    char *next = res + count + l;
                    char *next_plus = res + count + l + 1;
                    if (*next == 0)
                        *next = '0';
                    char i4 = (((*next) - '0') + (*(tmp + k) - '0'));
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
            } else {
                if (*(res + count) == 0) {
                    *(res + count) = '0';
                }
            }
            count++;
        }
    }
    char *final_res = malloc((len1 + len2) * sizeof(char));
    memset(final_res, 0, (len1 + len2) * sizeof(char));
    for (i = (len1 + len2) - 1, j = 0; i >= 0;) {
        char tmp = *(res + i--);
        if (tmp == 0)
            continue;
        *(final_res + j++) = tmp;
    }
    free(num1);
    free(num2);
    free(res);
    char lock = 0;
    printf("result = ");
    for (i = 0;;) {
        char tmp = *(final_res + i++);
        if (tmp > '0')
            lock = 1;
        if (tmp == 0)
            break;
        if (lock)
            printf("%c", tmp);
    }
    printf("\n");
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