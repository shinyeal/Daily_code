/*************************************************************************
	> File Name: luogu_P1423.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年08月18日 星期六 17时02分43秒
 ************************************************************************/

//小玉在游泳

#include <stdio.h>

int main() {

    int step = 1;
    double m;
    double sum = 0;
    scanf("%lf", &m);

    for(double i = 2.0; ;i *= 98.0 / 100) {
        sum += i;
        if(sum < m)
            step++;
        else
            break;
    }

    printf("%d\n", step);
    return 0;
}

