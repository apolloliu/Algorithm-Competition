#include <bits/stdc++.h>

using namespace std;
const int N = 300000 + 10;

int a[N];

int main() {
	freopen("1.txt", "w", stdout);

	srand(time(0));

	int n, m;

	// n = rand() % 300000 + 1;

	n = 300000;
	cout << n << endl;

	for(int i = 0; i < n; i++){
		a[i] = rand();
		cout << a[i] << ' ';
	}

	cout << endl;
	random_shuffle(a, a + n);

	for(int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
	
	return 0;
}