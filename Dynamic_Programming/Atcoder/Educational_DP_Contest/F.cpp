// F - LCS
// O(n * m)

#include <bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e15L;
const int maxn = 3030;
int dp[maxn][maxn];

int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string sa, sb;
    cin >> sa >> sb;
    int len_a = sa.size(), len_b = sb.size();
    memset(dp, 0, sizeof(dp));
    string s = "";
    vector<vector<int>>v(len_a+1, vector<int>(len_b+1, 0));

    for(int i = 0; i < len_a; ++i){
        for(int j = 0; j < len_b; ++j){
            if(sa[i] == sb[j]){
                dp[i+1][j+1] = dp[i][j] + 1; 
                v[i+1][j+1] = 1;
            }
            else{
                if(dp[i+1][j] > dp[i][j+1]){
                    dp[i+1][j+1] = dp[i+1][j]; 
                    v[i+1][j+1] = 2;
                }
                else {
                    dp[i+1][j+1] = dp[i][j+1];
                    v[i+1][j+1] = 3;
                }
            }
        }
    }
    
    int a = len_a, b = len_b;
    // cout << dp[len_a][len_b] << endl;
    while(a && b && dp[len_a][len_b]){
        if(v[a][b] == 1){
            a--; b--;
            s += sa[a];
        }
        else if(v[a][b] == 2){
            b--;
        }
        else {
            a--;
        }
    }

    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
