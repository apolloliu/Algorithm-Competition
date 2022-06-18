//#pragma GCC optimize(2)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<ll, ll> pll;

#define endl '\n'
#define ms(s) memset(s, 0, sizeof(s))

const int inf = 1e9;
const int N = 1e6 + 10;
int tot;
int n, w;
//#define LOCAL

unordered_map<string, int>id;
map<int, vector<string>>G;
bool st[N];
vector<string>res[N];

// int cmp(const psi& a, const psi& b) {
// 	string sa = a.first, sb = b.first;
// 	if(sa.size() != sb.size())
// 		return sa.size() > sb.size();
// 	return a.second < b.second;
// }

int cmp(string a, string b) {
	if(a.size() != b.size())return a.size() > b.size();

	return id[a] < id[b];
}


bool ok(int m, vector<string> s) {
	vector<string>c[n];
	for(int i = 0; i < n; i++)c[i].clear();

	memset(st, 0, sizeof st);
	int cur_len = 0;
	int t = 0;
	while(t < n) {
		string cur_str = "";
		for(int i = 0; i < n; i++) {
			if(!st[i]) {
				st[i] = true;
				c[0].push_back(s[i]);
				cur_len = s[i].size();
				cur_str = s[i];
				break;
			}
		}
		int sum = 0;
		for(auto str: c[0])sum += str.size() + 1;
		sum --;
		if(sum > w)return false;

		for(int i = 1; i < m; i++) {
			auto it = G.lower_bound(cur_len);
			if(it == G.end())it--;
			if(it->first > cur_len)it--;
			// cout << "len " << it->first << "string: " << cur_str << endl;
			for(auto str : it->second) {
				int idx = id[str];
				if(!st[idx]) {
					c[i].push_back(str);
					st[idx] = true;
					break;
				}
			}
			
			// cout << it->second << endl;
		}
		t++;
	}
	for(int i = 0; i < n; i++)
		if(st[i])return false;

	return true;
}

void solve() {
	vector<string>vs;
	vector<string>os;

	tot = 0;
	cin >> n >> w;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		tot += s.size();

		id[s] = i;
		G[s.size()].push_back(s);
		vs.push_back(s);
		os.push_back(s);
	}

	if(tot <= w) {
		cout << os[0];
		for(int i = 1; i < n; i++) {
			cout << " " << os[i];
		}
		cout << endl;
		return;
	}

	// for(auto s: vs) {
	// 	// string s = x.first;
	// 	cout << s << endl;
	// }

	// sort(vs.begin(), vs.end(), cmp);

	int l = 1, r = n;
	while(l < r) {
		int m = l + r >> 1;
		if(ok(m, os)) r = m;
		else l = m + 1;
	}
	cout << r << endl;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
	
	// vector<vector<int>>f(n + 1, vector<int>(m + 1, 0));
	// f[0][0] = 1;
	// // f[i][j][k] 第i行，第j列，已经容纳了 个字符串，

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = )
	// }


    return 0;
}