/*************************************************************************
	> File Name: euler.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月20日 星期五 14时40分35秒
 ************************************************************************/

//3的倍数和5的倍数

#include <stdio.h>

int main() {
    int sum3, sum5,sum15;
    sum3 = (3 + 999) * 333 / 2;
    sum5 = (5 + 995) * 199 / 2;
    sum15 = (15 +(1000 / 15)*15) * (1000 / 15) / 2;
    //等差数列前n和：（a1 + an）* n / 2
    printf("%d\n", sum3 + sum5 - sum15);
    return 0;
}
