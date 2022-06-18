//#pragma GCC optimize(2)
// #pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e5 + 10;
//#define LOCAL


// odd + even = odd;
// 10 / 2 = 5
// 12 / 2 = 6, 2
// 2, 1
// 14, 2
// 2, 1
// 4, 2
// 6, 2
// 10, 8, 6, 4, 2,
// 6 + 4 + 8, 

void solve() {
	int n;
	cin >> n;
	// cout << n << endl;
	vector<int>a;
	a.clear();
	int odd, even;
	odd = even = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x & 1)odd++;
		else even++, a.push_back(x);
	}

	// cout << "1" << endl;
	if(odd >= even) {
		cout << even << endl;
		return;
	}

	sort(a.begin(), a.end(), [&](int i, int j) {
		int n1 = 0, n2 = 0, x = i, y = j;
		while(x % 2 == 0) n1++, x >>= 1;
		while(y % 2 == 0) n2++, y >>= 1;

		if(n1 != n2)return n1 > n2;
		return i > j;
	});

	// for(auto x : a)
	// 	cout << x << " ";
	// cout << endl;

	int sz = a.size();
	auto get = [](ll x) {
		ll n1 = 0;
		while(x % 2 == 0) n1++, x >>= 1;
		return n1;
	};

	ll res = 0;
	for(int i = odd; i < sz; i++)
		res += a[i];
	ll ans = odd + get(res) + sz - odd - 1;
	if(odd)ans = min(ans, 1LL * even);
	ll num = get(a[sz - 1]);
	ans = min(ans, odd + (sz - odd) + num - 1);

	cout << ans << endl;

	// ll res = get(a[sz - 1]) + sz - odd - 1;

	// cout << res << endl;
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