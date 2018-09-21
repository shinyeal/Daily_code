/*************************************************************************
	> File Name: euler34.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 09时18分32秒
 ************************************************************************/

//各位数字的阶乘

#include<stdio.h>

#define MAX_N 254160

int main() {
    int num[15] = {1,1};
    for(int i = 2;i < 10; i++) {
        num[i] = num[i - 1] * i;
    }
    int ans = 0;
    for(int i = 3; i < MAX_N; i++) {
        int temp = i;
        int sum = 0;
        while(temp) {
            sum += num[temp % 10];
            temp /= 10;
        }
        if(sum == i) {
            ans += sum;
        }
    }
    printf("%d\n",ans);

    return 0;
}
