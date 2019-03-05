// E - 我爱学习！
// http://chjsgl.openjudge.cn/practice/1043/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char s[22][22]; 
char c[110];

void check(int n, int l){
    int size_a = strlen(s[n]);
    int size_b = strlen(c) - l;
    if(size_a > size_b)return ;
    bool flag = true;
    for(int i = 0; i < size_a; ++i)if(s[n][i] != c[i+l])flag = false;
    if(flag){
        for(int i = 0; i < size_a; ++i)c[l+i] = '*';
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); 
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 0; i < n; ++i)scanf("%s", s[i]);
    getchar();
    for(int i = 0; i < m; ++i){
        gets(c);
        for(int j = 0; j < n; ++j){
        for(int k = 0; k < strlen(c); ++k){
            if(c[k] == ' ' || c[k] == '*')continue;
            
                check(j, k);
            }
        }
        puts(c);
    }
    return 0;
}
