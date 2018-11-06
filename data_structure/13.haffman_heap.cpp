/*************************************************************************
	> File Name: 13.haffman_heap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月01日 星期四 15时05分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *data;
    int size, length;
} Heap;

void init(Heap *h, int len) {
    h->data = (int *)malloc(sizeof(int) *len);
    h->size = 0;
    h->length = len;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;  *a = *b;  *b = temp;
}

void push(Heap *h, int value) {
    if(h->size == h->length) return ;
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    while(h->data[current] < h->data[father]) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

void update(Heap *h, int pos, int n) {
    int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
    int max_value = pos;
    if(lchild < n && h->data[lchild] < h->data[max_value]) {
        max_value = lchild;
    }

    if(rchild < n && h->data[rchild] < h->data[max_value]) {
        max_value = rchild;
    }

    if(max_value != pos) {
        swap(&h->data[max_value], &h->data[pos]);
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    if(h->size == -1) return ;
    swap(&h->data[h->size - 1], &h->data[0]);
    h->size--;
    update(h, 0, h->size);
}

int top(Heap *h) {
    return h->data[0];
}

void output(Heap *h) {
    for(int i = h->size - 1; i >= 0; i--) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    int n, value;
    int ans = 0;
    scanf("%d", &n);
    init(heap, n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &value);
        push(heap, value);
    }
    while(heap->size > 1) {
        int a = top(heap);
        pop(heap);
        int b = top(heap);
        pop(heap);
        ans += a + b;
        push(heap, a + b);
    }
    printf("%d\n", ans);
    output(heap);
    clear(heap);
    return 0;
}
