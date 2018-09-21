/*************************************************************************
	> File Name: euler32.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 14时25分42秒
 ************************************************************************/

//全数字的乘积

#include <stdio.h>
#include <math.h>
#define MAX_N 10000

int digit(int x) {      //求位数
    
    return floor(log10(x)) + 1;

}

int get_digit (int a, int *num) {

    while(a) {

        if(a % 10 == 0) return 0;   //a里有0
        if(num[a % 10]) return 0;   //a的这一位数字也出现过
        num[a % 10] = 1;
        a /= 10;
    }
    return 1;
}

int is_valid(int a, int b, int c) {   //判断a, b, c 是否满足要求
    
    int num[10] = {0};
    if(!get_digit(a, num)) return 0;
    if(!get_digit(b, num)) return 0;
    if(!get_digit(c, num)) return 0;

    return 1;
}


int valid[MAX_N] = {0};   //开一个数组记录是否出现过这个数字

int main() {

    int ans = 0;

    for(int a = 2; digit(a) + digit(a) + digit(a * a) <= 9; a++) {   //较小乘数位数相加小于9
        for(int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {

            if(digit(a) + digit(b) + digit(a * b) < 9) continue;

            if(is_valid(a, b, a * b)) {

                ans += a * b * (1 - valid[a * b]);    //vaild没出现过时为0，出现过记为1，避免有重复数字

                valid[a * b] = 1;
                printf("%d * %d = %d\n", a, b, a * b);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
