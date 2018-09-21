/*************************************************************************
	> File Name: euler46.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月04日 星期六 17时12分14秒
 ************************************************************************/

//哥德巴赫的另一个猜想

#include <stdio.h>
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

            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {

    init();

    for(int i = 1; i <= prime[0]; i++) {
        for(int n = 1; ; n++) {
            if(prime[i] + 2 * n * n > MAX) break;
            dnum[prime[i] + 2 * n * n] = 1;
        }
    }

    for(int j = 9; j <= MAX; j += 2) {
        if(dnum[j] == 1) continue;
        printf("%d\n", j);
        break;
    }

    return 0;
}
