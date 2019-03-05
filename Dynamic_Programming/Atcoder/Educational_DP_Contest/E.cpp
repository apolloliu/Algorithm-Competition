// E - Knapsack 2
// O(n * v)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1e15L;
const int maxn = 123456;
ll dp[maxn];
int w[110], v[110];

int main(){
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, W;
    cin >> n >> W;
    memset(dp, 0, sizeof(dp));
    int sum_value = 0;
    for(int i = 0; i < n; ++i){
        cin >> w[i] >> v[i];
        sum_value += v[i];
    }
    for(int i = 0; i <= sum_value; ++i)dp[i] = inf;
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = sum_value; j >= 0; --j){
            if(dp[j] + w[i] <= W)
            dp[j+v[i]] = min(dp[j+v[i]], dp[j]+w[i]);
        }
    }

    ll res = 0;
    for(int i = 1; i <= sum_value; ++i){
        if(dp[i] <= W)
        res = max(res, (ll)i);
    }
    cout << res << endl;
    return 0;
}
