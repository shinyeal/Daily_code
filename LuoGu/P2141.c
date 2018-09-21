/*************************************************************************
	> File Name: P2141.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月11日 星期二 10时34分30秒
 ************************************************************************/

//珠心算测验

#include <stdio.h>

int main() {

    int n;
    int count = 0;
    int num[105];
    int ans[105] = {0};

    scanf("%d", &n);
    for(int i = 1; i <= n ; i++) {
        scanf("%d", &num[i]);
        ans[i] = num[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int que = num[i] + num[j];
            for(int k = 1; k <= n; k++) {
                if(ans[k] == que) {
                    count++;
                    ans[k] = 0;

                }
            }
        }
    }
    printf("%d\n", count);

    return 0;
}
