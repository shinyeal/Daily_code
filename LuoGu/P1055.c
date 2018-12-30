/*************************************************************************
	> File Name: P1055.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月28日 星期三 14时48分50秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char num[15];
    for(int i = 0; i < 13; i++) {
        scanf("%c", &num[i]);
    }
    int sum = 0, k = 1;
    for(int j = 0; j < 11; j++) {
        if(j == 1 || j == 5) continue;
        int key = num[j] - '0';
        sum += key * k;
        k++;
    }
    int ans = num[12] - '0';
    if(num[12] == 'X') {
        ans = 10;
    }
    if(sum % 11 == ans) {
        printf("Right\n");
    } else {
        num[12] = (sum % 11) + '0';
        if(num[12] == 10 + '0') {
            num[12] = 'X';
        }
        for(int i = 0; i < 13; i++) {
            printf("%c", num[i]);
        }
        printf("\n");
    }
    return 0;
}

