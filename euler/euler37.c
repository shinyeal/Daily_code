/*************************************************************************
	> File Name: euler37.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 22时56分58秒
 ************************************************************************/

//可截素数

#include <stdio.h>
#include <math.h>
#define MAX 1000000

int is_prime[MAX + 5] = {0};
int prime[MAX + 5] = {0};

int digit(int x) {

    return floor(log10(x)) + 1;
}

int get_num1(int value1) {

    int dig = digit(value1);
    while (dig != 0) {
        if(is_prime[value1]) {
            return 0;
        }
        value1 = value1 % (int)pow(10, --dig);
    }
    return 1;   
}

int get_num2(int value2) {
    
    while(value2) {
        if(is_prime[value2]) {
            return 0;
        }
        value2 /= 10;
    }
    return 1;
}

int main() {
    
    is_prime[1] = 1;
    for(int m = 2; m <= MAX; m++) {
        if(!is_prime[m]) {
            prime[++prime[0]] = m;
        }

        for(int i = 1, p = prime[1]; i <= prime[0]; i++, p = prime[i]) {
            if(p * m > MAX) break;
            is_prime[p * m] = 1;
            if(m % p == 0) break;
        }
    }
    
    int num = 0;

    //for(int i = 1; i <= prime[0]; i++) {
    //    printf("%d ", prime[i]);
    //}
    int sum = 0;

    for(int i = 23; i < MAX; i++) {

        if(get_num1(i) && get_num2(i)) {
            num++;
            printf("%d ", i);
            sum +=i;
        }
    }
     printf("%d\n", num);
        printf("%d\n", sum);


    return 0;
}
