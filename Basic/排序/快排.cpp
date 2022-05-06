#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], n;

void quick_sort(int l, int r) {
	if(l >= r)return;
	int i = l, j = r, x = a[l + r + 1 >> 1], piv = l + r + 1 >> 1;
	while (i < j) {
		while(a[i] < x) i++;
		while(x < a[j]) j--;
		if(i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	quick_sort(l, j);
	quick_sort(i, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	quick_sort(0, n - 1);

	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';

	return 0;
}