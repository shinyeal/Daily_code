/*************************************************************************
	> File Name: luogu_P1035.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年08月18日 星期六 16时41分12秒
 ************************************************************************/

//级数求和

#include <stdio.h>

int main() {

    double sum = 0;
    int k;

    scanf("%d", &k);

    for(int i = 1; ; i++) {

        sum += 1.0 / i;
        if(sum > k) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}

