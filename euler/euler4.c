/*************************************************************************
	> File Name: euler4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 09时19分41秒
 ************************************************************************/

//最大回文乘积

#include <stdio.h>

int is_nums(int x) {
    int temp = x, num = 0;   //temp：记录原数字
    while(x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return temp == num;
}

int main () {
int ans = 0;

    for(int i = 100; i < 1000; i++) {
        for(int j = i; j < 1000; j++){
            if(i * j < ans) continue;     //i * j 要小于之前得到过得ans
            if(!is_nums(i * j)) continue;     //回文数单词：palindromic
            ans = i * j;
            //printf("%d ", ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}
