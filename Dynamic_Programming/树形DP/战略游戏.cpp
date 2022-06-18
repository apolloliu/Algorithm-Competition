#include <bits/stdc++.h>

using namespace std;
const int N = 2000, M = N * 2;

int h[M], e[M], ne[M], idx;
int f[N][2]; // f[i][k] 表示覆盖第i个节点包含的子树所需最少节点数，k为0表示不选，k为1表示选该点
int n;
bool st[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
	f[u][0] = 0;
	f[u][1] = 1;

	for(int i = h[u]; i != -1; i = ne[i]) {
		int v = e[i];
		dfs(v);

		f[u][1] += min(f[v][1], f[v][0]);
		f[u][0] += f[v][1];
	}

}


int main(int argc, char * argv[]) 
{

	// ios::sync_with_stdio(false);
	// cin.tie(0);

	while(cin >> n) {
		// 这里必须初始化邻接表的idx
		idx = 0;
		memset(h, -1, sizeof h);
		memset(f, 0, sizeof f);
		memset(st, false, sizeof st);

		for(int i = 1; i <= n; i++) {
			int id, m;
			scanf("%d:(%d)", &id, &m);
			for(int j = 0; j < m; j++) {
				int x;
				scanf("%d", &x);
				add(id, x);
				// add(x, id);
				st[x] = true;
				
			}
		}

		
		int root = 0;
		while(st[root])root++;
		dfs(root);

		printf("%d\n", min(f[root][1], f[root][0]));
	}

    return 0;
}