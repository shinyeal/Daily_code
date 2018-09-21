/*************************************************************************
	> File Name: euler11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 14时55分07秒
 ************************************************************************/

//方阵中的最大乘积

#include<stdio.h>

int dir_arr[4][2] = {  //4代表有多少个向量，2代表有多少维
    1, 1, 1, -1,
    0, 1, 1, 0
};

int main() {
    int num[30][30] = {0};
    for(int i = 5; i < 25; i++) {
        for(int j = 5; j < 25; j++) {   //越界后值为0，不用再边界判断了。
            scanf("%d",num[i] + j);
        }
    }
    int ans = 0;
    for(int x = 5; x < 25; x++) {
        for(int y = 5; y < 25; y++) {
            for(int k = 0; k < 4; k++) {    //k个方向
                int p = 1;
                for(int step = 0; step < 4; step++) {    //走4步
                    int xx = x + step * dir_arr[k][0];
                    int yy = y + step * dir_arr[k][1];
                    p *= num[xx][yy];
                }
                if(p > ans)
                    ans = p;
            }
        }
    }
    return 0;
}
