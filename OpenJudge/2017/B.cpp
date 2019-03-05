// B - 高次同余方程求解
// http://chjsgl.openjudge.cn/practice/1040/
#include <stdio.h>
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
 
const ll inf = 1e15L;
const int maxn = 1010;
int a[1010]; 

int main(){
    // freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); 
    int k, n;
    scanf("%d%d", &k, &n);
    int t = 0;
    for(int i = 1; i < n; ++i){
        int cnt = 1LL;
        for(int j = 0; j < k; ++j){
            cnt = (cnt * i) % n;
        }
        if(cnt == 1LL)a[t++] = i;
    }
    for(int i = 0; i < t; ++i)printf("%d\n", a[i]);
    return 0;
}
