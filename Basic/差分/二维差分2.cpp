#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], d[N][N];

// 差分
void insert(int x1, int y1, int x2, int y2, int c) {
	d[x1][y1] += c;
	d[x2 + 1][y2 + 1] += c;
	d[x1][y2 + 1] -= c;
	d[x2 + 1][y1] -= c;
}

int main() {
	cin >> n >> m >> q;

	while(q--) {
		int x1, x2, y1, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}

	int res = 0;
	// 求前缀和
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			// cout << d[i][j] << ' ';
			res ^= d[i][j];
		}
		// cout << '\n';
	}

	cout << res << endl;

	return 0;
}