/*************************************************************************
	> File Name: luogu_P1424.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年08月18日 星期六 19时31分05秒
 ************************************************************************/

//小鱼的航程(改进版)

#include <stdio.h>

int main() {
    int x, n;
    int head, tail;
    int ans1, ans2, ans3;
    scanf("%d %d", &x, &n);

    head = 7 - x + 1;
    if(head > 2) {      //周六周日
        ans1 = (head - 2) * 250;
    } else {
        ans1 = 0;
    }
    
    ans2 = (n - head) / 7 * 5 * 250;

    tail = (n - head) % 7;
    if(tail <= 5) {
        ans3 = tail * 250;
    } else {
        ans3 = 5 * 250;
    }

    int sum = ans1 + ans2 + ans3;

    printf("%d\n", sum);
    return 0;
}
