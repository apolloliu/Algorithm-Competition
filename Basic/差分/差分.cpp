#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

ll sum[N], a[N], d[N];

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
	}

	while(m--) {
		int l, r;
		cin >> l >> r;
		d[l] += 1;
		d[r + 1] -= 1;
	}

	for(int i = 1; i <= n; i++) {
		a[i] = d[i] + a[i - 1];
		cout << a[i] << (i == n ? '\n' : ' ');
	}

	return 0;
}