#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
//#include <unordered_map>
////#include <unordered_set>
//using namespace std;
//
//#define FOR(i,a,b)  for(int i = a; i < b; ++i)
//#define FORR(i,a,b) for(int i = a; i <= b; ++i)
////#define LOCAL_DEFINE
//using namespace std;
//
//#define maxn 1234
//double dist[maxn];
//map<string, int>mp;
//struct Edge {
//    int src, dest;
//        double weight;
//        };
//
//        struct Graph {
//            int V, E;
//                struct Edge* edge;
//                };
//
//                struct Graph* createGraph(int V, int E){
//                    struct Graph* graph = new Graph;
//                        graph->V = V;
//                            graph->E = E;
//                                graph->edge = new Edge[E];
//                                    return graph;
//                                    };
//
//                                    bool flag;
//
//                                    bool BellmanFord(Graph* graph, int src){
//                                        for (int i = 0; i <= graph->V - 1; ++i) {
//                                                for (int j = 0; j < graph->E; ++j) {
//                                                            if(dist[graph->edge[j].src] * graph->edge[j].weight > dist[graph->edge[j].dest])
//                                                                            dist[graph->edge[j].dest] = dist[graph->edge[j].src] * graph->edge[j].weight;
//                                                                                    }
//                                                                                        }
//                                                                                            for (int j = 0; j < graph->E; ++j) {
//                                                                                                    if(dist[graph->edge[j].src] * graph->edge[j].weight > dist[graph->edge[j].dest])
//                                                                                                                //cout << "exist negative weight cycle" <<endl;
//                                                                                                                            return true;
//                                                                                                                                }
//                                                                                                                                    return false;
//                                                                                                                                    }
//
//
//                                                                                                                                    int main() {
//                                                                                                                                        ios_base::sync_with_stdio(false);
//                                                                                                                                            //cin.precision(10);
//                                                                                                                                                //cout << fixed;
//
//                                                                                                                                                #ifdef LOCAL_DEFINE
//                                                                                                                                                    freopen("input.txt", "r", stdin);
//                                                                                                                                                    #endif
//
//                                                                                                                                                        int n, m;
//                                                                                                                                                            double x;
//                                                                                                                                                                int t = 1;
//                                                                                                                                                                    while (cin >> n && n) {
//                                                                                                                                                                            mp.clear();
//                                                                                                                                                                                    string co;
//                                                                                                                                                                                            vector<string>s;
//                                                                                                                                                                                                    for (int i = 0; i < n; ++i) {
//                                                                                                                                                                                                                cin >> co;
//                                                                                                                                                                                                                            mp[co] = i;
//                                                                                                                                                                                                                                    }
//                                                                                                                                                                                                                                            cin >> m;
//                                                                                                                                                                                                                                                    string a, b;
//                                                                                                                                                                                                                                                            Graph* graph = createGraph(n, m);
//                                                                                                                                                                                                                                                                    int id = 0;
//                                                                                                                                                                                                                                                                            while (id < m){
//                                                                                                                                                                                                                                                                                        cin >> a >> x >> b;
//                                                                                                                                                                                                                                                                                                    graph->edge[id].src =  mp[a];
//                                                                                                                                                                                                                                                                                                                graph->edge[id].dest = mp[b];
//                                                                                                                                                                                                                                                                                                                            graph->edge[id++].weight = x;
//                                                                                                                                                                                                                                                                                                                                    }
//                                                                                                                                                                                                                                                                                                                                            flag = 0;
//                                                                                                                                                                                                                                                                                                                                                    for (int i = 0; i < n; ++i) {
//                                                                                                                                                                                                                                                                                                                                                                for (int i = 0; i < n; ++i) {
//                                                                                                                                                                                                                                                                                                                                                                                dist[i] = 0.;
//                                                                                                                                                                                                                                                                                                                                                                                            }
//                                                                                                                                                                                                                                                                                                                                                                                                        dist[i] = 1.0;
//                                                                                                                                                                                                                                                                                                                                                                                                                    if(BellmanFord(graph, i)){
//                                                                                                                                                                                                                                                                                                                                                                                                                                    flag = 1; break;
//                                                                                                                                                                                                                                                                                                                                                                                                                                                }
//                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                //for(int i = 0; i < n; ++i){
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                        //    if(dist[i] > 1.0){
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                //        flag = 1;
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        //        break;
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                //    }
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        //}
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if(flag)printf("Case %d: Yes\n", t);
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        else printf("Case %d: No\n", t);
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                t++;
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    }
//
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        return 0;
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
