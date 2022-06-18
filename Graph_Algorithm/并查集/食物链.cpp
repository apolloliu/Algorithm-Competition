#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;
int pa[N];

int findset(int x) {
	return x == pa[x] ? pa[x] : findset(pa[x]);
}

int main() {
	int n, k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++) pa[i] = i;

	int res = 0;

	while(k--) {
		int d, x, y;
		cin >> d >> x >> y;
		if(x > n || y > n ) {
			res ++;
			continue;
		}

		if(d == 2 && x == y) {
			res++;
			continue;
		}

		if(d == 1) {
			int a = findset(x), b = findset(y);
			if(abs(a - b) == 1) {
				res ++;
				continue;
			}
			if(a < b) pa[b] = a;
			else pa[a] = b;
		}
		else {
			int a = findset(x), b = findset(y);
			if(a == b) {
				res ++;
				continue;
			}
			if(a < b) {
				pa[b] = a + 1;
			}
			else pa[a] = b + 1;
		}
	}

	cout << res << endl;
}