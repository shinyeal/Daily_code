/*************************************************************************
	> File Name: euler22.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 15时04分58秒
 ************************************************************************/

//姓名得分

#include <stdio.h>
#include <iostream>
//#include "euler22.h"   
#include <algorithm>
#include <inttypes.h>
#include "euler22-1.h"
using namespace std;
int main() {
    int64_t i = 0;
    int64_t sum = 0, ans = 0;
    while(nameList[i++].length() != 0);
    sort(nameList, nameList + i - 1);
                //对姓名表按照字母顺序进行排序;
    i = 0;
    while(nameList[i].length() != 0) {
        sum = 0;
        for(int64_t j = 0; j < nameList[i].length(); j++) {
            sum += nameList[i][j] - 'A' + 1;
                //计算出每个名字的字母值;
        }
        ans += sum * (++i);
                //计算所有的姓名的得分之和;
    }
    printf("%" PRId64"\n", ans);
    return 0;
}
