#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
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

	cin >> n >> q;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		add(i, a[i]);
	}

	while(q--) {
		int op, x, d;
		cin >> op;
		if(op == 1) {
			cin >> x >> d;
			int diff = d - a[x];
			add(x, diff);
			a[x] = d;
		}
		else {
			cin >> x;
			cout << get_sum(x) << '\n';
		}
	}


    return 0;
}