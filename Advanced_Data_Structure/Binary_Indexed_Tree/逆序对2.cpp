#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 10;
const int inf = 2e9;

typedef long long ll;
#define lowbit(x) ((x) & (-x))

ll a[N], bit[N];
vector<int>Q[N];
int n, q;

void add(int i, ll x) {
	while(i <= n) {
		bit[i] += x;
		i += lowbit(i);
	}
}

ll get_sum(int i) {
	ll res = 0;

	while(i > 0) {
		res += bit[i];
		i -= lowbit(i);
	}

	return res;
}

int main(int argc, char * argv[]) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	ll res = 0;

	// 方法1：
	// for(int i = 1; i <= n; i++) {
	// 	cin >> a[i];
	// 	a[i] = n + 1 - a[i];
	// 	res += get_sum(a[i]);
	// 	add(a[i], 1);
	// }

	// 方法2：
	for(int i = n; i >= 1; i--) {
		res += get_sum(a[i]);
		add(a[i], 1);
	}

	cout << res << endl;

    return 0;
}