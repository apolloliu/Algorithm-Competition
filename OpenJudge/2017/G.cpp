// G - 鸡蛋的硬度
// 动态规划例题，dp[i][k] 表示到第i层扔第k个鸡蛋时最多扔鸡蛋的次数
// 题目要求的是1 <= x <= n层里最优的情况
// 当处在第i层时（此时用了k个鸡蛋），假如在该层碎了，则从前i-1层继续找（用k-1个鸡蛋），如果没碎则从剩下的n-i层来找（还是k个鸡蛋）
// 所以状态转移方程为：dp[i][k] = min(dp[i][k], max(dp[i-1][k-1], dp[n-i][k])); 注意鸡蛋要从2个开始，因为1个鸡蛋不改变最坏情况
// http://noi.openjudge.cn/ch0206/7627/

#include <bits/stdc++.h>
 
using namespace std;
 
int t[110], v[110];
int dp[110][110]; 
 
int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n, m;
    while(cin >> n >> m){
        memset(dp, 0, sizeof(dp));
        // dp[i][k] is the minimum of maximum times of throwing eggs
        // keep in mind that i is the current layer number, k is the number of eggs to be used
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; ++j)
                dp[i][j] = i;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                for(int k = 2; k <= m; ++k){ // Note: start from 2 eggs
                    int cnt = max(dp[j-1][k-1], dp[i-j][k])+1;
                    dp[i][k] = min(dp[i][k], cnt);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
