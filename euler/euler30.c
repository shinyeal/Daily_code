/*************************************************************************
	> File Name: euler30.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 10时52分32秒
 ************************************************************************/

//各位数字的五次幂

#include<stdio.h>
#include <math.h>

# define MAX_N 354294    //6 * 9 ^ 5
        //10 ^ n 和 n * 9 ^ 5 的交点的数字为5.xxx约等于6.

int is_equal(int x) {
    int temp = x, num = 0;
    while(x) {
        num += (int)pow(x % 10, 5);
        x /= 10;
    }
    return temp == num;

}
int main() {

int ans = 0;
    for(int i = 2; i < MAX_N; i++) {
        if(!is_equal(i)) continue;
        ans += i;
    }
    printf("%d\n", ans);

    return 0;
}
