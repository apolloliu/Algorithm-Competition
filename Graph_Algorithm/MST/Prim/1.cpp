
/*
Prim's MST using priority queue
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class Graph{
    int V,E;
public:
    Graph(int V, int E);
    vector<pii> adj[1234];
    void addEdge(int u, int v, int w);
};

Graph::Graph(int V, int E) {
    //adj = new vector<pii>[V];
    for(int i = 0; i < V; ++i){
        adj[i].clear();
        adj[i].push_back(pii(i, INT_MAX));
    }
    this->V = V;
    this->E = E;
}

//indirect graph
void Graph::addEdge(int u, int v, int w) {
    adj[v].push_back(pii(u, w));
    adj[u].push_back(pii(v, w));
}

int spanningTree(vector<pair<int, int>> g[], int V) {
    set<int>s;
    s.clear();
    s.insert(1);
    vector<pii>::iterator it;
    priority_queue<pii, vector<pii>, greater<pii> >p;
    while (!p.empty()){
        p.pop();
    }
    for(it = g[1].begin(); it != g[1].end(); ++it){
        p.push(pii(it->second, it->first));
    }
    int res = 0;
    while (!p.empty()){
        int v = p.top().second, w = p.top().first;
        if(s.find(v) != s.end()){p.pop(); continue;}
        s.insert(v);
        p.pop();
        res += w;
        if(s.size() == V)break;
        for(it = g[v].begin(); it != g[v].end(); ++it){
            p.push(pii(it->second, it->first));
        }
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--){
        int E, N, u, v, w;
        cin >> N >> E;
        Graph graph(N, E);
        for(int i = 0; i < E; ++i){
            cin >> u >> v >> w;
            graph.addEdge(u, v, w);
        }
        cout << spanningTree(graph.adj, N) << endl;
    }
    return 0;
}
 * DFS and Stack
 */
#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    int * topoSort(vector<int> a[], int N);
    Graph(int V);
    void add_edge(int u, int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void dfs(vector<int> a[], bool *vis, int cur, stack<int>&s){
    if(!vis[cur]){
        vis[cur] = 1;
        for(vector<int>::iterator it = a[cur].begin(); it != a[cur].end(); ++it){
            if(!vis[*it]){
                dfs(a, vis, *it, s);
            }
        }
    }
    s.push(cur);
}

int* Graph::topoSort(vector<int> *a, int N) {
    stack<int> Stack;
    bool vis[N] = {0};
    for (int i = 0; i < N; ++i) {
        if(!vis[i]){
            dfs(a, vis, i, Stack);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    bool flag = 1;
    int l, r, d;

    for(int i = 0; i < n; ++i){

        if(!dfs(i)){cout << "No" << endl; return 0;}
    }
    cout << "Yes" << endl;
    return 0;
}

