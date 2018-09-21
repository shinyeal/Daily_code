/*************************************************************************
	> File Name: luogu_P1089.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年08月18日 星期六 12时08分39秒
 ************************************************************************/

//津津的储蓄计划

#include <stdio.h>

int main() {

    int money[20] = {0};
    int hand = 300;
    int sum = 0;

    for(int i = 1; i <= 12; i++) {
        scanf("%d", &money[i]);
    }

    for(int i = 1; i <= 12; i++) {
        hand = hand - money[i];

        if(hand < 0) {
            printf("%d", -i);
            break;
        }
        if(hand >= 100) {
            sum += hand / 100 * 100;
            hand = hand % 100 + 300;
        } else if(hand >= 0) {
            hand = hand + 300;
        }

    }
    
    if(hand > 0)
        printf("%d", sum + sum / 5 + hand - 300);
    return 0;
}
