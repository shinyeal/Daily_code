/*************************************************************************
	> File Name: euler10.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月26日 星期四 10时39分57秒
 ************************************************************************/

//素数的和

#include <stdio.h>
#include <inttypes.h>

#define MAX 2000000

int64_t prime[MAX + 5] = {0};

int main() {

    int64_t sum = 0;

    for(int64_t i = 2; i <= MAX; i++) {

        if(!prime[i]) {    //if条件为0，也就是当他为素数的时候。
            prime[++prime[0]] = i;
            sum += i;
        }

        for(int64_t j = 1; j <= prime[0] && prime[j] * i <= MAX; j++ ) {
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    } 

    printf("%"PRId64"\n", sum);
    return 0;
}
