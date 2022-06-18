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
const int N = 1e6 + 10;
//#define LOCAL

ll a[N];
int n;
ll sum;
vector<pll>v;
set<pll>s;

inline bool ok(ll m) {
	// auto it = lower_bound(v.begin(), v.end(), {m, inf}) - v.begin();
	// for(int i = 1; i <= n + 1; i++) {
	for(auto it = s.begin(); it != s.end(); ++it) {
		int i = it->second;
		if(m >= a[i]){
			// cout << m << ' ' << i << endl;
			int j = i, k = i + 1;
			ll tot = m;
			int t = n, c = n;
			while(j >= 1 || k <= 2 * n) {
				// if(m == 1 && i == 5)
				// 	cout << "before: " << j <<' ' << k << " total: " << tot << ' ' << sum << endl;
				bool flag = true;
				if(j >= 1 && a[j] <= tot) {
					// cout << "j: " << a[j] << endl;
					tot += a[j--];
					c--;
					flag = false;
				}
				if(k <= 2 * n && a[k] <= tot) {
					// cout << "k: " << a[k] << endl;
					tot += a[k++];
					c--;
					flag = false;
				}
				if(flag)break;
				// if(m == 1 && i == 5)
				// 	cout << j <<' ' << k << " total: " << tot << ' ' << sum << endl;
				// if(k - j >= n + 1)break;
				if(tot >= sum && k - j >= n + 1)return true;
				if(k - j >= n + 1)break;
				t--;
				if(!t || !c)break;
			}
			// if(m == 1 && i == 5)
			// 	cout << "total: " << tot << ' ' << sum << endl;
			if(tot >= sum && k - j >= n + 1)return true;
		}
		else break;
	}
	return false;
}


inline void calc() {
	ll res = 1e18;

	for(int i = 1; i <= n + 1; i++) {
		ll ans = a[i], tot = a[i] * 2;
		int j = i - 1, k = i + 1;
		while(k - j < n + 1) {
			// cout << j << ' ' << k << ' ' << tot << ' ' << ans << endl;
			if(k > 2 * n) {
				if(a[j] <= tot)tot += a[j--];
				else {
					// if(a[j] - tot <= ans)ans += a[j] - tot;
					// else ans = a[j] - tot;
					ans += a[j] - tot;
					tot = a[j--] * 2;
				}
			}
			else if(j < 1) {
				if(a[k] <= tot)tot += a[k++];
				else {
					// if(a[k] - tot <= ans) ans += a[k] - tot;
					// else ans = a[k] - tot;
					ans += a[k] - tot;
					tot = a[k++] * 2;
				}
			}
			else if(a[j] <= a[k]) {
				if(a[j] <= tot)tot += a[j--];
				else {
					// if(a[j] - tot <= ans)ans += a[j] - tot;
					// else ans = a[j] - tot;
					ans += a[j] - tot;
					tot = a[j--] * 2;
				}
			}
			else {
				if(a[k] <= tot)tot += a[k++];
				else {
					// if(a[k] - tot <= ans) ans += a[k] - tot;
					// else ans = a[k] - tot;
					ans += a[k] - tot;
					tot = a[k++] * 2;
				}
			}
			
		}
		// cout << j << ' ' << k << ' ' << tot << ' ' << ans << endl;
		// if(tot >= sum)
		res = min(res, ans);
	}
	printf("%lld\n", res);
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	// ios::sync_with_stdio(false);
	// cin.tie(0);

	// cin >> n;
	scanf("%d", &n);
	sum = 0;

	ll l = 0, r = 0;
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]),
		// cin >> a[i],
		a[n + i] = a[i],
		sum += a[i],
		r = max(a[i], r),
		s.insert({a[i], i});
		// v.push_back({a[i], i});

	// sort(v.begin(), v.end());
	// ll l = 0, r = 1LL<<63 - 1;
	
	// while(l < r) {
	// 	ll m = l + r >> 1;
	// 	if(ok(m))r = m;
	// 	else l = m + 1;
	// }

	calc();
	
	// cout << res << endl;

	// cout << r << endl;
	// printf("%lld\n", r);

    return 0;
}