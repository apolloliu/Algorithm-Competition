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
const int N = 310, M = 2 * N;
//#define LOCAL

int h[M], e[M], ne[M], idx;
int n, S, total_v;
int c[N], w[N];
// ll f[N][N][3]; // f[i][j] 表示当前第i个节点，j为体积
// 其中f[i][j][0] 表示当前第i个节点不派蜜蜂，且被父节点看到的所有方案中的最小花粉power
// 其中f[i][j][1] 表示当前第i个节点不派蜜蜂，且被子节点看到的所有方案中的最小花粉power
// 其中f[i][j][2] 表示当前第i个节点派蜜蜂的最小花粉power
// f[u][j][0] = sigma(min(f[v][j][1], f[v][j][2]));
// f[u][j][1] = f[k][j][2] + sigma(min(f[v][t][1], f[v][t][2]));
// f[u][j][2] = sigma(min(f[u][j - c[u]][0], f[v][j - c[u]][1], f[v][j - c[u]][2]));


ll f[N][N * N][2]; // f[i][j] 表示当前第i个节点，j为体积
// 其中f[i][j][0] 表示当前第i个节点不派蜜蜂，且被父节点看到的所有方案中的最小花粉power
// 其中f[i][j][1] 表示当前第i个节点不派蜜蜂，且被子节点看到的所有方案中的最小花粉power
// 其中f[i][j][2] 表示当前第i个节点派蜜蜂的最小花粉power
// f[u][j][0] = sigma(min(f[v][j][1], f[v][j][2]));
// f[u][j][1] = f[k][j][2] + sigma(min(f[v][t][1], f[v][t][2]));
// f[u][j][2] = sigma(min(f[u][j - c[u]][0], f[v][j - c[u]][1], f[v][j - c[u]][2]));

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa) {
	for(int i = c[u]; i <= total_v; i++ )
		f[u][i][1] = w[u];

	for(int i = h[u]; i != -1; i = ne[i]) {
		int v = e[i];
		if(v == fa)continue;
		dfs(v, u);

		for(int j = total_v; j >= 0; j--) {
			f[u][j][0] += f[v][j][1];
		}
		for(int j = total_v; j >= 0; j--){
			ll x = inf;
			for(int k = 0; k <= j - c[u]; k++){
				x = min(x, f[u][j - k - c[u]][1] + min(f[v][k][0], f[v][k][1]) + w[u]);
				// f[u][j][1] += min(f[v][j - c[u]][0], f[v][j - c[u]][1]);
			}
			f[u][j][1] += x;
		}
			
			
	}
}

int main() 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	// memset(f, 0x3f, sizeof f);

	memset(h, -1, sizeof h);
	cin >> n >> S;

	total_v = 0;
	int total_w = 0;
	for(int i = 1; i <= n; i++)
		cin >> c[i] >> w[i],
		total_v += c[i],
		total_w += w[i];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < total_v; j++)
			for(int k = 0; k < 2; k++)
			f[i][j][k] = inf;

	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}

	dfs(1, 0);

	for(int i = 0; i <= total_v; i++)
	cout << i << ' ' << f[1][i][0] << ' ' << f[1][i][1] << ' ' << total_w << endl;

	// ll sum = 0;
	// for(int i = total_v - S; total_v; i++)
	// 	sum += min(f[1][i][2], f[1][i][1]);

	cout << min(f[1][total_v - S][0], f[1][total_v - S][1]) << endl;


	// for(int i = S; i <= )

	// for(int i = 0; i <= n; i++)
	// cout << f[1][total_v - S] << endl;
	// cout << total_w -  << endl;

    return 0;
}