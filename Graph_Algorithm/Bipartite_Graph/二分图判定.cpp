#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int n, m, c[N];
vector<int>edge[N];

bool dfs(int i) {
	for(auto x: edge[i]) {
		if(!c[x]) {
			c[x] = 3 - c[i];
			if(!dfs(x))return false;
		}
		else if(c[x] == c[i])
			return false;
	}

	return true;
}


int main() {
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	bool flag = true;
	for(int i = 1; i <= n; i++)
		if(!c[i]) {
			c[i] = 1;
			if(!dfs(i)) {
				flag = false;
				break;	
			}
		}

	flag ? puts("Yes") : puts("No");

	return 0;
}