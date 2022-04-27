// 这里利用拆点的技巧，每个点都拆分成出点和入点
// 每个点只能用一次，所以可以使用二分图最大匹配

#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 10010;

vector<int>edge[N];
int v[N], n, m; // 这里的n即表示左边和右边各有n个点
bool st[N];

bool dfs(int i) {
	st[i] = true;
	for(auto x: edge[i]) {
		if(!v[x] || (!st[v[x]] && dfs(v[x]))) {
			v[x] = i;
			return true;
		}
	}

	return false;
}

inline int match() {
	int res = 0;
	memset(v, 0, sizeof(v));

	for(int i = 1; i <= n; i++) {
		memset(st, 0, sizeof(st));
		if(dfs(i))
			res++;
	}

	return res;
}

int main() {

	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
	}


	cout << n - match() << '\n';

	return 0;
}