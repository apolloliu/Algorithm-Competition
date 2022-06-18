//#pragma GCC optimize(2)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define ms(s) memset(s, 0, sizeof(s))

const int inf = 1e9;
const int N = 123, M = 2 * N;
//#define LOCAL

int h[M], e[M], ne[M], idx;
int v[M], w[M];
int n, V;
int f[N][N]; // f[i][j] 表示当前第i个节点，体积不超过j的最大价值

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa) {
	// 初始化，只要体积满足最小为当前节点体积，最小值统统设为当前节点的价值
	for(int i = v[u]; i <= V; i++)
		f[u][i] = max(f[u][i], w[u]);

	for(int i = h[u]; i != -1; i = ne[i]) {
		int t = e[i];
		if(t == fa)continue;
		dfs(t, u);
		for(int j = V; j >= v[u]; j--)
			for(int k = 0; k <= j - v[u]; k++)
				f[u][j] = max(f[u][j], f[u][j - k] + f[t][k]);
	}
}



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(h, -1, sizeof h);

	cin >> n >> V;

	int root = 1;

	for(int i = 1; i <= n; i++) {
		int p;
		cin >> v[i] >> w[i] >> p;
		if(p == -1)root = i;
		else add(p, i);
	}

	dfs(root, 0);

	cout << f[root][V] << endl;

    return 0;
}