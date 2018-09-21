/*************************************************************************
	> File Name: euler21.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时24分49秒
 ************************************************************************/

//亲和数

#include <stdio.h>
#include <math.h>
#define MAX 10000

int prime[MAX + 5] = {0};
int dnum[MAX + 5] = {0};  //因子和
int mnum[MAX + 5] = {0};  //最小素数的幂次

void init() {

    for(int i = 2; i < MAX; i++){
        if(!prime[i]) {
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = i + 1;       
        }

        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                dnum[i * prime[j]] = dnum[i] * (1 - (int)pow(prime[j], mnum[i] + 2)) / (1 - (int)pow(prime[j], mnum[i] + 1));
                mnum[i * prime[j]] = mnum[i] + 1;
                break;

            } else {
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
                mnum[i * prime[j]] = 1;  
            }
                    
        }
    }
    return;
}

int main() {
    
    init();
    printf("%d\n", dnum[9]);
    int ans = 0;

    for(int i = 1; i < MAX; i++) {
        for(int j = i + 1; j < MAX; j++) {
            if(dnum[i] - i == j && dnum[j] - j == i)
                ans += i + j;                
        }
    }

    printf("%d\n", ans);
        
    return 0;

}


