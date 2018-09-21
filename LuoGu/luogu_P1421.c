/*************************************************************************
	> File Name: luogu_P1421.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年08月18日 星期六 10时22分28秒
 ************************************************************************/

//小玉买文具

#include <stdio.h>

int main() {

    int a, b;
    int ans = 0;
    scanf("%d %d", &a, &b);
    ans = (a * 10 + b)/19;

    printf("%d\n", ans);
    return 0;
}
