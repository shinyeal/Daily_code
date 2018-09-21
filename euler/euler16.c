/*************************************************************************
	> File Name: euler16.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月26日 星期四 23时57分05秒
 ************************************************************************/

//幂的数字和

#include <stdio.h>

int main() {

    int ans[400] = {1, 1};

    for(int i = 0; i < 1000; i++) {

        for(int j = 1; j <= ans[0]; j++ ) {
            ans[j] *= 2;
        }

        for(int j = 1; j <= ans[0]; j++) {
            if(ans[j] < 10)  continue;
            ans[j + 1 ] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }

    int num = 0;

  //  for(int i = ans[0]; i >= 1; i--) {
  //      printf("%d\n", ans[i]);
  //  }
    
    for(int i = 1; i <= ans[0]; i++) {
        num += ans[i];
    }

     printf("%d\n", num);

    return 0;
}


