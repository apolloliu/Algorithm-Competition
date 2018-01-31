/*
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

