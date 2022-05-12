#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10;

char p[N], s[M];
int ne[N];
int n, m;

void get_next() {
	// ne[1] = 1;
	for(int i = 2, j = 0; i <= n; i++) {
		while(j && p[i] != p[j + 1]) j = ne[j];
		if(p[i] == p[j + 1]) j++;
		ne[i] = j;
	}
}

void KMP() {
	get_next();

	for(int i = 1, j = 0; i <= m; i++) {
		while(j && s[i] != p[j + 1]) j = ne[j];
		if(s[i] == p[j + 1]) j++;
		if(j == n) {
			// 这里执行任何想要的操作
			cout << i - n << ' ';
			j = ne[j];
		}
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> p + 1;
	cin >> m >> s + 1;

	KMP();
	
	return 0;
}