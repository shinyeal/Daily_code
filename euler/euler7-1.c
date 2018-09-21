/*************************************************************************
	> File Name: euler7-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 16时39分51秒
 ************************************************************************/

//第10001个素数
//线性筛

#include <stdio.h>
#define MAX_N 150000

int prime[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {         //i 代表 m
            prime[++prime[0]] = i;                                      
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;                    
                    
        }
            
    }
    printf("%d\n",prime[10001]);
    return 0;
}

