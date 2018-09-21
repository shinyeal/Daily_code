/*************************************************************************
	> File Name: euler9.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 09时35分00秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX 1000
int main() {

    int a = 0, b = 0, c = 0;
    int e = 0;

    for(int i = 1; i * i <= MAX; i++) {
        for(int j = i + 1; j <= MAX; j++) {   

            a = 2 * i * j;        //根据性质四推导出公式
            b = j * j - i * i;
            c = i * i + j * j;

            
            if(1000 % (a + b + c) == 0) {   //当a, b, c三个数是素勾股数时;
                e = (int)pow(1000 / (a + b + c), 3);  //因为要输出的是三个素勾股数的乘积，设n为素勾股数的倍数， 则e = pow(n, 3); 
                printf("%d\n" , e * a * b * c);  
             //printf("%d %d %d", a, b, c);
            }
            if(e)
                break;
        }
    }


    return 0;
}
