/*************************************************************************
   > File Name: 22.red_black_tree.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 五 10/12 18:15:30 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct RBNode {
    int key, color; // 0 red, 1 black, 2 double black
    struct RBNode *lchild, *rchild;
} RBNode;

RBNode *NIL;

RBNode *getNewNode(int key) {
    RBNode *p = (RBNode *)malloc(sizeof(RBNode));
    p->key = key;
    p->color = 0;
    p->lchild = p->rchild = NIL;
    return p;
}

__attribute__((constructor)) void init_NIL() {
    NIL = getNewNode(0);
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

int hasRedChild(RBNode *node) {
    return node->lchild->color == 0 || node->rchild->color == 0;
}

RBNode *left_rotate(RBNode *node) {
    RBNode *temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    return temp;
}

RBNode *right_rotate(RBNode *node) {
    RBNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    return temp;
}

RBNode *insert_maintain(RBNode *root) {
    if (!hasRedChild(root)) return root;
    if (root->lchild->color == 0 && root->rchild->color == 0) {
        if (hasRedChild(root->lchild) || hasRedChild(root->rchild)) {
            root->color = 0;
            root->rchild->color = root->lchild->color = 1;
        }
        return root;
    }
    if (root->lchild->color == 0) {
        if (!hasRedChild(root->lchild)) return root;
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!hasRedChild(root->rchild)) return root;
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    root->color = 0;
    root->lchild->color = root->rchild->color = 1;
    return root;
}

RBNode *__insert(RBNode *root, int key) {
    if (root == NIL || root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = __insert(root->rchild, key);
    else root->lchild = __insert(root->lchild, key);
    return insert_maintain(root);
}

RBNode *insert(RBNode *root, int key) {
    root = __insert(root, key);
    root->color = 1;
    return root;
}

RBNode *predecessor(RBNode *node) {
    RBNode *temp = node->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

RBNode *erase_maintain(RBNode *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    //兄弟节点是红色，转一次，让兄弟节点的颜色变成黑色
    if (root->lchild->color == 0 || root->rchild->color == 0) {
        root->color = 0;
        if (root->lchild->color == 0) {
            root->lchild->color = 1;
            root = right_rotate(root);
            root->rchild = erase_maintain(root->rchild);
        } else {
            root->rchild->color = 1;
            root = left_rotate(root);
            root->lchild = erase_maintain(root->lchild);
        }
        return root;
    }
    
    //兄弟节点是黑色
    //兄弟节点在右，
    if (root->lchild->color == 2) {   //双重黑在左
        if (!hasRedChild(root->rchild)) {  //兄弟节点的子节点都是黑色
            root->color += 1;
            root->lchild->color = 1;
            root->rchild->color = 0;
            return root;
        } else if (root->rchild->rchild->color != 0) { //兄弟节点的右节点是黑色（代表左节点是红色）
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = 1;
            root->rchild->rchild->color = 0;
        }
        root->lchild->color = 1;
        root = left_rotate(root);
        root->color = root->lchild->color;
        root->lchild->color = root->rchild->color = 1;
    //兄弟节点在左
    } else {
        if (!hasRedChild(root->lchild)) {
            root->color += 1;
            root->rchild->color = 1;
            root->lchild->color = 0;
            return root;
        } else if (root->lchild->lchild->color != 0) {
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = 1;
            root->lchild->lchild->color = 0;
        }
        root->rchild->color = 1;
        root = right_rotate(root);
        root->color = root->rchild->color;
        root->lchild->color = root->rchild->color = 1;
    }
    //
    return root;
}

RBNode *__erase(RBNode *root, int key) {
    
    if (root == NULL || root == NIL) return NIL;
    if (root->key < key) root->rchild = __erase(root->rchild, key);
    else if (root->key > key) root->lchild = __erase(root->lchild, key);
    else {
        //0
        if (root->lchild == NIL && root->rchild == NIL) {
            NIL->color += root->color;
            free(root);
            return NIL;
        //1
        } else if (root->lchild == NIL || root->rchild == NIL) {
            RBNode *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        //2
        } else {
            RBNode *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

RBNode *erase(RBNode *root, int key) {
    root = __erase(root, key);
    root->color = 1;
    return root;
}

void clear(RBNode *root) {
    if (root == NIL || root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(RBNode *root) {
    if (root == NIL) return ;
    printf("(%d | %d, %d, %d)\n", root->color, root->key, root->lchild->key, root->rchild->key);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, value;
    RBNode *root = NIL;
    while (scanf("%d%d", &op, &value) != EOF) {
        switch (op) {
            case 0:
                printf("\ninsert %d\n", value);
                root = insert(root, value); break;
            case 1:
                printf("\ndelete %d\n", value);
                root = erase(root, value); break;
            default: printf("error\n");
        }
        printf("----------\n");
        output(root);
    }
    return 0;
}

