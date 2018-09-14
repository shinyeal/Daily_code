/*************************************************************************
	> File Name: sprintf_test.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月14日 星期五 15时23分02秒
 ************************************************************************/

//sprintf 计算一个数字的位数

#include <stdio.h>

int main() {
    
    int n;
    char str[100];
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", sprintf(str, "%d", n));
        //输出一个1-20的字符串
        for(int i = 1, j = 0; i <= 20; i++) {
            j += sprintf(str + j, "%d", i);
        }
        printf("str = %s\n", str);
    }
    return 0;
}
