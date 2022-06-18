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

const int inf = 5e9;
const int N = 5e4 + 10;
//#define LOCAL



int a[N], b[N];
void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	bool flag = true;
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	vector<int>v; v.clear();
	int mval = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] < b[i]) {
			puts("NO");
			return;
		}

		if(b[i])v.push_back(a[i] - b[i]);
		else mval = max(mval, a[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	
	if(v.size() > 1)flag = false;
	if(v.size() && mval > v[0])flag= false;

	if(flag)puts("YES");
	else puts("NO");
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