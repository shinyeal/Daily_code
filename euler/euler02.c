/*************************************************************************
	> File Name: euler02.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月20日 星期五 15时21分44秒
 ************************************************************************/

//偶斐波那契数

#include <stdio.h>

int main() {
    int a = 0, b = 1, temp;
    int sum;
    while(a + b <= 4000000) {
        temp = a + b;
        a = b;
        b = temp;
        if(b & 1)     //判断b为奇数时
            continue;
        sum += b; 
    }

    printf("%d\n",sum);
    return 0;
}
