// H - 拓扑排序
// http://bailian.openjudge.cn/practice/4084/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;
vector<int>res;
priority_queue<int, vector<int>, greater<int>>q;
vector<int>G[110];
int indeg[maxn];

void topo(){
    while(!q.empty()){
        int u = q.top();
        q.pop();
        res.push_back(u);
        for(auto v: G[u]){
            indeg[v]--;
            if(!indeg[v])q.push(v);
        }
    }
}
int main(){
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, n, x, y;
    cin >> v >> n;
    for(int i = 0; i <= v; ++i){
        G[i].clear();
    }
    res.clear();
    while(!q.empty())q.pop();
    memset(indeg, 0, sizeof(indeg));
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        G[x].push_back(y);
        indeg[y]++;
    }
    for(int i = 1; i <= v; ++i){
        if(!indeg[i])q.push(i);
    }
    topo();
    if(res.size() != v){cout << "Sandro fails." << endl; return 0;}
    int t = res.size();
    for(int r: res){
        cout << 'v' << r;
        if(t>=2){cout << " "; t--;}
    }
    cout << endl;
    return 0;
}
