/*************************************************************************
	> File Name: euler19-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 20时04分20秒
 ************************************************************************/

//数星期日

#include <stdio.h>

int days[13] = {
        0, 31, 28, 31, 30,
        31, 30, 31, 31, 30,
        31, 30, 31

};   //12个月的数组

int eryue(int y) {    //判断平闰年
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0 )
        return 1;
    else
        return 0;
}

int next_day(int y, int m, int d) {
    
    d = d + 1;    //判断下一天是哪一天
    
    if (d > days[m] + (m == 2 && eryue(y))){
        d = 1;        
    }
    return d; 
}

int main() {
    
        int y = 1900, m = 1, d = 1;
        int week = 1;
        int ans = 0;
    do{
        d = next_day(y, m, d);
        week = (week + 1) % 7;
        if(d == 1) {
            m++;        
        }

        if(m > 12) {
            y++;
            m = 1;        
        }

        if(y >= 1901 && m < 13 && d == 1 && week == 0) {
            ans++;
            printf("%d-%d-%d\n",y, m, d);                   
        }

    }while(y != 2001);

        printf("%d\n", ans);
        return 0;

}
