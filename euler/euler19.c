/*************************************************************************
	> File Name: euler19.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 19时03分46秒
 ************************************************************************/

//数星期日

#include<stdio.h>

int week(int y, int m, int d) {
    if(m == 1 || m == 2) {
        --y;
        m += 12;  //下一年
    }
    int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y /100 + y /400) % 7;   //蔡勒公式
    return w;
}

int main() {

    int sunday = 0;
    for(int y = 1901; y < 2001; y++) {
        for(int m = 1; m <= 12; m++) {
            if(week(y, m, 1) == 6) {
                sunday++;
                printf("%d-%d-%d\n", y, m, 1);
            }
        }
    }

    printf("%d\n", sunday);

    return 0;

}
