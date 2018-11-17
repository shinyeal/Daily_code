/*************************************************************************
	> File Name: 17.binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月06日 星期二 19时27分29秒
 ************************************************************************/

//二分法的三种情况

#include <stdio.h>
#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

//1,2,3,4,5,6
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(num[mid] == x) return mid;
        if(num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

//111111100000000
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    //找到的是值（最后一个1）所在的位置, 而不是某个值的元素
    while(head < tail) {
        mid = (head + tail + 1) >> 1;
        //printf("head : %d, tail : %d\n", head, tail);
        if(num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//0000001111111
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while(head < tail) {
        mid = (head + tail) >> 1;
        if(num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    int n;
    int num1[10] = {1, 2, 5, 6, 7, 11, 12, 13, 14, 15};
    int num2[10] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    int num3[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    P(binary_search1(num1, 10, 11));
    P(binary_search2(num2, 10));
    P(binary_search3(num3, 10));
    return 0;
}
