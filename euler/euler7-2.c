/*************************************************************************
	> File Name: euler7-2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 10时27分36秒
 ************************************************************************/

//第10001个素数
//线性筛 使用两个数组（素数数组 和 标记数组）

#include <stdio.h>        //线性筛，枚举M，找合数
#define MAX_N 150000

int is_prime[MAX_N + 5] = {0};       //每个数到底是素数还是合数。
int prime[MAX_N + 5] = {0};         //用来存放第i个素数

int main() {
    for(int m= 2; m <= MAX_N; m++ ) {
        if(!is_prime[m]) {        //把素数m放到素数表
            prime[++prime[0]] = m;   
        }

    for(int i = 1, p = prime[1]; i <= prime[0]; i++, p = prime[i]) {
        if(p * m > MAX_N)  break;
        is_prime[p * m] = 1;     // 不大于就标记了
        if(m % p == 0)  break;   //p是m的倍数的时候就到头了
    }
}
    printf("%d",prime[10001]);
    //for(int i = 1; i <= prime[0]; i++) {
    //    printf("%d ", prime[i]);
    //}       //打印所有素数
    printf("\n");

    //int n;
    //while(scanf("%d", &n) != EOF) {
    //    printf("%d is prime = %d\n", n, is_prime[n]);
    //}
    return 0;
}
