#include<bits/stdc++.h>

using namespace std;
#define fi first
#define se second


typedef long long ll;
typedef pair<int, int> ii;
int cmp(const ii& a, const ii& b){
	if(a.fi != b.fi)return a.fi > b.fi;
	return a.se < b.se;
}

const int N = 10, M = 100000;

int res;
int n, m, c;
// int num[N];
// ii v[N][M];


void dfs(int i, int sum, int pri, std::vector<std::vector<ii>>& v){
	if(i == n){
		// cout << sum << endl;
		if(pri <= m)res = max(res, sum);
		return;
	}

	for(int j = 0; j < v[i].size(); j++){
		if(pri + v[i][j].se <= m && sum + v[i][j].fi > res)
			dfs(i + 1, sum + v[i][j].fi, pri + v[i][j].se, v);
	}
}

int main(){
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, q;
	cin >> n >> m;
	std::vector<std::vector<ii>> v(n);
	for(int i = 0; i < N; i++)v[i].clear();
	for(int i = 0; i < n; i++){
		cin >> q;
		std::vector<ii> t;

		for(int j = 0; j < q; j++){
			cin >> x >> y;
			t.push_back({y, x});
			// cout << x << endl;
			// v[i][j] = {y, x};
		}
		// sort(t.begin(), t.end(), cmp);
		v[i] = t;
	}

	res = 0;
	dfs(0, 0, 0, v);
	cout << res << endl;

	return 0;
}