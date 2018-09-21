/*************************************************************************
	> File Name: euler47.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月04日 星期六 16时57分09秒
 ************************************************************************/

//不同的质因数

#include<stdio.h>
#define MAX 1000000

int prime[MAX + 5] = {0};
int dnum[MAX + 5] = {0};

void init() {

    for(int i = 2; i <= MAX; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 1;
        }

        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > MAX)  break;
            prime[i * prime[j]] = 1;
            dnum[i *prime[j]] = dnum[i] + (i % prime[j] != 0);
            if(i % prime[j] == 0) break;
        }
    }
    return;
}
int main() {
    init();
    //int n;
    //while(~scanf("%d", &n)) {
    //printf("%d\n", dnum[n]);
    //}
    for(int i = 1; i < MAX - 3; i++) {
        if(dnum[i] == 4 && dnum[i + 1] == 4 && dnum[i + 2] == 4 && dnum[i + 3] == 4) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
