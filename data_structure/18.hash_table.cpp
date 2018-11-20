/*************************************************************************
	> File Name: 18.hash_table.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月06日 星期二 20时44分49秒
 ************************************************************************/

//哈希表
//往哈希表存储字符串

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    //链表头地址数组
    Node **data;
    int size;
} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    //strdup：申请一片新的存储空间，并将str的内容拷贝到存储空间，他返回的是新的存储空间的地址
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    //通常要把哈希表的大小开的大一点：通常是2倍
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    //每次初始化存储的位置都是空，用calloc
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

//哈希函数是根据问题场景设计的
//APHash  ZobristHash   ？
//seed 为什么是31   ？

//字符串哈希的函数
int BKDRhash(char *str) {
    int seed = 31, hash = 0;
    for(int i = 0; str[i]; i++) hash = hash *seed +str[i];
    //& 0x7fffffff: 保证返回的是一个正值
    return hash & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    //先获得一个哈希值
    int hash = BKDRhash(str);
    //把哈希值转化为数组下标
    int ind = hash % h->size;

    //拉链法的头插法
    h->data[ind] = init_node(str, h->data[ind]);
    
/*
    //开放定值法
    int times = 0;
    Node *node = init_node(str, NULL);
    //如果哈希表当前节点被占用了
    while(h->data[ind]) {
        //坐标重映射
        times++;
        //二次试探法
        ind += times * times;
        ind %= h->size;
    }
    h->data[ind] = node;
*/
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDRhash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while(p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

void clear_node(Node *node) {
    if(node == NULL) return ;
    Node *p = node, *q;
    while(p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if(h == NULL) return ;
    for(int i = 0; i < h->size; i++) clear_node(h->data[i]);
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    HashTable *h = init_hashtable(100);
    char str[100];
    while(scanf("%d%s", &op, str) != EOF) {
        switch(op) {
            case 0: {
                //插入
                printf("insert %s to hash table\n", str);
                insert(h, str);
            } break;
            case 1: {
                //查找
                printf("search %s result = %d\n", str, search(h, str));
            } break;
        }
    }
    return 0;
}
