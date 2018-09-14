/*************************************************************************
	> File Name: 1.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月13日 星期四 18时55分53秒
 ************************************************************************/

//计算一个数字的位数

#include <stdio.h>
int main() {
    int n;
    char str[100];
    //需要一个文件指针
    FILE *fout = fopen("/dev/null", "w");
    //  /dev/null: 垃圾桶
    // w: 赋予一种写的模式
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", fprintf(fout, "%d", n));
    }

    return 0;
}
