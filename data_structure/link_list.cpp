/*************************************************************************
	> File Name: link_list.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月11日 星期四 20时23分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int *data;
    struct LinkNode *next；
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    //让head成为虚拟节点
    int length;

} LinkList;

LinkList *init() {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p -> head.next = 
}

//初始化
LinkNode *getNewNode(int value) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    p -> data = value;
    p ->next = NULL;
    return p;
}

LinkNode *insert(LinkList l, int value, int ind) {
    //虚拟节点
    LinkNode ret, *p = &ret;
    ret.next = l;
    while(ind--) {
        p = p -> next;
        //插入非法
        if(p == NULL) return l;
    }
    LinkNode *new_node = getNewNode(value);
    new_node ->next = p ->next;
    p -> next = new_node;
    return ret.next;
}

LinkNode *earse(LinkList l, int ind) {
    LinkNode ret, *p = &ret;
    ret.next = l;
    while(ind--) {
        p = p -> next;
        if(p == NULL) return l;
    }
    if(p -> next == NULL);
    p -> next -> next = p;
}

//head为什么不加* ...
void clear(LinkList head) {
    if(head == NULL) return ;
    LinkNode *p = head, *q;
    while(p) {
        q = p;
        p = p -> next;
        free(q);
    }
    return ;
}

void output(LinkList l) {
    printf()
    LinkNode *p = l;
    while (p != NULL) {
        printf("%d->", );
    }
}

int main() {
    srand(time(0));
    LinkList l = NULL;
    int length = 0;
    #define MAX 20
    for(int i = 0; i < MAX; i++) {
        int op = rand() % 4, value, ind;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                ind = rand() % (length + 1);
                value = rand() % 100;
                printf("insert(%d %d) to LinkList\n", value, ind);
                output(l);
                length += 1;
            } break;
            case 3: {
                if(length == 0) break;
                ind = rand() % length;
                printf("earse(%d) from LinkList\n", ind);
                l = earse(ind);
                output(l);
                length -= 1;    
            } break;
        }
    }
    clear(l);
    return 0;
}
