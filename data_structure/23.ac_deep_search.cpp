/*************************************************************************
	> File Name: 23.ac_deep_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月20日 星期日 09时45分03秒
 ************************************************************************/

//AC自动机，递归版优化（用深度搜索实现）
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BASE 26
#define BEGIN 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
    struct Node *fail, *father;
} Node;

Node *getNewNode(Node *father) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->father = father;
    return p;
}

void insert(Node *root, const char *str) {
    Node *p = root;
    Node *father = root;
    for(int i = 0; str[i]; i++) {
        if(p->next[str[i] - BEGIN] == NULL) {
            p->next[str[i] - BEGIN] = getNewNode(father);
        }
        p = p->next[str[i] - BEGIN];
    }
    p->flag = 1;
    return;
}

void build_ac(Node *node) {
    if(node == NULL) return;
    //当前节点是根节点的失败指针为空，建立根节点的父节点，为空，被上一行判断过滤
    if(node->fail == NULL) build_ac(node->father);
    //先把所有节点走一遍
    for(int i = 0; i < BASE; i++) {
        //确定当前节点所有子节点的失败指针
        if(node->next[i] == NULL) continue;
        //失败指针已经确认过了，不需要再确认
        if(node->next[i]->fail) continue;
        Node *p = node->fail, *pre_p = node;
        while(p && p->next[i] == NULL) {
            //顺着失败指针找上去
            if(p->fail == NULL) build_ac(p->father);
            pre_p = p;
            p = p->fail;
        }
        //当p节点是空时,pre_p指向的是根节点
        if(p == NULL) p = pre_p;
        else p = p->next[i];
        node->next[i]->fail = p;
        build_ac(node->next[i]);
    }
    return ;
}

void clear(Node *node) {
    if(node == NULL) return ;
    for(int i = 0; i < BASE; i++) clear(node->next[i]);
    free(node);
    return ;
}

int main() {
    Node *father = NULL;
    Node *node = getNewNode(father);
    return 0;
}

