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

bool check(ll x, ll y) {
	if((x & y) > 0 && (x ^ y) > 0)return true;
	return false;
}
void solve() {
	int n, m, t;
	cin >> n;
	t = n;
	m = n;
	int i = 0, j = 0;
	while(n) {
		if(n & 1) {
			break;
		}
		i++;
		n = n >> 1;
	}
	while(m) {
		if(!(m & 1)) {
			break;
		}
		j++;
		m = m >> 1;
	}
	// cout <<i << ' ' << j <<endl;
	if(check(1 << i, t))cout << (1 << i) << endl;
	else if(check(1 << j, t))cout << (1 << j) << endl;
	else if(check((1 << i) + (1 << j), t))cout << (1 << i) + (1 << j) << endl;

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