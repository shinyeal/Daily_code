/*************************************************************************
	> File Name: euler14-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月26日 星期四 14时45分36秒
 ************************************************************************/

//最长考拉兹序列
//暴力算法

#include <stdio.h>
#include <stdio.h>
#include <inttypes.h>      //因为在运算的过程中数值可能会超出定义的最大值

#define MAX 1000000

int get_length(int64_t x) {
    
    int length = 1;

    while(x != 1) {

        if(x & 1) {
            x = 3 * x + 1;
        }else {
            x >>= 1;
        }
            length += 1;
    }
        return length;
}

int main () {
    
    int ans = 0, ans_length = 0;
    for(int i = 1; i < MAX; i++) {
        int temp_length = get_length(i);   //用整型temp_length记录当前长度。
        if(temp_length > ans_length) {
            ans = i;
            ans_length = temp_length;

        }
    }

        printf("%d(%d)", ans, (ans_length));
        return 0;

}
