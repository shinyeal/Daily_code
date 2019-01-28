/*************************************************************************
	> File Name: 3.1.cycle_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月28日 星期一 15时57分57秒
 ************************************************************************/

//循环队列
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, length;
    int cnt; //记录队列中的元素数量，cnt = 0为空，cnt = length队列满了
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) *n);
    q->head = 0;
    q->tail = -1;
    q->length = n;
    q->cnt = 0;
    return q;
}

int empty(Queue *q) {
    return q->cnt == 0;
}

int push(Queue *q, int value) {
    if(q->cnt == q->length) return 0;
    q->tail += 1;
    if(q->tail >= q->length) q->tail -= q->length;
    q->cnt += 1;
    q->data[q->tail] = value;
    return 1;
}

void pop(Queue *q) {
    if(empty(q)) return ;
    q->head += 1;
    if(q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    return ;
}

int front(Queue *q) {
    if(empty(q)) return 0;
    return q->data[q->head];
}

void clear(Queue *q) {
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(Queue *q) {
    printf("Queue = [");
    for(int i = 0; i < q->cnt; i++) {
        int ind = (q->head + i) % q->length;
        printf(" %d", q->data[ind]);
        i + 1 == q->cnt || printf(",");
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_OP 20
    Queue *q = init(MAX_OP);
    srand(time(0));
    for(int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, value = rand() % 100;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                push(q, value);
                printf("push %d to queue\n", value);
                output(q);
            } break;
            case 3: {
                printf("pop %d to queue\n", front(q));
                pop(q);
                output(q);
            } break;
        }
    }
    return 0;
}
