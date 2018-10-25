/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: 2018年10月21日 星期日 18时14分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, length;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q -> length = n;
    q -> data = (int *)malloc(sizeof(int) *n);
    q -> head = 0;
    q -> tail = -1;
    return q;
}

int push(Queue *q, int value) {
    if(q -> tail + 1 == q -> length) return 0;
    q -> tail += 1;
    q -> data[q -> tail] = value;
    return 1;
}

int empty(Queue *q) {
    return q -> head > q -> tail;
}

void pop(Queue *q) {
    if(empty(q)) return ;
    q -> head += 1;
    return;
}

int front(Queue *q) {
    if(empty(q)) return 0;
    return q -> data[q -> head];
}

void clear(Queue *q) {
    if(q == NULL) return ;
    free(q -> data);
    free(q);
    return ;
}

void output(Queue *q) {
    printf("Queue = [");
    for(int i = q -> head; i <= q -> tail; i++) {
        printf(" %d", q -> data[i]);
        i == q -> tail || printf(",");
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_OP 20
    srand(time(0));
    Queue *q = init(MAX_OP);
    for(int i = 0; i < MAX_OP; i++) {
        //随机三个入队操作和一个出队操作
        int op = rand() % 4, value = rand() % 100;
        switch(op) {
            case 0:
            case 1:
            case 2:
                push(q, value);
                printf("push %d to queue\n", value);
                output(q);
                break;
            case 3:
                printf("pop %d from queue\n", front(q));
                pop(q);
                output(q);
                break;
        }
    }
    return 0;
}

