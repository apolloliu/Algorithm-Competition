// http://noi.openjudge.cn/ch0206/7627/
// O(n*n*m)
// : Medium
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll inf = 1e15L;
const int maxn = 1010;
int t[110], v[110];
int dp[110][110]; 
 
int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n, m;
    while(cin >> n >> m){
        memset(dp, 0, sizeof(dp));
        // dp[i][j] is the minimum of maximum times of throwing eggs
        // keep in mind that i is the current layer number, j is the number of eggs to be used
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; ++j)
                dp[i][j] = i;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                for(int k = 2; k <= m; ++k){
                    int cnt = max(dp[j-1][k-1], dp[i-j][k])+1;
                    dp[i][k] = min(dp[i][k], cnt);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
