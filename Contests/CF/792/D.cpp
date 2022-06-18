#pragma GCC optimize(2)
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

ll a[N], b[N];

void solve() {
	int n, k;
	cin >> n >> k;

	ll res = 0;

	for(int i = 1; i <= n; i++)cin >> a[i], b[i] = a[i] - (n - i), res += a[i];

	sort(b + 1, b + n + 1, greater<int>());

	for(int i = 1; i <= k; i++)
		res -= b[i];

	// 这里注意要乘以1LL，防止溢出
	res -= k * 1LL * (k - 1) / 2;

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