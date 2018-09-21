/*************************************************************************
	> File Name: luogu_P1425.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年08月18日 星期六 10时34分44秒
 ************************************************************************/

//小鱼的游泳时间

#include <stdio.h>

int main() {

    int a, b, c, d;
    int x = 0;
    int y = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(d >= b) {
        x = c - a;
        y = d - b;
    }else {
        x = c - 1 - a;
        y = d + 60 - b;
    }

    printf("%d %d", x, y);
    return 0;
}

