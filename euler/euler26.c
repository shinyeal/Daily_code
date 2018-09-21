/*************************************************************************
	> File Name: euler26.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 10时02分03秒
 ************************************************************************/

//倒数的循环节

#include <stdio.h>    //n的余数最多为n - 1个，找余数，出现的第二次结束
#include <string.h>
#define MAX_N 1000
int dnum[MAX_N + 5];  //记录每一个余数第一次出现的位置

int get_length(int d) {
    int y = 1, n = 1;   //y:记录余数的变量，余数开始时等于1，n：项数，记录这个数字算到了第几位
    memset(dnum, 0, sizeof(dnum));  //把每个余数第一次出现的位置清零！！
    printf("1 / %d =  0.", d);
    while(y != 0 && dnum[y] == 0) {   //余数没有出现过
        printf("%d", y * 10 / d);
        dnum[y] = n;     //余数y第一次出现的位置就是当前的项数n
        y = y * 10 % d;   //计算各个位置的余数
        n += 1;
    }
    printf("(%d)\n", y ? n - dnum[y] : 0);
    return y ? n - dnum[y] : 0;    //n的最后一个位置减去y第一次出现的位置
}

int main() {

    int max_length = 0, ans = 0;
    for(int d = 2; d < 1000; d++) {  //遍历分母
        int temp_length  = get_length(d);   //get_length(d)返回的是每一个循环节的长度
        if(temp_length > max_length) {
            max_length = temp_length;
            ans = d;
        }
    }
    printf("%d -> %d\n", ans, max_length);

    return 0;
}
