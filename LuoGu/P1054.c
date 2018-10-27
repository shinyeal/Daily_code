/*************************************************************************
> File Name: match.c
> Author: 
> Mail: 
> Created Time: 2018年10月21日 星期日 15时37分16秒
************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define INF 0x3f3f3f3f
#define MD 100000007

long long int qnf(long long int a, long long int b) {
    long long int ans = 1;
    for(int i = 1; i <= b; i++) {
        ans = ans * a % MD;
    }
    return ans;
}

long long int calc(char *str, int l, int r, int a_value) {
    long long int pos = -1, temp_prior = 0, prior = INF - 1;
    for(int i = l ;i <= r; i++) {
        long long int cur_prior = INF;
        switch(str[i]) {
            //运算优先级
            case '(': temp_prior += 100; break;
            case ')': temp_prior -= 100; break;
            case '+': cur_prior = temp_prior + 1; break;
            case '-': cur_prior = temp_prior + 1; break;
            case '*': cur_prior = temp_prior + 2; break;
            case '^': cur_prior = temp_prior + 3; break;
        }
        if(cur_prior <= prior) {
            prior = cur_prior;
            pos = i;
        }
    }
    if(pos == -1) {
        int num = 0;
        for(int i = l; i <= r; i++) {
            if(str[i] == 'a') return a_value;
            if(str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] -'0';
        }
        return num;
    } else {
        long long int a = calc(str, l, pos - 1, a_value);
        long long int b = calc(str, pos + 1, r, a_value);
        switch(str[pos]) {
            case '+': return (a + b) % MD;
            case '-': return (a - b) % MD;
            case '*': return (a * b) % MD;
            case '^': return qnf(a, b);
        }
    }
    return 0;
}


int main() {
    srand(time(0));
    int seed = rand() % 101;
    //printf("%d\n", seed);
    char str[1000];
    scanf("%[^\n]s", str);
    getchar();
    int num = calc(str, 0, strlen(str) - 1, seed);
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        scanf("%[^\n]s", str);
        getchar();
        //printf("%s = %d\n", str, calc(str, 0, strlen(str) - 1, seed));
        if(calc(str, 0, strlen(str) - 1, seed) == num) {
            printf("%c", i + 65);
        }
    }
    printf("\n");
    return 0;
}

/*
int main() {
    char str[1000];
    while(scanf("%[^\n]s", str) != EOF) {
        getchar();
        printf("%s = %d\n", str, calc(str, 0, strlen(str) - 1, 3));
    }
    return 0;
}
*/

