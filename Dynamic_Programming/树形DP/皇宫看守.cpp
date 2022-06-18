/**
// 其中f[i][0] 表示当前第i个节点不派守卫，且被父节点看到的所有方案中的最小经费
// 其中f[i][1] 表示当前第i个节点不派守卫，且被子节点看到的所有方案中的最小经费
// 其中f[i][2] 表示当前第i个节点派守卫的最小经费

// f[i][0] = sigma(min(f[j][1], f[j][2]));
// f[i][1] = f[k][2] + sigma(min(f[j][1], f[j][2]));
// f[i][2] = sigma(min(f[i][0], f[j][1], f[j][2]));
 **/

#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 2000, M = N;


int h[M], e[M], ne[M], idx;
int f[N][3], w[N];

bool st[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
	// f[u][0] = f[u][1] = 0;
	f[u][2] = w[u];

	for(int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];
		dfs(v);

		f[u][0] += min(f[v][1], f[v][2]);
		f[u][2] += min(f[v][0], min(f[v][1], f[v][2]));
	}

	f[u][1] = inf;

	for(int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		f[u][1] = min(f[u][1], f[v][2] + f[u][0] - min(f[v][1], f[v][2]));
	}

	// 这里不需要覆盖了
	// if(f[u][1] == inf)f[u][1] = 0;
}


int main(int argc, char * argv[]) 
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(h, -1, sizeof h);
	memset(st, 0, sizeof(st));

	int n, m, k, id, x;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> id >> k >> m;
		w[id] = k;
		for(int j = 0; j < m; j++) {
			cin >> x;
			//单向边
			add(id, x);
			st[x] = true;
		}
	}

	int root = 1;
	while(st[root])root++;

	dfs(root);

	cout << min(f[root][1], f[root][2]) << endl;

    return 0;
}
