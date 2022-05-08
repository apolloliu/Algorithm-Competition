#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 20;
int n, m, k;
int idx[N];
vector<int>p[N];
bool st[N];

int main(){
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			int x;
			cin >> x;
			p[i].push_back(x);
		}
	}

	bool success = false;
	int res = INT_MAX;

	for(int i = 0; i < 1 << n; i++){
		memset(st, false, sizeof st);
		int sum = 0;
		for(int j = 0; j < n; j++){
			if(i >> j & 1){
				sum ++;
				for(auto x : p[j])st[x] = true;
			}
		}
		int val = 0;
		for(int i = 1; i <= m; i++){
			if(st[i])val ++;
		}
		if(val == m)res = min(res, sum), success = true;
	}

	if(success)
		cout << res << endl;
	else cout << -1 << endl;

	return 0;
}