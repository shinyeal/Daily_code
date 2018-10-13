/*************************************************************************
> File Name: test.cpp
> Author: 
> Mail: 
> Created Time: 2018年10月12日 星期五 19时10分01秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//结构定义
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} *LinkList, LinkNode;
//指向这个节点的指针才是linklist

//链表节点的初始化
//返回的是一个LinkNode的地址
LinkNode *getNewNode(int value) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p -> data = value;
    p -> next = NULL;
    return p;
}

//向链表的某个位置去添加一个元素
LinkNode *insert(LinkList l, int value, int ind) {
    //虚拟节点 可以应对0号位插入时
    LinkNode ret, *p = &ret; 
    //ret 虚拟节点，他是这个链表中的第一个元素
    //定义一个p一开始指向虚拟节点
    ret.next = l; //虚拟节点指向原来的链表
    while(ind--) {
        p = p -> next;
        if(p == NULL) return l;
        //当前插入是非法的, 返回之前的链表
    }
    //p已经指向待插入节点的前一个节点
    LinkNode *new_node = getNewNode(value);
    new_node -> next = p ->next;
    p -> next = new_node;
    return ret.next;
}

//链表的删除 也需要用到虚拟节点
LinkNode *erase(LinkList l, int ind) {
    LinkNode ret, *p = &ret;
    ret.next = l;
    while(ind--) {
        p = p -> next;
        if(p == NULL) return l;
    }
    if(p -> next == NULL) return l; 
    //p节点是指待删除节点的前一个节点， p -> next 是待删除节点
    LinkNode *q = p -> next;
    p -> next = p -> next -> next;
    free(q);
    return ret.next;
}

//清空链表
void clear(LinkList head){
    if(head == NULL) return ;
    //遍历性去free掉
    LinkNode *p = head, *q;
    while(p) {
        q = p;
        p = p -> next;
        free(q);
    }
    return;
}

void output(LinkList l) {
    LinkNode *p = l;
    while(p != NULL) {
        printf("%d ->", p -> data);
        p = p -> next;
    }
    printf("NULL\n");  //链表的最后一位
    return ;
}

int main() {
    srand(time(0));
    LinkList l;
    int length = 0;
    #define MAX 20
    for(int i = 0; i < MAX; i++) {
        int op = rand() % 4, value, ind;
        //75%的插入概率，25%的删除概率
        switch(op) {
            case 0:
            case 1:
            case 2: {
                //插入
                ind = rand() % (length + 1);
                //待插入元素的位置
                value = rand() % 100;
                //待插入元素的值
                printf("insert(%d, %d) to LinkList\n", value, ind);
                l = insert(l, value, ind);
                output(l);
                length += 1;
            } break;
            case 3: {
                //删除
                if(length == 0) break;
                ind = rand() % length;
                printf("erase(%d) from LinkList\n", ind);
                l = erase(l, ind);
                output(l);
                length -= 1;
            } break;
        }

    }
    clear(l);
    return 0;
}
