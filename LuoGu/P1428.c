/*************************************************************************
	> File Name: P1428.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月11日 星期二 09时47分35秒
 ************************************************************************/

//小鱼比可爱

#include <stdio.h>
#include <limits.h>

int main() {

    int n;
    int count[105] = {0};
    int num[105];
    num[0] = INT_MAX;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        for(int j = 0; j <= i; j++) {
            if(num[i] > num[j]) {
                count[i]++;
            }
        }
        printf("%d ", count[i]);
    }
    return 0;
}

