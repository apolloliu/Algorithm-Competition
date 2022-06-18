#include <bits/stdc++.h>

using namespace std;


const int N = 110, M = N * N;

int h[N], e[M], ne[M], idx;
int scc_cnt, scc[N];
int id[N], dfn[N], low[N], timestamp;
stack<int>stk;
bool in_stk[N];
int dout[N], din[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++timestamp;
	stk.push(u);
	in_stk[u] = true;

	for(int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if(!dfn[j]) {
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if(in_stk[j])
			low[u] = min(low[u], dfn[j]);
	}


	if(dfn[u] == low[u]) {
		int x;
		++scc_cnt;

		do {
			x = stk.top();
			stk.pop();
			in_stk[x] = false;
			scc[scc_cnt]++;
			id[x] = scc_cnt;
		}
		while(x != u);
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(h, -1, sizeof(h));

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		int x;
		while(cin >> x && x) {
			add(i, x);
		}
	}

	// int sum = 0;
	for(int i = 1; i <= n; i++)
		if(!dfn[i]) {
			// sum++;
			tarjan(i);
		}


	// for(int i = 1; i <= n; i++)
	// 	cout << id[i] << ' ';
	// cout <<endl;

	for(int i = 1; i <= n; i++) {
		for(int j = h[i]; ~j; j = ne[j]) {
			int k = e[j];
			int a = id[i], b = id[k];
			if(a != b)dout[a]++, din[b]++;
		}
	}

	int tot = 0, sum = 0;
	for(int i = 1; i <= scc_cnt; i++) {
		if(!din[i])sum++;
		if(!dout[i])tot++;
	}

	tot = max(tot, sum);
	if(scc_cnt == 1)tot = 0;

	cout << sum << endl;
	cout << tot << endl;

	return 0;
}