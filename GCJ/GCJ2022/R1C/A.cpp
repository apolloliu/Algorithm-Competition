#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
#include <unordered_map>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<string, int> psi;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int N = 123;
// #define LOCAL

int n;
string s[N], c[N];
unordered_map<char, vector<psi>>mp;
unordered_map<string, int>total;
string res;
bool st[27];
int sum;

bool check(string t) {
	memset(st, false, sizeof(st));
	int len = t.size();

	for(int i = 0; i < len; ) {
		if(st[t[i] - 'A'] == true) return false;
		int j = i;
		while(j < len && t[i] == t[j])st[t[j] - 'A'] = true, j++;
		i = j;
	}
	return true;
}

string compress(string t) {
	if(check(t)) {
		int len = t.size();
		string tmp = "";
		for(int i = 0; i < len; ) {
			int j = i;
			tmp += t[i];
			while(j < len && t[i] == t[j])j++;
			i = j;
		}
		return tmp;
	}

	return t;
}

bool valid(vector<psi> v) {
	int cnt = 0;
	for(auto t: v) {
		string str = t.first;
		int sz = str.size();
		if(str[0] != str[sz - 1])cnt++;
	}
	if(cnt > 1)return false;

	return true;
}

bool dfs(string t, bool vis[N]) {
	if(t.size() >= sum) {
		if(check(t)) {
			// cout << "str : " << t << endl;
			res = t;
			return true;
		}
		else return false;
	}

	int len = t.size();
	char c = t[len - 1];

	if(!valid(mp[c])) return false;

	bool flag = false;

	string ts = t;
	for(auto tmp: mp[c]) {
		string str = tmp.first;
		int idx = tmp.second;

		if(!vis[idx]) {
			if(str[0] == str[str.size() - 1]){
				ts += str;
				vis[idx] = 1;
				flag = true;
			}
		}
	}
	for(auto tmp: mp[c]) {
		string str = tmp.first;
		int idx = tmp.second;

		if(!vis[idx]) {
			if(str[0] != str[str.size() - 1]){
				ts += str;
				vis[idx] = 1;
				flag = true;
			}
		}
	}

	if(flag) {
		if(dfs(ts, vis)) return true;

		// for(auto tmp: mp[c]) {
		// 	string str = tmp.first;
		// 	int idx = tmp.second;

		// 	vis[idx] = 0;
		// }
	}

	if(!flag)
	for(int i = 0; i < n; i++) {
		string str = s[i];
		int idx = i;
		if(!vis[idx]) {
			vis[idx] = 1;
			if(check(t + str) && dfs(t + str, vis)) return true;
			vis[idx] = 0;
		}
	}

	return false;
}

string solve() {
	mp.clear();
	cin >> n;
	sum = 0;

	for(int i = 0; i < n; i++) {
		cin >> s[i];
		// c[i] = compress(s[i]);
		sum += s[i].size();
	}

	sort(s, s+n);


	for(int i = 0; i < n; i++){
		if(!check(s[i]))
			return "IMPOSSIBLE";
		mp[s[i][0]].push_back({s[i], i});
	}

	bool vis[N];
	for(int i = 0; i < n; i++) {
		res = "";
		string t = s[i];
		
		memset(vis, 0, sizeof vis);
		vis[i] = 1;
		if(dfs(t, vis) && res.size() == sum)
			return res;
	}

	return "IMPOSSIBLE";
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for(int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << '\n';
	}

    return 0;
}