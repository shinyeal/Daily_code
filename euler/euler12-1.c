/*************************************************************************
	> File Name: euler12-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 16时02分48秒
 ************************************************************************/

//高度可约的三角形数

#include <stdio.h>

int num(int n) {

    return (n + 1) * n / 2;
}

int factor_num(int n) {
    int cnt = 0;
    for(int i = 1; i * i <= n; i++) {

        if(n % i == 0) cnt += 2;   //n = a * b,如果找到了a也就能对应的找到b,二者之间是一一对应的，所以每次加2，a, b一定有一个是小于根号n，一个是大于根号n的，所以可以写成i * i <=n
    }
    return cnt;
}

int main() {
    int n = 1;
    while(factor_num(num(n)) < 500) n++;
    printf("%d\n", num(n));
    return 0;
}
