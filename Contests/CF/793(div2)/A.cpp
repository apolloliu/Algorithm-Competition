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

void solve() {
	int n;
	string s;
	char c;
	cin >> n >> s;

	int sum;
	if(n & 1) {
		int m = n / 2;
		c = s[m];
		sum = 1;
		int j = m + 1;
		while(j < n && s[j] == c)j++, sum++;
		j = m - 1;
		while(j >= 0 && s[j] == c)j--, sum++;
	}
	else {
		int a = n / 2 - 1, b = n / 2;
		c = s[a];
		sum = 0;
		while(a >= 0 && s[a] == c)a--, sum++;
		while(b < n && s[b] == c)b++, sum++;
	}
	cout << sum << endl;
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