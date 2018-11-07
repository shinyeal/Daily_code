/*************************************************************************
	> File Name: 14.clue_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月04日 星期日 11时22分46秒
 ************************************************************************/

//线索二叉树

#include <stdio.h>
#include <stdlib.h>
#define normal 0
#define thread 1


typedef struct Node {
    int key, ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *init(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    p->ltag = p->rtag = normal;
    return p;
}

Node *insert(Node *root, int key) {
    if(root == NULL) return init(key);
    if(root->key == key) return root;
    if(key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

void build(Node *root) {
    if(root == NULL) return ;
    static Node *pre = NULL;
    //访问前一个节点
    build(root->lchild);
    //建立当前节点的前驱节点
    if(root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = thread;
    }
    //建立当前节点前驱节点的后继节点
    if(pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = thread;
    } 
    pre = root;
    build(root->rchild);
    return ;
}

void output(Node *root) {
    int status = 1;
    Node *p = root;
    while(p) {
        switch(status) {
            case 1: {
                while(p->ltag == normal && p->lchild)
                    p = p->lchild;
                status = 2;
            } break;
            case 2: {
                printf("%d ", p->key);
                status = 3;
            } break;
            case 3: {
                if(p->rtag == normal) {
                    status = 1;
                    //p = p->rchild;
                } else {
                    status = 2;
                    //p = p->rchild;
                }
                //先状态转移后赋值
                p = p->rchild;
            } break;
        }
    }
    return ;
}

int clear(Node *root) {
    if(root == NULL) return 0;
    root->ltag == normal && clear(root->lchild);
    root->rtag == normal && clear(root->rchild);
    free(root);
    return 1;
}

int output_thread(Node *root) {
    if(root == NULL) return 0;
    printf("key : %d ", root->key);
    if(root->lchild) {
        printf("(ltag : %d, lchild : %d)", root->ltag, root->lchild->key);
    }
    if(root->rchild) {
        printf("(rtag : %d, rchild : %d)", root->rtag, root->rchild->key);
    }
    printf("\n");
    root->ltag == normal && output_thread(root->lchild);
    root->rtag == normal && output_thread(root->rchild);
    return 0;
}

int main() {
    int n;
    Node *root = NULL;
    while(scanf("%d", &n) != EOF) {
        root = insert(root, n);
    }
    build(root);
    output_thread(root);
    clear(root);
    return 0;
}
