// 算法复杂度 O(nm), n为顶点数，m为边数
// 重要结论：最大独立集 = 节点数 - 二分图最大匹配数
// 本题是有向图

#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 1e5 + 10;

vector<int>edge[N];

/**
 * n1: 左边的点的数量
 * n2: 右边的点的数量
 * v[M]: 右边对应的左边的点
 * c[N]: 记录每个节点是在左边还是右边
 * st数组：标记某个点是否被访问过
 **/
int n, m;
int v[N], n1, n2, r[N], c[N], a[M][2];
bool st[N];

bool dfs(int i) {
	st[i] = true;
	for(auto x : edge[i]) {
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

	for(int i = 1; i <= n1; i++) {
		memset(st, 0, sizeof(st));
		if(dfs(i))
			res++;
	}

	return res;
}

// 将每个节点进行染色
inline void calc(int i) {

	for(auto x : edge[i]) {
		if(!c[x]) {
			c[x] = 3 - c[i];
			calc(x);
		}
	}
}

int main(int argc, char* argv[]) {
	int x, y;
	cin >> n >> m;

	// 第一次利用边表是为了给每个节点染色
	for(int i = 0; i < m; i++) {
		cin >> a[i][0] >> a[i][1];
		edge[a[i][0]].push_back(a[i][1]);
		edge[a[i][1]].push_back(a[i][0]);
	}

	for(int i = 1; i <= n; i++) {
		if(!c[i]) {
			c[i] = 1;
			calc(i);
		}
	}

	
	for(int i = 1; i <= n; i++) {
		if(c[i] == 1)r[i] = ++n1;
		else if(c[i] == 2)r[i] = ++n2;

		edge[i].clear();
	}

	// 第二次利用边表是为了构造二分图
	for(int i = 0; i < m; i++) {
		x = a[i][0], y = a[i][1];

		if(c[x] == 1) edge[r[x]].push_back(r[y]);
		else edge[r[y]].push_back(r[x]);
	}
	

	cout << n - match() << endl;

}