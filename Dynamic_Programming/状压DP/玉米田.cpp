#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 14;
const int mod = 1e8;

ll f[N][1 << N], a[N][N];
int n, m;
vector<int>state[1 << N];

bool ok(int k, int x) {
	for(int i = 0; i < m; i++)
		if((x >> i & 1) && (x >> (i + 1) & 1))return false;

	for(int i = 1; i <= m; i++)
		if(!a[k][i] && (x >> (i - 1) & 1))return false;
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	state[0].push_back(0);
	for(int i = 1; i <= n; i++) {
		for(int j 

			= 1; j <= m; j++)
			cin >> a[i][j];
		for(int j = 0; j < 1 << m; j++) {
			if(ok(i, j))state[i].push_back(j);
		}
	}

	f[0][0] = 1;
	for(int i = 1; i <= n + 1; i++)
		for(int j = 0; j < state[i].size(); j++)
			for(int k = 0; k < state[i - 1].size(); k++) {
				int &a = state[i][j], &b = state[i - 1][k];
				if((a & b) == 0)
					f[i][a] = (f[i][a] + f[i - 1][b] ) % mod;
			}


	int res = 0;
	for(int i = 0; i < 1 << m; i++)
		res = (res + f[n][i]) % mod;
	cout << res << endl;

}