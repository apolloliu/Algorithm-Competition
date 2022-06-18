#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int inf = 1e9;
const int N = 12345, M = 2 * N;

// map<pii, int>v;
int h[M], w[M], e[M], ne[M], idx;
ll res;

void add(int a, int b, int c) {
    w[idx] = c, e[idx] = b; ne[idx] = h[a], h[a] = idx++;
}


int dfs(int x, int fa) {
    
    ll m1, m2;
    // 最坏情况只有一个点，直径为0
    m1 = m2 = -inf;
    
    for(auto i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if(j != fa) {
            int d = dfs(j, x) + w[i];
            if(d >= m1) {
                m2 = m1;
                m1 = d;
            }
            else if(d > m2) {
                m2 = d;
            }
        }
    }

    if(m1 == -inf)m1 = 0;
    if(m2 == -inf)m2 = 0;

    res = max(res, m1 + m2);
    
    // if(m1 == -inf)return 0;

    return m1;
}


int main(int argc, char * argv[]) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    memset(h, -1, sizeof h);
    
	int n, x, y, c;
	cin >> n;

	for(int i = 0; i < n - 1; i++) {
		cin >> x >> y >> c;
		add(x, y, c);
		add(y, x, c);
	}

    res = 0;
    
    // 这里父节点可以随便取，只要不在1-n范围
    dfs(1, 0);

	cout << res << endl;

    return 0;
}