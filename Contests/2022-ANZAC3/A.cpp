//#pragma GCC optimize(2)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long long ull;
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
	ll L = a[0].second, R = a[0].second;

	ll over = 0;
	for(int i = 1; i < n; i++) {
		ll t_dis = a[i].first - a[i - 1].first + over;
		ll &x = a[i].second;

		if(x < L) {
			if(x < L - t_dis) L = x, R -= t_dis;
			else
				over = t_dis - (L - x), 
				R -= min(t_dis, L - x), L = x;
		}
		if(x > R) {
			if(R + t_dis < x) R = x, L += t_dis;
			else
				over = t_dis - (x - R),
				L += min(t_dis, x - R), R = x;
		}
		// else over = 0;
		// else over = t_dis;

		// if(x < L - t_dis) {
		// 	L = x;
		// }
		// else if(x > R + t_dis) {

		// }
		// if(abs(diff) <= t_dis) continue;

		// L = a[i - 1].second - l + t_dis;
		// R = a[i - 1].second + r + t_dis;
		// ll tmp_l = l, tmp_r = r;
		// if(L > a[i].second) tmp_l += abs(a[i].second - L);
		// if(R < a[i].second) tmp_r += abs(a[i].second - R);

		// l = tmp_l; r = tmp_r;

		// L = a[i - 1].second - l - t_dis;
		// R = a[i - 1].second + r - t_dis;
		// ll tmp1_l = l, tmp1_r = r;
		// if(L > a[i].second) tmp1_l += abs(a[i].second - L);
		// if(R < a[i].second) tmp1_r += abs(a[i].second - R);

		// if(tmp1_l + tmp1_r <= tmp_l + tmp_r) {
		// 	l = tmp1_l;
		// 	r = tmp1_r;
		// }
		// else {
		// 	l = tmp_l;
		// 	r = tmp_r;
		// }
	}

	cout << R - L << endl;
	// cout << max(R - L, 0LL) << endl;

	// int last = 0;
	// for(int i = 1; i < n; i++) {
	// 	ll t_dis = a[i].first - a[last].first;
	// 	ll diff = a[i].second - a[last].second;
	// 	if(abs(diff) > t_dis) {
	// 		if(diff >= 0) {
	// 			// L = a[0].second - l + t_dis;
	// 			if(L + t_dis > a[i].second) l += L + t_dis - a[i].second, L = a[i].second;
	// 			else L += t_dis;
	// 			if(R + t_dis < a[i].second) r += a[i].second - (R + t_dis), R = a[i].second;
	// 			else R += t_dis;
	// 		}
	// 		else {
	// 			if(L - t_dis > a[i].second) l += L - t_dis - a[i].second, L = a[i].second;
	// 			else L -= t_dis;
	// 			if(R - t_dis < a[i].second) r += a[i].second - (R - t_dis), R = a[i].second;
	// 			else R -= t_dis;
	// 		}
	// 		last = i;

	// 		cout << "l r: " << i << ' ' << l << ' ' << r << endl;
	// 	}
	// 	// else {
	// 	// 	L =
	// 	// }
	// }

	// cout << (l + r) << endl;

    return 0;
}