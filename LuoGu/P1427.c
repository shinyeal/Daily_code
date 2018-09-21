/*************************************************************************
	> File Name: P1427.c
	> Author: xinyue
	> Mail: shinyeal9@yeah.net
	> Created Time: 2018年09月10日 星期一 11时46分18秒
 ************************************************************************/

//小鱼的数字游戏

#include <stdio.h>

int main() {

    int i = 0;
    int arr[105];

    do{
        i++;
        scanf("%d", &arr[i]);
    }while(arr[i] != 0);
    
    for(int j = i - 1; j >= 1; j--) {
        printf("%d ", arr[j]);
    }

    return 0;
}

