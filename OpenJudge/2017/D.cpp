// D - BLACK JACK
// http://chjsgl.openjudge.cn/practice/1044/

// hack 神数据：
// 3
// 10
// A
// A
// 2
// 10
// 5

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
const int inf = 0x7f7f7f7f;
const int maxn = 1010;

int check(char c[]){
    if(c[0] == 'J' || c[0] == 'Q' || c[0] == 'K' || c[0] == '1')return 10;
    return (int)c[0] - '0';
}

int vis[1110];

int haha(int t, int sum, int num){
    if(!t){
        if(sum == 21)return inf;
        return sum;
    }
    if(t == 1 && sum == 10 && num == 2)return inf + 1;
    memset(vis, 0, sizeof(vis));
    vis[sum] = true;
    for(int i = 0; i < t; ++i){
        for(int j = 110; j >= 0; --j){
            if(vis[j])vis[j+11]++, vis[j+1] ++, vis[j]--;
        }
    }
    if(vis[21])return inf;
     for(int i = 21; i >= 0; --i)if(vis[i])return i;
    for(int i = 110; i >= 0; --i)if(vis[i])return i;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); 
    int n, m;
    char c[15];
    scanf("%d", &n);
    int sum1 = 0, sum2 = 0, Aa = 0, Ab = 0;
    for(int i = 0; i < n; ++i){scanf("%s", c); if(c[0] != 'A')sum1 += check(c); else Aa ++;}
    scanf("%d", &m);
    for(int i = 0; i < m; ++i){scanf("%s", c); if(c[0] != 'A')sum2 += check(c); else Ab ++;}
    if(sum2 + Ab > 21){puts("win"); return 0;}
    if(sum1 + Aa > 21){puts("lose"); return 0;}
    sum1 = haha(Aa, sum1, n);
    sum2 = haha(Ab, sum2, m);
    // printf("%d %d\n", sum1, sum2);
    if(sum1 > sum2)printf("win\n");
    else if(sum1 == sum2)printf("draw\n");
    else printf("lose\n");
    return 0;
}
