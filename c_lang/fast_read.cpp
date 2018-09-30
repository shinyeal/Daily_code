/*************************************************************************
> File Name: fast_read.cpp
> Author: 
> Mail: 
> Created Time: 2018年09月18日 星期二 20时37分07秒
************************************************************************/

#include<iostream>
#include 
using namespace std;

char ss[1<<17], *A = ss, *B = ss;
inline char gc() {

    //gc(): 取数 2的17次方字节
    //fread 成功读入多少字符（整型）
    //ss : 读入缓冲区
    //B 结束位置 A：开始位置
    //逗号表达式返回值是最后一个式子的返回值
    //fread = 0 时（结束输入）时条件表达式才能 = 1
    //A == B 成立代表缓冲区没东西了， 头指针尾指针重合了
    //*A : A指向的字符右移
    return A == B && (B = (A = ss) + fread(ss, 1, 1<<17, stdin), A == B) ? -1 : *A++;
}

template<typename T> inline void sdf(T &x) {
    char c;ZZ
    T y = 1;
    while(c = gc(), (c < 48 || c > 57) && c != -1) {
        if(c == '-') y = -1;   
    }
    x = c ^ 48;   
    while(c = gc(), (c <= 57 && c >= 48)) {
        x = (x << 1) + (x << 3) + (c ^ 48);    
    }
    x *= y;
}

int main() {
    int n, a;
    sdf(n);
    for(int i = 0; i < n; i++) {
        sdf(a);    
    }
    return 0;

}

