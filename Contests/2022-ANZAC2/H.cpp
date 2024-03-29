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
const int N = 1e5 + 10;
//#define LOCAL


ll a[N], d[N];


void insert(int l, int r) {
	d[l] += 1;
	d[r + 1] -= 1;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int n, c;
	cin >> n >> c;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	int s, e;
	s = e = 1;
	ll sum = a[1];

	while(s <= n) {
		if(s <= e)insert(s, e);
		if(e + 1 > n)sum -= a[s++];
		else if(sum + a[e + 1] > c)sum -= a[s++];
		else {
			e++;
			sum += a[e];
		}
	}

	for(int i = 1; i <= n; i++)
		d[i] += d[i - 1], cout << d[i] << endl;

    return 0;
}