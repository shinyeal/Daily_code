/*************************************************************************
	> File Name: euler29.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 10时17分13秒
 ************************************************************************/

//不同的幂

#include <stdio.h>
#include <string.h>
#define MAX_N 10000   //结果集的个数
#define MAX_M 210     //结果的长度

int result[MAX_N][MAX_M] = {0};
int result_length = 0;    //记录结果集中有多少个大整数
int find_result(int * num) {
    for(int i = 0; i < result_length; i++) {
        if(memcmp(result + i, num, sizeof(int) * MAX_M))  continue;
        return i + 1;
    }
    return 0;
}

int main() {

    int temp[MAX_M];
    for(int a = 2; a <= 100; a++) {
        for(int b = 2; b <= 100; b++) {

        int temp[MAX_M] = {0};
            temp[0] = temp[1] = 1;
            temp[a] *= b;
            //temp[0]++;
            
        }

        for(int i = 1; i <= MAX_M; i++) {
            if(temp[i] < 10) continue;
            temp[i + 1] += temp[i] / 10;
            temp[i] %= 10;
            temp[0] += (i == temp[0]);
        }
    }
    if(find_result(temp) == 0) {   //没找到temp的值
        memcpy(result + result_length, temp, sizeof(int) * MAX_M);  //内存拷贝,把tenp数组中的数据拷贝到result,拷贝MAX_M个
        result_length += 1;
    }

    printf("%d\n", result_length);
    return 0;
}
