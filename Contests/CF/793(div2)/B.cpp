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

int a[N], b[N];


void solve() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// cout << (3 & 4) << endl;

	int res = -1;
	vector<int>v; v.clear();
	for(int i = 0; i < n; i++) {
		if(a[i] != i) {
			res &= a[i];
			// v.push_back(a[i]);
			// cout << i << endl;
			// return;
		}
	}

	cout << res << endl;
	// int m = v.size();
	// int res = 0;
	// // quick_sort(0, n - 1);
	// sort(v.begin(), v.end());
	// int t = inf;
	// for(int i = 0; i < m; i++)
	// 	t = min(t, v[i] & v[1]);
	// res = max(res, t);
	// t = inf;
	// for(int i = 0; i < m; i++)
	// 	t = min(t, v[i] & v[0]);
	// res = max(res, t);
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