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
	int n, m;
	cin >> n >> m;
	vector<vector<int>>a(n + 1, vector<int>(m + 1, 0));
	// for(int i = 0; i < n; )
	bool invalid = false;
	int p1, p2;
	p1 = p2 = 0;
	for(int i = 1; i <= n; i++) {
		int sum = 0;
		vector<int>b(m + 1, 0);
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			b[j] = a[i][j];
		}
		int d1, d2;
		d1 = d2 = 0;
		sort(b.begin() + 1, b.end());
		for(int j = 1; j <= m; j++){
			if(a[i][j] != b[j]) {
				sum++;
				if(j > d1) d2 = d1, d1 = j;
				else if(j >= d2) d2 = j;
			}
		}
		if(sum >= 3) invalid = true;
		// else if(p1 && p2 && d1 && d2) {
		// 	if(p1 != d1 && p2 != d2)invalid = true;
		// }
		if(d1 && d2)
		p1 = d1, p2 = d2;
	}

	// cout << "p: " << p1 << ' ' << p2 << endl;
	if(p1 && p2)
	for(int i = 1; i <= n; i++) {
		swap(a[i][p1], a[i][p2]);
		vector<int>b(a[i].begin() + 1, a[i].end());
		sort(b.begin(), b.end());
		for(int j = 1; j <= m; j++)
			if(a[i][j] != b[j - 1]) {
				cout << "-1\n";
				return;
			}
	}

	if(invalid) cout << "-1\n";
	else {
		
		if(!p1 && !p2)cout << "1 1\n";
		else cout << p2 << ' ' << p1 << endl;
	}

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