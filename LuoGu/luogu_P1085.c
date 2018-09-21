/*************************************************************************
	> File Name: luogu_P1085.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年08月18日 星期六 10时54分47秒
 ************************************************************************/

//不高兴的津津

#include <stdio.h>

int main() {
    
    int a, b;
    int flag = 0;
    int max = 0;

    for(int i = 1;i <= 7; i++) {
        scanf("%d%d", &a ,&b);

        int ans = a + b;
        if(ans > 8 && ans > max) {
            max = ans;
            flag = i;
        }
    }
    if(flag == 0)
        printf("0");
    else
        printf("%d", flag);
    return 0;
}

