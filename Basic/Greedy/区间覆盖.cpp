// 排序一次即可
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

const int inf = 1e9;
typedef pair<int,int> pii;
pii p[N];

int main() {
	int s, t;
	int n;
	cin >> s >> t >> n;

	for(int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	sort(p, p + n);

	int res = -1, sum = 0;

	int i = 0, l, r;
	l = r = -inf;
	while(i < n && p[i].first <= s) {
		if(p[i].second >= r) {
			l = p[i].first;
			r = p[i].second;
		}
		i++;
	}

	sum++;

	bool flag = true;

	while(i < n && r < t) {
		int L = l, R = r;
		while(i < n && p[i].first <= r) {
			if(p[i].second > R) {
				L = p[i].first;
				R = p[i].second;
			}
			i++;
		}
		if(R > r) {
			l = L, r = R;
			sum++;
		}
		else i++;
	}

	if(r >= t)res = sum;

	cout << res << endl;
}