/*************************************************************************
	> File Name: test_frame1.h
	> Author: 
	> Mail: 
	> Created Time: 2018年10月06日 星期六 20时29分47秒
 ************************************************************************/

#ifndef _TEST_FRAME1_H
#define _TEST_FRAME1_H

#define EXPECT(x, y) { \
    int count = 0;\
    if(x == y) { printf("%s == %s YES\n", #x, #y); count++; }\
    else printf("%s == %s NO\n", #x, #y);\
}\


#define TEST(a, b) void b() \

#define RUN_ALL_TEST() ( \
    printf("[test,is_prime_func]\n"),\
    is_prime_func(), \
    /*printf("[ \033[1;32mPASS\033[0m ] total: 4, expect_cnt : 2),\*/ \
    printf("[test,add_func]\n"), \
    add_func(), \
    printf("[ \033[1;32mPASS\033[0m ] total: 3, expect_cnt : 3\n"),\
    1\
)\

#endif
