/*************************************************************************
	> File Name: build_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月28日 星期日 18时19分05秒
 ************************************************************************/

//二叉树广义表

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

typedef struct Stack {
    Node **data;
    int top, size;
} Stack;

Stack *initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) *n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s == NULL || s->top == -1;
}

void pop(Stack *s) {
    if(empty(s)) return;
    s->top -= 1;
    return ;
}

Node *top(Stack *s) {
    if(empty(s)) return NULL;
    return s->data[s->top];
}

void push(Stack *s, Node *root) {
    if(s->top + 1 == s->size) return ;
    s->data[++(s->top)] = root;
    return ;
}

void clearStack(Stack *s) {
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

Node *getNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void clearTree(Node *root) {
    if(root == NULL) return ;
    clearTree(root->lchild);
    clearTree(root->rchild);
    free(root);
    return ;
}

Node *build(const char *str) {
    int k = 0;
    Node *p = NULL, *root = NULL;
    Stack *s = initStack(100);
    while(str[0]) {
        switch(str[0]) {
            case '(': {
                push(s, p);
                k = 0;
            } break;
            case ')': {
                pop(s);
            } break;
            case ',':{
                k = 1;
            }
            case ' ': break;
            default : {
                p = getNode(str[0]);
                if(root == NULL) root = p;
                if(empty(s)) break;
                if(k == 0) top(s)->lchild = p;
                else top(s)->rchild = p;
            } break;
        }
        str++;
    }
    return root;
}

void output(Node *root, const char *last_output) {
    if(root == NULL) return ;
    printf("%c", root->key);
    output(root->lchild, "");
    output(root->rchild, "");
    printf("%s", last_output);
    return ;
}

int main() {
    char str[100];
    Node *root = NULL;
    while(scanf("%[^\n]s", str) != EOF) {
        getchar();
        output(root = build(str), "\n");
        clearTree(root);
    }
    return 0;
}
