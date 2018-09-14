/*************************************************************************
	> File Name: digit_test.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月14日 星期五 15时27分30秒
 ************************************************************************/

//计算一个数字的位数

#include <stdio.h>
#include <math.h>

int main() {
    int n;

    while(scanf("%d", &n) != EOF) {
        printf("%d\n", (int)floor(log10(n)) + 1);
        printf(" has %d digit\n", printf("%d", n));
    }
    return 0;
}
