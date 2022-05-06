#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;
const int inf = 1e9 + 10;

typedef long long ll;
unordered_map<int, int>mp;
array<int, 2>q[N];
vector<int>v;
ll sum[N]; // 前缀和

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x, c;

	cin >> n >> m;
	

	for(int i = 0; i < n; i++) {
		cin >> x >> c;
		mp[x] += c;
		v.push_back(x);
	}


	// 保存查询数据
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		q[i] = {l, r};
		// 保存的是l的左端点
		v.push_back(l - 1);
		v.push_back(r);
	}

	// 去重
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());


	// 求前缀和，不用前缀和会TLE
	for(int i = 0; i < v.size(); i++) {
		sum[i] = !i ? (ll)mp[v[i]] : sum[i - 1] + (ll)mp[v[i]];
	}

	for(int i = 0; i < m; i++) {
		auto [l, r] = q[i];
		auto it1 = lower_bound(v.begin(), v.end(), l - 1) - v.begin();
		auto it2 = lower_bound(v.begin(), v.end(), r) - v.begin();

		cout << sum[it2] - sum[it1] << '\n';
	}

	return 0;
}