/*************************************************************************
	> File Name: sqrt.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月13日 星期四 20时03分57秒
 ************************************************************************/

//用牛顿迭代法求解平方根

#include <stdio.h>
#include <math.h>
#include <time.h>

#define TEST_TIME(func) ({ \
    int begin = clock(); \ 
    double ret = func; \
    int end = clock(); \
    printf("%lfms\n", (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000); \
    ret; \
})

double _sqrt1(double x) {
    double head = -100, tail = 100, mid;
    #define EPS 1e-7
    while(tail - head > EPS) {
        mid = (head + tail) / 2.0;
        if(mid * mid < x) head = mid;
        else tail = mid;
    }
    return head;
}

double f1(double x, double n) {
    return x * x - n;
}

double f1_prime(double x) {
    return 2 * x;
}

double newton(double n, double (*f)(double, double), double(*f_prime)(double)) {
    double x= 1.0;
    #define EPS 1e-7
    while(fabs(f(x, n)) > EPS) {
        x -= f(x, n) / f_prime(x);
    }
    return x;
}

int main() {
    double x;
    while(scanf("%lf", &x) != EOF) {
        printf("%lf\n", TEST_TIME(_sqrt1(x)));
        printf("%lf\n", TEST_TIME(newton(x, f1, f1_prime)));
    }
    return 0;
}
