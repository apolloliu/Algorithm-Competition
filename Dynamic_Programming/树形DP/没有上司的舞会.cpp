#include <bits/stdc++.h>
using namespace std;

const int N = 6000 + 10, M = N;

int h[M], e[M], ne[M], idx;
int w[N], f[N][2], n;
bool st[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
	f[u][0] = 0;
	f[u][1] = w[u];

	for(int i = h[u]; i != -1; i = ne[i]) {
		int v = e[i];

		dfs(v);

		f[u][0] += max(f[v][1], f[v][0]);
		f[u][1] += f[v][0];
	}
}

int main() {
	memset(h, -1, sizeof(h));
	// memset(f, 0)

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> w[i];

	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		add(b, a);
		st[a] = true;
	}

	int root = 1;
	while(st[root])root++;

	dfs(root);

	cout << max(f[root][0], f[root][1]) << endl;
}