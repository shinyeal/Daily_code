/*************************************************************************
	> File Name: euler14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 15时44分58秒
 ************************************************************************/

//最长考拉兹序列
//记忆化数组

#include <stdio.h>
#include <inttypes.h>

#define MAX_N 1000000
#define KEEP_RANGE 2000000     //记录已经算过的数字

int keep_ans[KEEP_RANGE +5] = {0};

int get_length(int64_t x) {      //传入一个x数字，返回以x为起始的序列的长度
    
    if(x == 1) return 1;
    if(x <= KEEP_RANGE && keep_ans[x]) return keep_ans[x];
    int temp_ans;   //临时保存计算的结果
    if(x & 1) temp_ans = get_length(x * 3 + 1) + 1;    //get_length()计算下一个状态的长度
        else temp_ans = get_length(x >> 1) + 1;
    if(x <= KEEP_RANGE) keep_ans[x] = temp_ans;
        return temp_ans;
}

int main() {
    
    int ans = 0,  ans_length = 0;
    for(int i = 1; i < MAX_N; i++) {

        int temp_length = get_length(i);
        if(temp_length > ans_length) {
            ans = i;
            ans_length = temp_length;
        }
        
    }
    printf("%d(%d)\n", ans, ans_length);

    return 0;
}
