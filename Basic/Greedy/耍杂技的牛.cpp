#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

typedef long long ll;
typedef pair<ll, ll> pii;

pii p[N];


int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n, [&](pii a, pii b) {
		return a.first + a.second < b.first + b.second;
	});

	ll res = -1e18, sum = 0;
	for(int i = 0; i < n; i++) {
		res = max(res, sum - p[i].second);
		sum += p[i].first;
	}

	cout << res << endl;

	return 0;
}