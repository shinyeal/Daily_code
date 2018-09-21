/*************************************************************************
	> File Name: euler12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 10时21分26秒
 ************************************************************************/

//高度可约的三角形数

#include <stdio.h>   
#define MAX_N 100000

int dnum[MAX_N + 5] = {0};   //num这个数字的因子的数量
int mnum[MAX_N + 5] = {0};   //相关素数中最小素因子的幂次
int prime[MAX_N + 5] = {0};

void init() {

    for(int i = 2; i * 2 <= MAX_N; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }

        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > MAX_N)  break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {

                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[i * prime[j]] = 1;  //素因子的幂次是1
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }

    return ;
}

int factor_nums(int n) {
    
    if(n & 1) {
        return dnum[n] * dnum[(n + 1) / 2];
    }else {
        return dnum[n / 2] * dnum[n + 1];
    }
}

int main() {  
    init();
    int n = 1;
    while(factor_nums(n) < 500) ++n;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}

