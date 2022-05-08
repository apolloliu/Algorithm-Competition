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

#define eps 1e-6
#define endl '\n'
#define ms(s) memset(s, 0, sizeof(s))

const int inf = 1e9;
const int N = 1e5 + 10;
//#define LOCAL

int n, m;
int pa[N];
set<int>s;
map<int, int>cnt;

int findset(int x) {
	return x == pa[x] ? x : findset(pa[x]);
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	// ios::sync_with_stdio(false);
	// cin.tie(0);

	// cin >> n >> m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i <= n; i++)pa[i] = i;

	for(int i = 0; i < m; i++) {
		int x, y;
		// cin >> x >> y;
		scanf("%d%d", &x, &y);
		int a = findset(x), b = findset(y);
		if(a <= b)pa[b] = a;
		else pa[a] = b;
	}

	cnt.clear();

	ll tmp = 0;

	for(int i = 1; i <= n; i++) {
		int a = findset(pa[i]);
		cnt[a] ++;
	}

	for(auto v: cnt) {
		auto [id, x] = v;
		tmp += x * 1LL * (x - 1) / 2;
	}

	ll res = n * 1LL * (n - 1) / 2;
	// cout << tmp << endl;
	printf("%.9lf\n", double(tmp * 1. / res));

    return 0;
}