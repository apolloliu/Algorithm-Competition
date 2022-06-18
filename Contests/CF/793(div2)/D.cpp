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
	cin >> n >> s;

	vector<int>G[n + 1];
	for(int i = 1; i <= n; i++)G[i].clear();

	vector<int>odd, even;
	for(int i = 0; i < n; i++)
		if(s[i] == '0')even.push_back(i + 1);
		else odd.push_back(j + 1);

	
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