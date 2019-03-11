// HDU 3578 Greedy Tino
// Difficulty level: Medium

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ipii;
const int inf = 0x7f7f7f7f;
const int maxn = 4010;
#define OFFSIZE 2000

int a[110];
int dp[110][4010];

void max_self(int &a, int b){
    a = max(a, b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin >> T;
    for (int icase = 1; icase <= T; ++icase)
    {
        cin >> n;
        int sum = 0;
        // flag is to check whether there is a '0' in the array
        // if so, it can satisfy the requirement
        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
            if(!a[i])flag = true;
        }
        for(int j = 0; j <= n; ++j)
        for (int i = -sum; i <= sum; ++i)
        {
            dp[j][i+OFFSIZE] = -inf;
        }
        dp[0][OFFSIZE] = 0;

        // dp[i+1][j] = max(dp[i][j+a[i]], dp[i][j-a[i]], dp[i][j])
        for (int i = 0; i < n; ++i)
        {
            for (int j = -sum; j <= sum; ++j)
            {
                if(dp[i][j+OFFSIZE] != inf)
                max_self(dp[i+1][j+OFFSIZE], dp[i][j+OFFSIZE]);
                if(j+a[i]+OFFSIZE < maxn && dp[i][j+a[i]+OFFSIZE] != inf)
                max_self(dp[i+1][j+OFFSIZE], dp[i][j+a[i]+OFFSIZE] + a[i]);
                if(j-a[i]+OFFSIZE>=0 && dp[i][j-a[i]+OFFSIZE] != inf)
                max_self(dp[i+1][j+OFFSIZE], dp[i][j-a[i]+OFFSIZE] + a[i]);
            }
        }
        cout << "Case " << icase << ": ";
        if(flag || dp[n][OFFSIZE])
            cout << dp[n][OFFSIZE]/2 << endl;
        else cout << -1 << endl;
    }
    return 0;
}
