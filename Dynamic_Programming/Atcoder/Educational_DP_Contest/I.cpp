// I - Coins
// O(n^2)
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll inf = 1e15L;
const int maxn = 3010;
double p[maxn];
double dp[maxn][maxn];
 
int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    memset(p, 0, sizeof(p));
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1.;
    for (int i = 1; i <= n; ++i)
    {
         cin >> p[i];
         dp[i][0] = dp[i-1][0] * (1-p[i]);
         //dp[i][i] = dp[i-1][i-1] * p[i];  it doesn't matter whether setting these values
    }
    
    //dp[i][j] - i is the number of current coins, j is the number fo heads
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            dp[i][j] = p[i] * dp[i-1][j-1] + (1 - p[i]) * dp[i-1][j];
        }
    }
    double res = 0.;
    for (int head = 1; head <= n; ++head)
    {
        int tail = n - head;
        if(head > tail)res = res + dp[n][head];
    }
    cout << std::fixed << setprecision(10) << res << endl;
    return 0;
}
