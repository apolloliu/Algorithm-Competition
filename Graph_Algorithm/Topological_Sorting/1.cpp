/*
 * Topologic Algorithm using Kahn's Algorithm Time Complexity O(V + E)
 */

#include <bits/stdc++.h>

using namespace std;

struct Vertex{
    int in, out;
};

struct Graph{
    int V;
    Vertex* vet;
};

struct Graph* create_graph(int V){
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->vet = new Vertex[V];
    for (int i = 0; i < V; ++i) {
        graph->vet[i].in = graph->vet[i].out = 0;
    }
    return graph;
};


int *topoSort(vector<int> a[], int N)
{
    // Your code here
    vector<int>::iterator it;
    struct Graph* graph = create_graph(N);
    for (int i = 0; i < N; i ++) {
        for (it = a[i].begin(); it != a[i].end(); ++ it) {
            int s = i;
            int d = *it;
            graph->vet[s].out ++;
            graph->vet[d].in ++;
        }
    }
    queue<int>que;
    vector<int>res;
    res.clear();
    while (!que.empty())que.pop();
    for(int i = 0; i < N; ++i){
        if(graph->vet[i].in == 0){
            que.push(i);
        }
    }
    while (!que.empty()){
        int s = que.front();
        que.pop();
        res.push_back(s);
        for (it = a[s].begin(); it < a[s].end(); ++it) {
            int d = *it;
            graph->vet[d].in --;
            if(graph->vet[d].in == 0){
                que.push(d);
            }
        }
    }

    int *ret = new int[N];
    for (int i = 0; i < N; ++i) {
        *(ret + i) = res[i];
    }
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