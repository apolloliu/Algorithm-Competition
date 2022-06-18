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
int sum[N];
char s[N];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	memset(sum, 0, sizeof sum);
	int b = 0, w = 0;
	int res = inf;
	int i = 1, j;
	while(i < k) {
		b += (s[i] == 'B');
		w += (s[i] == 'W');
		i++;
		// printf("i: %d\n", i);
	}
	for(j = 1; i <= n; i++, j++) {
		b += (s[i] == 'B');
		w += (s[i] == 'W');
		// while(i - j >= k) {
		// 	b += (s[i] == 'B');
		// 	w += (s[i] == 'W');
		// 	i++;
		// }
		// if(b)
		// cout << w << endl;
		res = min(res, w);
		if(j)b -= (s[j] == 'B');
		if(j)w -= (s[j] == 'W');
		// int 
		// sum[i] = sum[i - 1] + (s[i] == 'W');
	}
	printf("%d\n", res);
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
	// cin >> T;
	scanf("%d", &T);

	while(T--) {
		solve();
	}
	

    return 0;
}