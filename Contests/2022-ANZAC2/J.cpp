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
const int N = 1324;
//#define LOCAL

int a[N];
int s;

int calc(int x, int y) {
	if(y <= x) y += s;

	// cout << x << ' ' << y << endl;
	int res = 0, t = 0;
	if(y - x - 1 >= 3) {
		x += 4;
		res ++;
		t = 1;
	}
	if(t) res += (y - x) / 2;

	return res;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;
	cin >> s >> n;

	for(int i = 1; i <= n; i++) {
		cin >> x;
		a[x] = 1;
	}

	vector<int>v;
	for(int i = 1; i <= s; i++) {
		if(a[i])v.push_back(i);
	}

	int res = 0, sz = v.size();
	for(int i = 0; i < sz - 1; i++) {
		x = v[i], y = v[i + 1];

		res += calc(x, y);
	}

	res += calc(v[sz - 1], v[0]);

	cout << res << endl;

    return 0;
}