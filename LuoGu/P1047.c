/*************************************************************************
	> File Name: P1047.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月10日 星期一 10时01分42秒
 ************************************************************************/

//校门外的树

#include <stdio.h>
int main() {
    int total, n;
    int begin, end;
    int flag[10005] = {0};
    scanf("%d %d", &total, &n);
    //for(int i = 0; i <= total; i++) {
    //    flag[i] = 0;
    //}

    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &begin, &end);
        for(int j = begin; j <= end; j++) {
            if(flag[j] == 0) {
                flag[j] = 1;
            }
        }
    }

    int count = 0;
    for(int i = 0; i <= total; i++) {
        if(flag[i] == 0) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}

