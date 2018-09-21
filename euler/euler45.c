/*************************************************************************
	> File Name: euler45.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 09时49分07秒
 ************************************************************************/

//三角形数、五边形数和六角形数

#include <stdio.h>
#include <inttypes.h>

int64_t Triangle(int64_t n) {

    return n * (n + 1) / 2;
}

int64_t Pentagonal(int64_t n) {

    return n * (3 * n - 1) / 2;
}

int64_t Hexagonal(int64_t n) {

    return n * (2 * n - 1);
} 

int64_t binary_search(int64_t (*num)(int64_t), int64_t n, int64_t x) {       //函数指针(*num), 函数传入参数(int),n:最大查找范围
    
    int64_t head = 0, tail = n - 1, mid;
    while(head <= tail) {

        mid = (head + tail) / 2;
        //mid = (head + tail) >> 2;
        if(num(mid) == x) return mid;
        if(num(mid) > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;

}

int main() {

    int64_t n = 144;
    while(binary_search(Pentagonal, 2 * n , Hexagonal(n)) == -1) ++n;
    //while((binary_search(Triangle, 2 * n, Hexagonal(n) == -1) && (binary_search(Pentagonal, 2 * n, Hexagonal(n)) == -1)  ++n;
    printf("%" PRId64 "\n", Hexagonal(n));

    return 0;
}
