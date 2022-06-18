#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 12;

int n, m;
int f[N][M][M];
char g[N][M];
vector<int>T[N];
vector<int>state;


// bool ok(int k, int x) {
// 	if()
// }

bool check(int x) {
	for(int i = 0; i < m; i++)
		if((x >> i & 1) && ((x >> (i + 1) & 1) || (x >> (i + 2) & 1)))
			return false;
	return true;
}

int calc(int i) {
	int res = 0;
	for(int j = 0; j < m; j++)
		res += g[i][j] == 'P' ? (1 << j) : 0;
	return res;
}

int count_bits(int x) {
	int res = 0;
	while(x) {
		res += x & 1;
		x >>= 1;
	}
	return res;
}

int main() {
	// cin >> n >> m;
	scanf("%d%d", &n, &m);
	// cout <<  count_bits(5) << endl;
	vector<int>cnt(n + 1, 0);

	for(int i = 1; i <= n; i++) {
		scanf("%s", g[i]);
		// printf("%s\n", g[i]);
		for(int j = 0; j < m; j++)
			cnt[i] += (g[i][j] == 'P' ? 1 : 0) << j;
		// cnt[i] = calc(i);
		// cout << cnt[i] << endl;
	}


	for(int i = 0; i < 1 << m; i++)
		if(check(i))
			state.push_back(i);

	int sz = state.size();
	// for(int i = 0; i < sz; i++)
	// 	cout << "state: " << i << ' ' << state[i] << endl;


	// f[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int i1 = 0; i1 < sz; i1++)
			for(int i2 = 0; i2 < sz; i2++)
				for(int i3 = 0; i3 < sz; i3++) {
					int a = state[i1], b = state[i2], c = state[i3];
					if(a & cnt[i])continue;
					// if(!check(a | cnt[i]))continue;
					// if(b & cnt[i - 1])continue;
					// if(a & cnt[i] | b & cnt[i - 1])continue;
					if((a & b) | (a & c) | (b & c))continue;
					int num = count_bits(a);
					// f[i & 1][a][b] = max(f[(i - 1) & 1][b][c] + num, f[i & 1][a][b]);
					f[i][i1][i2] = max(f[i][i1][i2], f[i - 1][i2][i3] + num);
					// cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << f[i][i1][i2] << endl;
				}

	// for(int i = 1; i <= n; i++)
	// 	cout << i - 2 << ' ' << f[i][0][0] << endl;

	// for(int i = 0; i < sz; i++)
	// 	for(int j = 0; j < sz; j++)
	// 		cout << "first line: " << i << ' ' << j << ' ' << f[1][i][j] << endl;

	int res = 0;
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++)
			res = max(res, f[n][i][j]);
	cout << res << endl;

	return 0;
}