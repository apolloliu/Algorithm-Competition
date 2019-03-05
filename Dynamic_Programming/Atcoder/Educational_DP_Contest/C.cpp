
//C - Vacation
//
#include <bits/stdc++.h>

using namespace std;

const int maxn = 123456;
int dp[maxn][3], h[maxn][3];
const int inf = 0x7f7f7f7f;
int main(){
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> h[i][0] >> h[i][1] >> h[i][2];
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n ; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = j + 1; k <= j + 2; ++k){
                dp[i][j] = max(dp[i][j], h[i-1][k%3] + dp[i-1][k%3]);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 3; ++i)res = max(dp[n][i], res);
    cout << res << endl;
    return 0;
}
