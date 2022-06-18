//#pragma GCC optimize(2)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define ms(s) memset(s, 0, sizeof(s))

const int inf = 1e9;
const int N = 2e5 + 10, M = 1010;
//#define LOCAL

ll a[N];
int id[N];
vector<int>c[N];

// 5 3 8 6 3 2

// 5
// 6
// 3 8

// 3 2
// 3 5 6 8
// 2



void solve() {
	memset(id, 0, sizeof id);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i <= k; i++)c[i].clear();

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i]) c[a[i] % k].push_back(a[i]);
	}

	for(int i = 0; i < k; i++) {
		sort(c[i].begin(), c[i].end(), [&](int a, int b) {
			// return c[i][j] > c[i][];
			return a > b;
		});
	}

	vector<int>v;
	ll res = 0;
	int i = 0;
	int sz = c[0].size();
	for(i = 0; i + 1 < sz; i += 2) {
		res += (c[0][i] + c[0][i + 1]) * 1LL / k;
	}
	while(i < sz) {
		v.push_back(c[0][i++]);
	}
	for(i = 1; i < k; i++) {
		int n1 = i, n2 = (k - i) % k;
		int sz_a = c[n1].size();
		int sz_b = c[n2].size();
		if(n1 != n2)
		while(id[n1] < sz_a && id[n2] < sz_b) {
			res += (c[n1][id[n1]] + c[n2][id[n2]]) * 1LL / k;
			id[n1]++;
			id[n2]++;
		}
		else {
			while(id[n1] + 1 < sz_a) {
				res += (c[n1][id[n1]] + c[n2][id[n1] + 1]) * 1LL / k;
				id[n1] += 2;
			}
		}
		// cout << "res :" << res << " i: " << i << endl;
		while(id[n1] < sz_a) {
			v.push_back(c[n1][id[n1]]);
			id[n1]++;
		}
		while(id[n2] < sz_b) {
			v.push_back(c[n2][id[n2]]);
			id[n2]++;
		}
	}

	sort(v.begin(), v.end());

	// memset(c, 0,)
	// for(int i = 0; i < n; i++)

	sz = v.size();
	// double ans = 0.;
	int j;
	for(int j = 0; j + 1< sz; j += 2)
		res += (v[j] + v[j + 1]) * 1LL / k;
	// for(i = 0, j = sz - 1; i < j; i ++, j--) {
	// 	// cout << "i: " << i << " j: " << j << endl;
	// 	cout << "val "<< v[i] << ' ' << v[j] << endl;
	// 	res = res + (v[i] + v[j]) * 1. / k;
	// }

	// res += floor(ans);
	cout << res << endl;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--) {
		solve();
	}
	

    return 0;
}