/*
 * Print all Topologic sorts Time Complexity O(VE)
 */

#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> * adj;
    vector<int> indegree;
    void alltopologicalSortUtil(vector<int> &res, bool vis[]);
public:
    Graph(int V);
    void alltopoSort();
    void addEdge(int u, int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    for (int i = 0; i < V; ++i) {
        indegree.push_back(0);
    }
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    indegree[v]++;
}

// Main recusive function to print all topologic sorting
void Graph::alltopologicalSortUtil(vector<int> &res, bool *vis) {
    //Indicate whether all topologic sorts are found or not
    bool flag = 0;

    for(int i = 0; i < V; ++i){
        // If indegree is 0 and not yet visited then only choose that vertex
        if(!indegree[i] && !vis[i]){
            list<int>::iterator it;
            for (it = adj[i].begin(); it != adj[i].end(); ++it) {
                indegree[*it]--;
            }
            vis[i] = 1;
            res.push_back(i);
            alltopologicalSortUtil(res, vis);

            vis[i] = 0;
            res.erase(res.end() - 1);
            for (it = adj[i].begin(); it != adj[i].end(); ++ it) {
                indegree[*it]--;
            }

            flag = 1;
        }
    }

    // We reach here that all vertices are visited. Print all solutions here.
    if(!flag){
        for(int i = 0; i < res.size(); ++i){
            cout << res[i] << " ";
        }
        cout << '\n';
    }
}

void Graph::alltopoSort() {
    bool *vis = new bool[V];
    memset(vis, 0, sizeof(vis));
    vector<int>res;
    res.clear();
    alltopologicalSortUtil(res, vis);
}


int main(){
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--){
        int E, V, u, v;
        cin >> V >> E;
        Graph graph(V);
        for(int i = 0; i < e; ++i){
            cin >> u >> v;
            graph.addEdge(u, v);
        }
        graph.alltopoSort();
    }
    return 0;
}