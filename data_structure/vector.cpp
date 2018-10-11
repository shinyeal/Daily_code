/*************************************************************************
	> File Name: vector.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月11日 星期四 19时00分01秒
 ************************************************************************/

//顺序表

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_ARG(a, b) ((#a)[0] ? a + 0 : b)
#define init(a) __init(DEFAULT_ARG(a, 10))

//结构定义
typedef struct Vector {
    int *data;  //指向存储区内容
    int size, length;
} Vector;

void *__init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    v -> data = (int *)malloc(sizeof(int) * n);
    v -> size = n;
    v -> length = 0;
    return p;
}

int expand(Vector * v) {
    //原空间申请地址
    //printf("[%p] expanding", v -> data);
    int *p = (int *)realloc(v -> data, sizeof(int) * 2 * v -> size); //原空间申请地址, 新申请的
    if(p == NULL) return 0;
    v -> data = p;
    v -> size *= 2;
    //printf(" [%p] expand vactor success, %s \n", v ->data, v -> size);
    return 1;
}

int insert(Vector *v, int value, int ind) {
    //顺序表满了
    if(v -> length == v ->size) {
        if(expand(v) == 0) {
            return 0;
        }
    }
    //下标位置不合法
    if(ind < 0 || ind > v -> length) return 0;
    //倒过来写会覆盖
    for(int i = v -> length - 1; i >= ind; i--) {
        v ->data[i + 1] = v -> data[i];
    }
    v -> data[ind] += value;
    v -> length += 1;
    return 1;
}

int erase(Vector *v, int ind) {
    if(v -> length == 0) return 0;
    if(ind < 0 || ind > v -> length) return 0;
    for(int i = ind + 1; i < v -> length; i++) {
        v ->data[i + 1] = v -> data[i];
    }
    v ->length -= 1;
    return 1;
}

void clear(Vector *v) {
    if(v == NULL) return;  //顺序表如果是空地址
    free(v -> data);
    free(v);   //数据表本身空间
    return ;
}

void output(Vector *v) {
    printf("Vector = [");
    for(int i = 1; i < v -> length; i++) {
        printf(" %d", v -> data);
    }
    printf("]");
    return ;
}

int main() {
    Vector *v = init();
    #define MAX 40
    for(int t = 0;t < MAX; t++) {
        int op = rand() % 5, ind, value;
        switch(op) {
            case 4:
            case 3:
            case 2:
            case 0: {
                ind = rand() % (v ->length + 3) - 1;
                value = rand() % 100;
                printf(" [%d] insert(%d, %d) to vector\n", insert(v, value, ind), value, ind);
                output(v);
            } break;
            case 1: {
                ind = rand() % (v ->length + 3) - 1;
                printf("[%d] earse(%d) from vector\n", erase(v, ind), ind);
                output(v);
            } break;
        }
    }
    clear(v);
    return 0;
}
