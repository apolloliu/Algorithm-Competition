
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
