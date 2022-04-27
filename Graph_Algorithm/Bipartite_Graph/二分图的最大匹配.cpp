// 算法复杂度 O(nm), n为顶点数，m为边数
// 本题是有向图
#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 1e5 + 10;

vector<int>edge[N];

/**
 * n1: 左边的点的数量
 * n2: 右边的点的数量
 * v[M]: 右边对应的左边的点
 * st数组：标记某个点是否被访问过
 **/
int v[N], n1, n2;
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

	for(int i = 1; i <= n1; i++) {
		memset(st, 0, sizeof(st));
		if(dfs(i))
			res++;
	}

	return res;
}

int main(int argc, char* argv[]) {
	int m, x, y;
	cin >> n1 >> n2 >> m;

	for(int i = 1; i <= n1; i++) {
		edge[i].clear();
	}

	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		edge[x].push_back(y);
		// edge[y].push_back(x);
	}

	cout << match() << endl;

}