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


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pll>a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	ll l, r;
	l = r = 0;

	for(int i = 1; i < n; i++) {
		ll t_dis = a[i].first  - a[i - 1].first;
		ll p_dis = a[i].second - a[i - 1].second;
		if(abs(p_dis) > t_dis) {
			if(p_dis < 0) {
				l += abs(p_dis) - t_dis;
			}
			else {
				r += p_dis - t_dis;
			}
		}
	}

	cout << r + l << endl;

    return 0;
}