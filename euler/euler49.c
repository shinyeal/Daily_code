/*************************************************************************
	> File Name: euler49.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 10时23分27秒
 ************************************************************************/

//素数重排

#include<stdio.h>
#define MAX 1000000

int prime[MAX + 5] = {0};

void init() {

    for(int i = 2; i <= MAX; i++) {
        if(!prime[i]) prime[++prime[0]] = i;

        for(int j = 1; j <= prime[0]; j++) {

            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return;
}

int get_num(int m) {

    while(m) {

    }

}

int main() {

    init();

    for(int i = 1000; i <= 9999; i++) {
        for(int j = i + 1; j <= 9999; j++) {
            for(int k = j + 1; k <= 9999; k++) {
                if(get_num(i) && get_num(j) && get_num(k) && prime[k] - prime[j] == prime[j] - prime[i] && 2 * prime[j] == prime[i] + prime[k] && prime[k] >= 1000 && prime[k] <= 9999) {
                    printf("%d %d %d\n", prime[i], prime[j], prime[k]);
                }
            } 
        }
    }
    
    return 0;
}

