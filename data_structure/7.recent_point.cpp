/*************************************************************************
	> File Name: 6.test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月23日 星期二 19时39分07秒
 ************************************************************************/

//最近公共祖先


#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000    //节点数
#define MAX_K 20

struct Edge {
    int v, n;
} g[MAX_N << 1];

int head[MAX_N + 5] = {0}, cnt = 0;
//添加a 指向b 的边
inline void add(int a, int b) {
    g[++cnt].v = b;
    g[cnt].n = head[a];
    head[a] = cnt;
    return ;
}

//gas[i][j] ->  i 点往上走 2^j 步， 所能到达的祖先节点的编号
int gas[MAX_N][MAX_K] = {0}, dep[MAX_N] = {0};
//为什么0节点不用 从1节点开始

//dfs:深搜
void dfs(int u, int father) {
    gas[u][0] = father;
    dep[u] = dep[father] + 1;
    for(int i = 1; i < MAX_K; i++) {
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
    }
    for(int i = head[u]; i; i = g[i].n) {
        if(g[i].v == father) continue;
        dfs(g[i].v, u);
    }
    return;
}

//lca：交换a, b两个节点的值(异或)
int lca(int a, int b) {
    if(dep[b] < dep[a]) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int l = dep[b] - dep[a];
    //对齐（倍增）1， 2， 4, 8
    for(int i = 0; i < MAX_K; i++) {
        if((l & (1 << i))) b = gas[b][i];
    }
    if(a == b) return a;
    //往上走
    for(int i = MAX_K - 1; i >= 0; i--) {
        if(gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[b][i];
    }
    return gas[a][0];
}


int main() {
    int n, a, b;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    //选哪个做根节点不影响路径
    dfs(1, 0);
    while(scanf("%d%d", &a, &b) != EOF) {
        //printf("lca(a, b) = %d, a -> b = %d\n", lca(a, b), dep[a] + dep[b] - 2 * dep[lca(a, b)]);
        printf("lca(%d, %d) = %d, a -> b = %d\n", a, b, lca(a, b), dep[a] + dep[b] - 2 * dep[lca(a, b)]);
    }
    return 0;
}
