// UVA 124 - Following Orders
// all toposort for a graph
#include <bits/stdc++.h>

using namespace std;

#define MEM(a,b)    memset(a, b, sizeof(a))
#define UN(a)       sort(all(a)), a.erase(unique(all(a)), a.end())
#define REV(a)      reverse(all(a))
#define MP(a, b)    make_pair(a, b)
#define PAIR(a, b)  pair<int, int>(a, b)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const int inf = 0x7f7f7f7f;
const int maxn = 123456;
const double EPS = 1e-8;

unordered_map<char, int>mp;
string ww;
void dfs(std::vector<int> G[], std::vector<int>& indeg, std::vector<int> s, std::vector<bool>& vis){
    bool flag = 1;
    for(int i = 0; i < indeg.size(); ++i){
        if(!indeg[i] && !vis[i]){
            vis[i] = 1;
            for(int v: G[i])indeg[v]--;
            s.push_back(i);
            dfs(G, indeg, s, vis);
            for(int v: G[i])indeg[v]++;
            s.erase(s.end()-1);
            vis[i] = 0;
            flag = 0;
        }
    }
    if(flag){
        string str = "";
        for(int x: s)str += ww[x];
        cout << str << '\n';
    }
}

void solve(std::vector<int> G[], std::vector<int> indeg){
    int n = mp.size();
    std::vector<int> s;
    assert(!s.size());
    std::vector<bool> vis(n, 0);
    dfs(G, indeg, s, vis);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[1010], word, a, b, c;
    // gets(s);
    int icase = 0;
    while(gets(s)){
        if(icase)cout << '\n';
        ww = "";
        mp.clear();
        char *t;
        int add;
        int cur = 0;
        string my_str = "";
        for (t = s; sscanf(t, "%1s%n", &word, &add) == 1; t += add) my_str += word;
        sort(my_str.begin(), my_str.end());
        for(char x : my_str)mp[x] = cur++, ww+=x;
        int n = mp.size();
        std::vector<int>G[n];
        std::vector<int>indeg(n, 0);
        for(int i = 0; i < n; ++i)G[i].clear();
        gets(s);
        cur = 1;
        for (t = s; ; t += add){
            if(sscanf(t, "%1s%n", &c, &add) != 1)break;
            if(cur%2==1){
                a = c;
            }
            else {
                b = c;
                int ia = mp[a], ib = mp[b];
                G[ia].push_back(ib);
                indeg[ib]++;
            }
            cur++;
        }
        solve(G, indeg);
        icase++;
    }
    return 0;
}
