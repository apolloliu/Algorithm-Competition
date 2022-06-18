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
const int N = 12345;
//#define LOCAL

void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll>a(n + 1), sum(n + 1, 0);
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum[i] = a[i] + sum[i - 1];

	// for(auto x: a)
	// 	cout << x << ' ';
	// cout << endl;


	// cout << "xxxx " << sum[n] << endl;

	ll res = 0;
	if (k >= n) {
		res = sum[n] + k - 1;
		cout << res << endl;
		return; 
	}

	for(int i = 1; i <= n; i++) {
		// cout << "woc" <<endl;
		if(i >= k) {
			ll ans = sum[i] - sum[i - k] + k - 1;
			// cout << i << ' ' << ans << endl;
			res = max(ans, res);
		}
	}

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