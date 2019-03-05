//A - Frog 1
//
#include <bits/stdc++.h>

using namespace std;

int dp[123456], a[123456];
const int inf = 0x7f7f7f7f;
int main(){
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i)dp[i] = inf;
    dp[0] = 0;
    for(int i = 0; i < n ; ++i){
        for(int j: {i+1, i+2}){
            if(j < n)
            dp[j] = min(dp[j], dp[i]+abs(a[i]-a[j]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}
