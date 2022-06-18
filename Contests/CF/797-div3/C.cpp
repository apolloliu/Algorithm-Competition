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
const int N = 2e5 + 10;
//#define LOCAL

int s[N], f[N];
void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++)
		cin >> f[i];
	int cur = 0;
	vector<int>v;

	int i = 1;
	while(i <= n) {
		v.push_back(f[i] - max(s[i], cur));
		cur = max(cur, f[i++]);
	}
	int sz = v.size();
	for(i = 0; i < sz; i++)
		cout << v[i] << (i == sz - 1 ? "" : " ");
	cout << endl;
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