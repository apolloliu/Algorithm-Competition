#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int inf = 2e9;
const int N = 12345, M = 2 * N;

// map<pii, int>v;
int h[M], w[M], e[M], ne[M], idx;
int up[N], d1[N], d2[N], from[N], from2[N];
bool is_leaf[N];

void add(int a, int b, int c) {
    w[idx] = c, e[idx] = b; ne[idx] = h[a], h[a] = idx++;
}


int dfs_d(int x, int fa) {
    d1[x] = d2[x] = -inf;
    
    for(auto i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if(j != fa) {
            int d = dfs_d(j, x) + w[i];
            // val = max(val, d);
            if(d >= d1[x]) {
                d2[x] = d1[x];
                d1[x] = d; from[x] = j;
            }
            else if(d > d2[x]) {
                d2[x] = d;
            }
        }
    }

    if(d1[x] == -inf) {
        // is_leaf[x] = true;
        d1[x] = d2[x] = 0;
    }
    
    return d1[x];
}

void dfs_u(int x, int fa) {
    for(int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if(j != fa) {
            if(from[x] == j)up[j] = max(up[x], d2[x]) + w[i];
            else up[j] = max(up[x], d1[x]) + w[i];
            dfs_u(j, x);
        }
    }
}


int main(int argc, char * argv[]) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    memset(h, -1, sizeof h);
    memset(is_leaf, false, sizeof is_leaf);

	int n, x, y, c;
	cin >> n;

	for(int i = 0; i < n - 1; i++) {
		cin >> x >> y >> c;
		add(x, y, c);
		add(y, x, c);
	}

    // 这里父节点可以随便取，只要不在1-n范围
    dfs_d(1, 0);
    dfs_u(1, 0);

    int res = inf;

    for(int i = 1; i <= n; i++) {
        cout << i << ' ' << d1[i] << ' ' << up[i] << endl;
    }

    for(int i = 1; i <= n; i++)
        // if(is_leaf[i])res = min(res, up[i]);
        // else 
        res = min(res, max(up[i], d1[i]));

	cout << res << endl;

    return 0;
}