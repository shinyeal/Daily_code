/*************************************************************************
	> File Name: test_frame.h
	> Author: 
	> Mail: 
	> Created Time: 2018年10月06日 星期六 15时17分06秒
 ************************************************************************/

#ifndef PROJECT_TEST_FRAME_H
#define PROJECT_TEST_FRAME_H

int TEST(int test, char *func) {

}

int EXPECT(char *test, int ans) {
    int result;
    result = is_prime(test);
    if(result == ans) {
        return 1;
    }
    return 0;
}

void RUN_ALL_TEST() {

    for(int i = 1; i <= 2; i++) {
        printf("[%s, %s]", , );
        for(int j = 1; j<= test.size; j++) {
            int flag = 1;
            if(EXPECT(test, func) == 0) {
                flag = 0;
            }
            printf("%s", EXPECT(test), flag);
        }
        printf("[PASS]");
    }
}

#endif
