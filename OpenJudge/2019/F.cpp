// D - Stockbroker Grapevine
// http://bailian.openjudge.cn/practice/1125?lang=en_US
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int G[110][110];
const int inf = 0x7f7f7f7f;

int main(int argc, char const *argv[]){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, val, y;
    while(cin>>n && n){
        for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)G[i][j] = inf;
        for(int i = 1; i <= n; ++i)G[i][i] = 0;
        std::vector<pii> v;
        v.clear();
        for(int i = 1; i <= n; ++i){
            cin >> m;
            for(int j = 0; j < m; ++j){
                cin >> y >> val;
                G[i][y] = val;
            }
        }
        for(int k = 1; k <= n; ++k){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    if(G[i][k] != inf && G[k][j] != inf)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            int sum = 0, mm = 0;
            for(int j = 1; j <= n; ++j){
                if(G[i][j] != inf){
                    mm = max(mm, G[i][j]);
                    sum++;
                }
            }
            if(sum == n){
                v.push_back({mm, i});
            }
        }
        if(v.size()){
            sort(v.begin(), v.end());
            cout << v[0].second << " " << v[0].first << endl;
        }
        else cout << "disjoint" << endl;
    }
    return 0;
}
