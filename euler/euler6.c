/*************************************************************************
	> File Name: euler6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 10时02分33秒
 ************************************************************************/

//平方的和与和的平方之差

#include<stdio.h>
int main () {

int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= 100; i++) {
        sum1 += i;
        sum2 += i * i;
    }
    printf("%d\n", sum1 * sum1 - sum2);

    return 0;
}


//优化：euler6-1.c : 用立方n3推导出带有n2的公式。


