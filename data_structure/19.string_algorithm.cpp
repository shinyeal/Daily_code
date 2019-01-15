/*************************************************************************
	> File Name: 19.string_algorithm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月30日 星期日 19时43分51秒
 ************************************************************************/

//字符串匹配
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST(func, a, b) { \
    printf("%s(\"%s\", \"%s\") = %d\n", #func, a, b, func(a, b)); \
}

//暴力算法
int BruteForce(char *str, char *pattern) {
    for(int i = 0; str[i]; i++) {
        int flag = 1;
        for(int j = 0; pattern[j]; j++) {
            if(str[i + j] == pattern[j]) continue;
            flag = 0;
            break;
        }
        if(flag) return i;
    }
    return -1;
}

//KMP 算法
int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) *strlen(pattern));
    next[0] = -1;
    for(int i = 1; pattern[i]; i++) {
        //先让j等于上一个next数组上一个的值
        int j = next[i - 1];
        //如果j不是-1，并且下标加一和当前子串不相等，j根据next数组的值回溯到上一个和子串当前元素相等的位置
        while(j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        //如果数组下标加一和
        if(pattern[j + 1] == pattern[i]) next[i] = j + 1;
        //否则next数组的值是-1
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while(str[i]) {
        while(j != -1 && str[i] != pattern[j + 1]) j = next[j];
        if(str[i] == pattern[j + 1]) {
            j += 1;
        }
        i += 1;
        if(pattern[j + 1] == 0) return i - strlen(pattern);
    }
    return -1;
}

//SUNDAY 算法
int Sunday(char *str, char *pattern) {
    #define BASE 128
    int ind[BASE] = {0};
    int len = strlen(pattern), max_len = strlen(str);
    for(int i = 0; i < BASE; i++) {
        ind[i] = len + 1;
    }
    for(int i = 0; i < len; i++) {
        ind[pattern[i]] = len - i;
    }
    for(int i = 0; i < max_len; ) {
        int flag = 1;
        for(int j = 0; j < len; j++) {
            if(str[i + j] == pattern[j]) continue;
            i += ind[str[i + len]];
            flag = 0;
            break;

        }
        if(flag) return i;
    }
    return -1;
    #undef BASE
}

//Shift_And 算法
int ShiftAnd(char *str, char *pattern) {
    #define BASE 128
    int code[BASE] = {0}, len = 0;
    for(len = 0; pattern[len]; len++) {
        code[pattern[len]] |= (1 << len);
    }
    int p = 0;
    for(int i = 0; str[i]; i++) {
        p = (p << 1 | 1) & code[str[i]];
        if(p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
    #undef BASE
}

int main() {
    char str[100], pattern[30];
    while(scanf("%s%s", str, pattern) != EOF) {
        TEST(BruteForce, str, pattern);
        TEST(KMP, str, pattern);
        TEST(Sunday, str, pattern);
        TEST(ShiftAnd, str, pattern);
    }
    return 0;
}
