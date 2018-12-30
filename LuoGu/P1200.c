/*************************************************************************
	> File Name: P1200.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月28日 星期三 19时44分22秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main() {
    int i = 0, j = 0;
    char num1[10], num2[10];
    scanf("%[A-Z]\n%[A-Z]",&num1,&num2); 
    int ans1 = 1, ans2 = 1;
    while(num1[i] != '\0') {
        ans1 *= num1[i] - '@';
        i++;
    }
    while(num2[j] != '\0') {
        ans2 *= num2[j] - '@';
        j++;
    }
    if(ans1 % 47 == ans2 % 47) {
        printf("GO\n");
    } else {
        printf("STAY\n");
    }
    return 0;
}
