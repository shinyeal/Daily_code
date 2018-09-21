/*************************************************************************
	> File Name: euler29-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 15时08分43秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>

int main() {

    double a[10000];
    int s[5000];
    int i, j , m = 0;
    int count = 0;
    for(i = 2; i < 101; i++) {
        for(j = 2; j < 101; j++) {
            s[i] = j;
            a[m++] = pow(i, s[i]);
            count++;
        }

        for(int i = 2; i < m; i++) {
            for(int j= i + 1; j < m; j++) {
                if(a[i] == a[j]) {
                    count--;
                    break;
                }
            }
        }
    }

printf("%d",count);

    return 0;
}
