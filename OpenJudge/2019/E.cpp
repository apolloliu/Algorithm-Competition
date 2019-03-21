// E - The Suspects
// http://bailian.openjudge.cn/practice/1611/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 30000 + 10;
int pa[maxn];

int findset(int x){
    return pa[x] = pa[x] == x ? x : findset(pa[x]);
}

int main(int argc, char const *argv[]){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, x;
    while(cin >> n >> m, n || m){
        std::vector<int> v;
        for(int i = 0; i < n; ++i)pa[i] = i;
        for(int i = 0; i < m; ++i){
            cin >> k;
            v.clear();
            for(int j = 0; j < k; ++j){
                cin >> x;
                v.push_back(x);
            }
            sort(v.begin(), v.end());
            if(v.size()>=2){
                int fa = findset(v[0]);
                for(int j = 1; j < v.size(); ++j){
                    int y = findset(v[j]);
                    pa[y] = fa;
                }
            }
        }
        int res = 0;
        // find_set(a) == find_set(b) - checking whether they are in the same set
        for(int i = 0; i < n; ++i)if(findset(i) == findset(0))res ++;
        cout << res << '\n';
    }
    return 0;
}
