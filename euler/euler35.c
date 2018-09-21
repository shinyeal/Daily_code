/*************************************************************************
	> File Name: euler35.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 17时00分44秒
 ************************************************************************/

//圆周素数

#include<stdio.h>
#include <math.h>
#include <inttypes.h>
#define MAX 1000000

//#define DUG

#ifdef DUG
#define dugprint(a, b) printf(a, b);
#else 
#define dugprint(a, b) 
#endif

int64_t is_prime[MAX + 5] = {0};
int64_t prime[MAX + 5] = {0};

int digit(int x) {          
    //dugprint("%d %d\n", x, floor(log10(x)) + 1);
    return floor(log10(x)) + 1;
}

int get_num(int value) {
    int dig = digit(value);
    for(int i = 0; i < dig; i++) {
        //dugprint("%d ", value);
        if(is_prime[value]) {
            //printf("\n");
            return 0;
        }
        value = value % (int)pow(10, dig - 1) * 10 + value / (int)pow(10, dig - 1);
    }
    //printf("\n");
    return 1;
}

int main() {
    for(int m = 2;m <= MAX; m++) {
        if(!is_prime[m]) {
            prime[++prime[0]] = m;
        }
        for(int i = 1, p = prime[1]; i <= prime[0]; i++, p = prime[i]) {
            if(p * m > MAX) break;
            is_prime[p * m] = 1;
            if(m % p == 0) break;
        }
    }
    int64_t num = 0;

   // for(int i = 1; i <= 100; i++) {
   //     printf("%d   %"PRId64"\n ", i, is_prime[i]);
   // }
    for(int i = 2;i < MAX; i++) {
        if(!get_num(i))  continue;
        num++;
        //printf("%"PRId64"\n", i);
    }
    printf("%"PRId64"\n", num);
    return 0;
}
