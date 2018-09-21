/*************************************************************************
	> File Name: euler24.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 16时09分02秒
 ************************************************************************/

//字典序排列

#include<stdio.h>
#define MAX_N 10

int jnum[MAX_N] = {0};    //记录他跳了几个状态
int dnum[MAX_N] = {0};    //记录哪些数字用过了

void init() {

    jnum[0] = dnum[0] = 1;  //jnum初始化,dnum初始化，代表还没有被用过
    for(int i = 1; i < MAX_N; i++) {
        dnum[i] = 1;
        jnum[i] = i * jnum[i - 1];   //初始化了1~9的阶乘
    }
    return;  //先写了一个初始化函数
}

int judge_num(int n, int k) {  // 确定这个数字，n:后边的数字有多少个，k：还想往后边跳多少位
    int ind = (k /jnum[n]) + 1;   //找到第几个可用的数字
    int i = -1;

    while(ind > 0) {

        i++;
        ind -= dnum[i];  //找到了第ind个可用的数字，这个数字就是i

    }
        dnum[i] = 0;   //数字i被用过了
        return i;

}

int main() {
    init();   //调用了初始化函数
    int n, k;   //n是10， k是1000000
    scanf("%d %d",&n, &k);
    k -= 1;   //求出的是k - 1个状态
    for(int i = n - 1; i >= 0; i--) {
        int num = judge_num(i, k);
        printf("%d ", num);
        k %= jnum[i];   //还剩多少数字
        
    }

    printf("\n");
    

    return 0;
}
