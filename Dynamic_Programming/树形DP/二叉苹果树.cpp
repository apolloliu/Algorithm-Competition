// 有依赖的背包问题的简化版

//#pragma GCC optimize(2)

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
const int N = 124, M = 2 * N;
//#define LOCAL
int h[M], e[M], ne[M], w[M], idx;
int f[N][N]; // f[i][j] 表示当前第i个节点，子树边数不超过j，所包含的最多苹果数
int n, Q;

void add(int a, int b, int c) {
	w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


void dfs(int u, int fa){
	// 这里不需要初始化
	// for(int i = 1; i <= n; i++)
		// f[u][i] = 1;
	int V = n - 1;

	for(int i = h[u]; i != -1; i = ne[i]) {
		int v = e[i];
		if(v == fa) continue;
		dfs(v, u);

		for(int j = V; j; j--)
			for(int k = 0; k <= j - 1; k++)
				f[u][j] = max(f[u][j], f[u][j - k - 1] + f[v][k] + w[i]);
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
	
	cin >> n >> Q;

	for(int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}

	dfs(1, 0);

	cout << f[1][Q] << endl;

    return 0;
}