/*************************************************************************
> File Name: test_frame.c
> Author: 
> Mail: 
> Created Time: 2018年10月06日 星期六 15时15分34秒
************************************************************************/
#include <stdio.h>
//#include "test_frame.h"
//#include "test_frame1.h"
#include "test_frame2.h"

int add(int a, int b) {
    return a + b;

}

int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

TEST(test, is_prime_func) {
    EXPECT(is_prime(2), 1);
    EXPECT(is_prime(-2), 1);
    EXPECT(is_prime(15), 1);
    EXPECT(is_prime(9973), 1);

}

TEST(test, add_func) {
    EXPECT(add(1, 2), 2);
    EXPECT(add(3, 4), 7);
    EXPECT(add(2, 2), 4);

}

int main() {
    return RUN_ALL_TEST();
}
