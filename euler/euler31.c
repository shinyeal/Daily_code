/*************************************************************************
	> File Name: euler31.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 11时28分15秒
 ************************************************************************/

//硬币求和

#include <stdio.h>     //降维后的方法
#define MAX_W 8
#define MAX_N 201

int w[MAX_W] = {1, 2, 5, 10, 20, 50, 100, 200};
int dp[MAX_N] = {0};

int main() {

    dp[0] = 1;  //不用再判断dp[n][0] = 1
    for(int i = 0; i < 8; i++) {
        for(int j = w[i]; j < MAX_N; j++) {  //j = w[i] ,保证合法性
            dp[j] += dp[j - w[i]];
        }
    }
    printf("%d\n", dp[MAX_N - 1]);
    return 0;
}
