/*************************************************************************
	> File Name: euler13.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 00时00分42秒
 ************************************************************************/

//大数相加

#include<stdio.h>
#include <string.h>

char num[55];
int ans[55] = {1, 0};  //ans这个大整数中存入的数字只有一位，这个数字就是0

int main() {

    for(int i = 0; i < 100; i++) {
        scanf("%s", num);
        int len = strlen(num);  //num的长度
        if(ans[0] < len)  ans[0] = len;
        for(int j = 0; j < len; j++) {
            ans[len - j] += (num[j] - '0');  //倒着存
        }

        for(int j = 1;j <= ans[0]; j++) {
            if(ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }

    for(int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
