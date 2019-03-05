//D - Knapsack 1

//Solution 1:
// O(n * W)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 123456;
ll dp[110][maxn];
int w[110], v[110];
const int inf = 0x7f7f7f7f;
int main(){
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, W;
    cin >> n >> W;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= W; ++j){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(w[i] + j <= W){
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i <= W; ++i){
        res = max(res, dp[n][i]);
    }
    cout << res << endl;
    return 0;
}


// Solution 2:
// O(n * W)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 123456;
ll dp[maxn];
int w[110], v[110];
const int inf = 0x7f7f7f7f;
int main(){
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, W;
    cin >> n >> W;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = W; j >= 0; --j){
            if(w[i] + j <= W){
                dp[j+w[i]] = max(dp[j+w[i]], dp[j] + v[i]);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i <= W; ++i){
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}

