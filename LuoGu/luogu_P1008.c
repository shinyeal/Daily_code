/*************************************************************************
	> File Name: luogu_P1008.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年08月18日 星期六 15时49分05秒
 ************************************************************************/

//三连击

#include <stdio.h>

int diff_num(int n, int *dnum) {

    while(n) {
        int m;
        m = n % 10;
        if(dnum[m] == 0) return 0;
        dnum[m] = 0;
        n /= 10;
    }
    return 1;
}

int value(int a, int b, int c) {

    int dnum[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    if(!diff_num(a, dnum)) return 0;
    if(!diff_num(b, dnum)) return 0;
    if(!diff_num(c, dnum)) return 0;

    return 1;
}

int main() {

    for(int i = 123; i * 3 <= 987; i++) {

        if(value(i, i * 2, i * 3)) {
            printf("%d %d %d\n", i, i * 2, i * 3);
        }
    }

    return 0;
}

