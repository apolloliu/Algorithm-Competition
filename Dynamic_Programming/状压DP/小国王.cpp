#pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define ms(s) memset(s, 0, sizeof(s))

const int inf = 1e9;
const int N = 12;
//#define LOCAL

ll f[N][1 << N][N * N];
int n, m;
vector<int>state;
// unordered_map<int, vector<int>>T;
vector<int>T[1 << N];

int calc_bits(int x) {
	int sum = 0;
	while(x) {
		sum += (x & 1);
		x >>= 1;
	}
	return sum;
}

bool check(int x) {
	int last = 0;
	while(x) {
		if((x & 1) && last)return false;
		last = x & 1;
		x >>= 1;
	}
	return true;
}

int main(int argc, char * argv[]) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < 1 << n; i++)
		if(check(i))state.push_back(i);

	for(auto x: state) {
		for(auto y: state) {
			// 用 x & i 和 x | i来判断
			if((x & y) || !check(x | y))continue;
			T[x].push_back(y);
		}
	}

	f[0][0][0] = 1;

	for(int i = 1; i <= n + 1; i++)
		for(auto a : state)
			for(auto b: T[a])
				for(int j = 0; j <= m; j++) {
					int c1 = calc_bits(a), c2 = calc_bits(b);
					if(j >= c1 && j >= c1 + c2)
						f[i][a][j] += f[i - 1][b][j - c1];
				}

	// 两种计算方式均可
	// ll res = 0;
	// for(int i = 0; i < 1 << n; i++)
	// 	res += f[n][i][m];
	// cout << res << endl;

	cout << f[n + 1][0][m] << endl;

    return 0;
}