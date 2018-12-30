/*************************************************************************
	> File Name: P1308.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月28日 星期三 21时13分37秒
 ************************************************************************/
/*
1.需要大小写转换，把单词全部转化为大写或者全部转化为小写
*/

#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main() {
    char str[30];
    char str1[30];
    char str2[30];
    int n = getchar();
    scanf("%[A-Za-z]", str);
    scanf("%s", str1);
    //gets(str2);
    puts(str2);
    printf("%d\n", n);
    printf(" str: %s\n str1: %s\n str2: %s\n", str, str1, str2);
    //for(int i = 0; i != '\0'; i++) {
    //}
    return 0;
}
