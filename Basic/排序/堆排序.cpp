#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

// n is heap size
int h[N], n, m;

void up(int x) {
	while(x > 1) {
		int fa = x / 2;
		if(h[fa] > h[x]) {
			swap(h[fa], h[x]);
		}
		x /= 2;
		// cout << x << ' ';
	}
	// cout << endl;
}

void down(int x) {
	
	while(x <= n) {
		int idx = x, val = h[x];
		int lf = x * 2, rf = x * 2 + 1;

		if(lf <= n && val > h[lf]) {
			idx = lf;
			val = h[lf];
		}

		if(rf <= n && val > h[rf]) {
			idx = rf;
			val = h[rf];
		}

		// swap
		swap(h[x], h[idx]);
		if(x == idx) break;
		x = idx;
	}
}

void build_heap() {
	for(int i = n / 2; i; i--)
		down(i);
}

void print_minimum() {
	// h[1] is the minimum
	cout << h[1] << ' ';
	h[1] = h[n];
	n--;
	down(1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	build_heap();

	while(m--) {
		print_minimum();
	}

	return 0;
}