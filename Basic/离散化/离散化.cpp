#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];
vector<int>val;
int n;

// 方法1:
// 时间：247ms
void solve1() {
	for(int i = 1; i <= n; i++) {
		val.push_back(a[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());

	for(int i = 1; i <= n; i++) {
		int rk = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
		cout << rk + 1 << ' ';
	}
	cout << '\n';
}


// 方法2: 最慢
// 时间：536ms
map<int, int>id;
set<int>s;
void solve2() {
	for(int i = 1; i <= n; i++) {
		s.insert(a[i]);
	}

	int rk = 0;
	for(auto x : s)
		id[x] = ++rk;

	for(int i = 1; i <= n; i++)
		cout << id[a[i]] << ' ';
	cout << '\n';
}


// 方法3: 最快
// 时间：175ms
pair<int, int>p[N];
void solve3() {
	for(int i = 1; i <= n; i++) {
		p[i] = {a[i], i};
	}

	sort(p + 1, p + n + 1);

	int rk = 0;
	for(int i = 1; i <= n; i++) {
		if(i == 1 || p[i].first != p[i - 1].first) rk++;
		a[p[i].second] = rk;
	}

	for(int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		val.push_back(a[i]);
	}

	// 方法1: 
	// solve1();

	// 方法2: 最慢
	// solve2();

	// 方法3: 最快
	solve3();

	return 0;
}