/*************************************************************************
	> File Name: luogu_P1909.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年08月18日 星期六 15时19分32秒
 ************************************************************************/

//买铅笔

#include <stdio.h>

int main() {

    int n;
    int a, b;
    int min = 10000000;
    int ans;
    
    scanf("%d", &n);
    for(int i = 1; i <= 3; i++) {
        scanf("%d %d", &a, &b);

        for(int j = 1; j <= 3; j++) {
            
            if(n % a == 0) {
                ans = n / a * b;
            } else {
                ans = (n / a + 1) * b;
            }

            if(min > ans) {
                min = ans;
            }
        }
    }

    printf("%d\n", min);
    return 0;
}

