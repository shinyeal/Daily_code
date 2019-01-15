/*************************************************************************
	> File Name: 22.ac.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月13日 星期日 20时44分19秒
 ************************************************************************/

//AC 自动机
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail;
} Node;

Node *getNewNode() {
    //calloc:初始化是空
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

void clear(Node *node) {
    if(node == NULL) return ;
    for(int i = 0; i < BASE; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

typedef struct Queue {
    //队列的数据区存储AC自动机的节点地址的
    Node **data;
    int head, tail, size;
} Queue;

Queue *init_queue(int n) {
    Queue *q = (Queue *)calloc(sizeof(Queue), 1);
    //data初始化n个指针空间，他应该是一个指针数组
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->tail = q->head = 0;
    return q;
}

//* ：返回队首元素地址
Node *front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->head == q->tail;
}

void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
    return ;
}

void pop(Queue *q) {
    if(empty(q)) return ;
    q->head++;
}

void clear_queue(Queue *q) {
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for(int i = 0; str[i]; i++){
        int ind = str[i] - BEGIN_LETTER;
        if(p->next[ind] == NULL) p->next[ind] = getNewNode(), ++cnt;
        p = p->next[ind];
     }
    p->flag = 1;
    return cnt;
}

void build_ac(Node *root, int n) {
    //建立AC自动机需要一个队列，队列的大小和传入子串节点数相等
    Queue *q = init_queue(n + 10);
    //根节点的失败指针是空值
    root->fail = NULL;
    push(q, root);
    while(!empty(q)) {
        Node *now_node = front(q);
        pop(q);
        //遍历当前子节点的失败指针
        for(int i = 0; i < BASE; i++) {
            //第i个子孩子没有子节点，不需建立失败指针
            if(now_node->next[i] == NULL) continue;
            //建立当前节点的失败指针
            Node *p = now_node->fail;
            //失败指针一直往上找
            while(p && p->next[i] == NULL) p = p->fail;
            /*当前节点的失败节点是空，
              证明当前节点的第i个子孩子的失败节点是根节点*/
            if(p == NULL) now_node->next[i]->fail = root;
            //否则当前节点的子节点的失败节点指向失败节点的子孩子
            else now_node->next[i]->fail = p->next[i];
            push(q, now_node->next[i]);
        }
    }
    return ;
}

int match(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    //没有回溯过程，直接遍历
    for(int i = 0; str[i]; i++) {
        //ind：节点向哪里跳转
        int ind = str[i] - BEGIN_LETTER;
        while(p &&p->next[ind] == NULL) p = p->fail;
        //找到了一个p下面有第i个子孩子或者p节点为空
        if(p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        //统计成功多少个单词，找链上找有多少个独立成词的flag节点
        //p所指的状态顺着失败指针一直找上去，链上的节点都相当于当前状态所匹配成功的节点
        while(q) cnt += q->flag, q = q->fail;
    }
    return cnt;
}

int main() {
    Node *root = getNewNode();
    int n, cnt = 0;
    char str[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    //build ac
    build_ac(root, cnt);
    scanf("%s", str);
    //match ac,出现了多少次字典中的单词
    printf("match word cnt : %d\n", match(root, str));
    return 0;
}
