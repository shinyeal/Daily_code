/*************************************************************************
	> File Name: euler28.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 10时19分19秒
 ************************************************************************/

//螺旋数阵对角线

#include<stdio.h>

int main () {

int sum = 1;

    for(int i = 3; i <= 1001; i +=2) {
        sum += 4 * i * i - 6 * i + 6;
        //里边比外边一圈边长多两个数字
        //一圈的数字：
        //n * n
        //n * n - n + 1
        //n * n - n + 1 - n + 1
        //n * n - n + 1 - n + 1 - n + 1
        //加起来就是4 * n * n - 6 * n + 6
    }

    printf("%d\n", sum);
    return 0;
}
