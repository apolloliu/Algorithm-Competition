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
const int N = 50010 , M = 2 * N;
//#define LOCAL
int h[M], e[M], ne[M], idx;
int ans;

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int calc(int x) {
	int res = 1;
	for(int i = 2; i <= x / i; i++) {
		if(x % i == 0){
			res += i;
			if(x / i != i)
				res += x / i;
		}
	}
	return res;
}

int dfs(int u, int fa) {
	int d1, d2;
	d1 = d2 = 0;

	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(j == fa)continue;
		int d = dfs(j, u) + 1;

		if(d >= d1) {
			d2 = d1; d1 = d;
		}
		else if(d >= d2) d2 = d;
	}

	ans = max(ans, d1 + d2);

	return d1;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(h, -1, sizeof h);

	int n, x, y;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		y = calc(i);
		if(y < i) {
			add(i, y);
			add(y, i);
		}
		
	}

	ans = 0;
	dfs(1, 0);

	cout << ans << endl;

    return 0;
}