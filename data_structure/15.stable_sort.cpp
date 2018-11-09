/*************************************************************************
	> File Name: 15.stable_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月04日 星期日 19时45分51秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//当a = b的时候不能使用异或交换两个数字，否则结果是0

#define swap(a, b) { \
    a ^= b; b ^= a; a ^= b; \
}


//建立一个num的存储空间，将arr数组中的东西拷贝到num数组中
#define TEST(arr, n, func, args...) { \
    int *num = (int *)malloc(sizeof(int) * n); \
    memcpy(num, arr, sizeof(int) *n); \
    output(num, n); \
    printf("%s = ", #func); \
    func(args); output(num, n); \
    free(num); \
}

void insert_sort(int *num, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}

void bubble_sort(int *num, int n) {
    int times = 1;
    //&& times: 说明上一轮是有交换动作的
    for(int i = 1; i < n && times; i++) {
        times = 0;
        for(int j = 0; j < n - i; j++) {
            if(num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
        }
    }
    return ;
}

void merge_sort(int *num, int l, int r) {
    if(r - l <= 1) {
        //区间内部有两个元素, 手动排序
        if(r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    //临时存储区
    int *temp = (int *)malloc(sizeof(int) *(r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 <= mid || p2 <= r) {
        if(p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) *(r - l + 1));
    free(temp);
    return ;
}

void randint(int *num, int n) {
    while(n--) num[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX 20
    int arr[MAX];
    randint(arr, MAX);
    TEST(arr, MAX, insert_sort, num, MAX);
    TEST(arr, MAX, bubble_sort, num, MAX);
    TEST(arr, MAX, merge_sort, num, 0, MAX - 1);
    return 0;
}
