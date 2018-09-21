/*************************************************************************
	> File Name: P1046.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月10日 星期一 09时38分37秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int a[10];
    int n;
    int count = 0;

    for(int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    int tall = n + 30;
    for(int j = 0; j < 10; j++) {
        if(tall >= a[j]) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
