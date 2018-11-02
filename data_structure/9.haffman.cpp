/*************************************************************************
	> File Name: haffman.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 10/28 20:02:20 2018
 ************************************************************************/

//二叉树哈弗曼树

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

//freq,节点的总次数；

typedef struct Node {
    int key, freq;
    struct Node *lchild, *rchild;
}Node;

Node *getNewNode(int key, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild =NULL;
    return p;
}

void clear(Node *root){
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

//交换值
void swap_node(Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return ;
}

Node *build_haffman(Node **arr, int n) {
    //合并n-1次，将频次最小的放入末尾；
   // Node INIT_NODE = {0, INT32_MAX, NULL, NULL};
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 2; j++) {
            if (arr[j]->freq < arr[n - i - 1]->freq) {
                swap_node(arr + j, arr + n - i - 1);
            } 
            if (arr[j]->freq < arr[n - i - 2]->freq) {
                swap_node(arr + j, arr + n - i - 2);
            }
            if(arr[n - i - 1]->freq > arr[n - i - 2]->freq) {
                swap_node(arr - n - i - 1, arr - n - i - 2);
            }
        }
        printf("first: ->%d, second:->%d\n", arr[n - i - 1]->freq,  arr[n - i - 2]->freq);
        Node *temp = getNewNode(0, arr[n - i - 1]->freq + arr[n - i - 2]->freq);
        temp->lchild = arr[n - i - 1];
        temp->rchild = arr[n - i - 2];
        arr[n - i - 2] = temp;
    }
    return arr[0];
}

//提取编码
void extract_code(Node *root, char (*code)[20], int k, char *buff) {
    buff[k] = 0;
    if (root->key) {
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0';
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff);
}

int main() {
    int n;
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    scanf("%d", &n);
    //初始化数组
    for (int i = 0; i < n; i++) {
        char key[10];
        int freq;
        scanf("%s%d", key, &freq);
        arr[i] = getNewNode(key[0], freq);
    }
    root = build_haffman(arr, n);
    char code[256][20] = {0}, buff[20];
    //提取编码
    //第i层编码对应第i位
    extract_code(root, code, 0, buff);
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0) continue;
        printf("%c : %s\n", i, code[i]);
    }
    return 0;
}
