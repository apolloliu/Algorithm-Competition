// G - Longest Path
// O(V)
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll inf = 1e15L;
const int maxn = 123456;
int indeg[maxn], vis[maxn];
std::vector<int> G[maxn];
set<pii>s;
int dist[maxn];
 
void topo(){
    while(!s.empty()){
        pii u = *(s.begin());
        // vis[u.fi] = 1;
        s.erase(s.begin());
        for(auto v: G[u.fi]){
            // if(!vis[v]){
                dist[v] = max(dist[v], dist[u.fi] + 1);
                indeg[v]--;
                if(!indeg[v])s.insert({v, u.se+1});
            // }
        }
    }
}
 
int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        G[i].clear();
    }
    s.clear();
    memset(dist, 0, sizeof(dist));
    memset(indeg, 0, sizeof(indeg));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        G[x].pb(y);
        indeg[y]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!indeg[i])s.insert({i, 0});
    }
    int res = 0;
    topo();
    for(int i = 1; i <= n; ++i)res = max(res, dist[i]);
    cout << res << endl;    
    return 0;
}
