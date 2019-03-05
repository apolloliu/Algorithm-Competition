// H - Grid 1
// O(n * m)
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;

const int M=1010;
const ll mod = 1e9L + 7;

char a[M][M];
ll dp[M][M];
int n, m;
void move(ll& a, ll b){
    a = (a + b) % mod;
}

int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    dp[1][1] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int x = i - 1, y = i - 1;
            if(a[i-1][j-1] == '#')continue;
            move(dp[i][j], dp[i-1][j]);
            move(dp[i][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << endl;
} 
