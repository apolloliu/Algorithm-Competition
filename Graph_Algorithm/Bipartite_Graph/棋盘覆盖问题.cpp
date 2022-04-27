// 算法复杂度 O(nm), n为顶点数，m为边数
#include <bits/stdc++.h>

using namespace std;

const int N = 50;
vector<int>edge[N * N]; // 这里棋盘的点数最大
int v[N * N], a[N][N], n1, n2, r[N][N];
bool st[N * N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool dfs(int i){
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
	memset(v, 0, sizeof v);
	for(int i = 1; i <= n1; i++) {
		memset(st, 0, sizeof st);
		if(dfs(i))
			res++;
	}

	return res;
}


int main(int argc, char* argv[]) {
	int n, m, x, y;
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x][y] = 1;
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(!a[i][j]) {
				if((i + j) & 1)r[i][j] = ++n2;
				else r[i][j] = ++n1;
			}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(!a[i][j]) {
				for(int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if(nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny]) continue;
					int t1 = r[i][j], t2 = r[nx][ny];
					if((i + j) & 1)edge[t2].push_back(t1);
					else edge[t1].push_back(t2);
				}
			}

	cout << match() * 2 << endl;

	return 0;
}