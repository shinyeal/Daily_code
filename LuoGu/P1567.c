/*************************************************************************
	> File Name: P1567.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月11日 星期二 11时38分34秒
 ************************************************************************/

//统计天数

#include <stdio.h>
#include <inttypes.h>

int main() {

    int n;
    int max = 0;
    int count = 1;
    int temp[1000001];

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &temp[i]);
    }

    for(int j = 1; j <= n; j++) {
        if(temp[j + 1] > temp[j]) {
            count++;
        } else {
            if(max <= count) {
                max = count;
                //count = 1;
            }
            count = 1;
        }
    }
    printf("%d\n", max);
    return 0;
}

