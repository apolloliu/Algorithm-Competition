#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;

stack<int>stk;
bool in_stk[N];
int h[N], e[N], ne[N], idx;
int id[N], dfn[N], low[N], timestamp;
int scc[N], scc_cnt; // 连通分量从1开始计算

int dout[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++timestamp;
	stk.push(u);
	in_stk[u] = true;

	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!dfn[j]) {
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if(in_stk[j]) {
			low[u] = min(low[u], dfn[j]);
		}
	}

	if(low[u] == dfn[u]) {
		scc_cnt++;
		int node;
		do {
			if(!stk.size())break;

			node = stk.top();
			stk.pop();
			scc[scc_cnt]++;
			in_stk[node] = false;
			id[node] = scc_cnt;
		}
		while(node != u);
	}
}

int main(int argc, char const *argv[])
{
	int n, m;
	memset(h, -1, sizeof h);
	memset(in_stk, false, sizeof in_stk);

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		add(a, b);
	}

	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			tarjan(i);

	// for(int i = 1; i <= n; i++) {
	// 	cout << id[i] << ' ';
	// }
	// cout << endl;

	for(int i = 1; i <= n; i++) {
		for(int j = h[i]; j != -1; j = ne[j]) {
			int k = e[j];
			int x = id[i], y = id[k];
			if(x != y) dout[x]++;
		}
	}

	// 保证最后一个出度为0的缩点只有一个，然后该缩点的大小即为答案
	int res = 0, num = 0;
	for(int i = scc_cnt; i >= 1; i--) {
		if(!dout[i]) {
			num ++;
			res += scc[i];
		}
	}

	if(num > 1)res = 0;

	printf("%d\n", res);

	return 0;
}