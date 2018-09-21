/*************************************************************************
	> File Name: euler17.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月26日 星期四 15时38分06秒
 ************************************************************************/

//表达数字的英文字母计数

#include <stdio.h>

    int find[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    int find1[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
    
    int get_num(int x) {
        if(x < 20) {
            return find[x];

        } else if(x < 100) {
          // for(int i = 2; i <= 10; i++) {
          //      for(int j = 0; j < 10; j++) {
          //          return find1[i] +find[j];
          //      }
          //  }
        return find1[x / 10] + find[x % 10];
        } else if(x <= 999) {
            if(x % 100 == 0) {
                return find[x / 100] + 7;
            }else {
                return find[x / 100] + 10 + get_num(x % 100);
            }
        } else {
            return 11;
        }
    }

int main() {

    int ans = 0;
    
    for(int i = 1; i <= 1000; i++) {
        ans += get_num(i);
    }
    printf("%d\n", ans);

    return 0;
}
