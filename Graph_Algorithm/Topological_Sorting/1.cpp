/*
 * Topologic Algorithm using in-degree of vertices.
 */

#include <bits/stdc++.h>

using namespace std;

struct Vertex{
    int in, out;
};


struct Graph{
    int V;
    Vertex* vet = new Vertex[V];
    list<int> *adj;
};

struct Graph* create_graph(int V){
    struct Graph *graph;
    graph->V = V;
    graph->vet = new Vertex[V];
    for (int i = 0; i < V; ++i) {
        graph->vet[i].in = graph->vet[i].out = 0;
    }
    graph->adj = new list<int>[V];
};


void dfs(Graph* graph, vector<int>& res, bool *vis, int cur){
    list<int>::iterator it;
    if(!vis[cur])
    for(it = graph->adj[cur].begin(); it != graph->adj[cur].end(); ++it){
        int t = *it;
        if(graph->vet[t].in == 1 && graph->vet[t].out == 1 && !vis[t]){
            vis[t] = 1;
            dfs(graph, res, vis, t);
            res.push_back(t);
        } else if(!vis[t]) {
            res.push_back(t);
            vis[t] = 1;
        }
    }
    return;
}

/* You need to complete this function */
int * topoSort(vector<int> a[], int N)
{
    // Your code here
    vector<int>::iterator it;
    struct Graph* graph = create_graph(N);
    for (int i = 0; i < N; i ++) {
        for (it = a[i].begin(); it != a[i].end(); ++ it) {
            int s = i;
            int d = *it;
            graph->adj[s].push_back(d);
            graph->vet[s].out ++;
            graph->vet[d].in ++;
        }
    }
    queue<int>que;
    vector<int>res;
    res.clear();
    bool vis[N] = {0};
    while (!que.empty())que.pop();
    for(int i = 0; i < N; ++i){
        if(graph->vet[i].in == 0){
            vis[i] = 1;
            que.push(i);
        }
    }
    while (!que.empty()){
        int s = que.front();
        que.pop();
        res.push_back(s);
        vis[s] = 1;
        for (int i = 0; i < a[s].size(); ++i) {
            int d = a[s][i];
            if(!vis[d]){
                if(graph->vet[d].in == 1 && graph->vet[d].out == 1){
                    res.push_back(d);
                    dfs(graph, res, vis, d);
                    graph->vet[d].in --;
                    vis[d];
                }
                else {
                    que.push(d);
                }
                vis[d] = 1;
            }
        }
    }
    int *ret = new int[N];
    for (int i = 0; i < N; ++i) {
        *(ret + i) = res[i];
    }
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    cout << res.size() << endl;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--){
        int E, N, x, y;
        cin >> E >> N;
        vector<int> v[N];
        for(int i = 0; i < N; ++i){
            vector<int> t;
            t.clear();
            v[i].clear();
        }
        for(int i = 0; i < E * 2; i += 2){
            cin >> x >> y;
            cout<< x << y << endl;
            v[x].push_back(y);
        }
        cout << E << " "  << v[0].size() << endl;
        int *res = topoSort(v, N);
        for (int i = 0; i < N; ++i) {
            cout << *(res + i) << " ";
        }
        cout << '\n';
    }
    return 0;
}
