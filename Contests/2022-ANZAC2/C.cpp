//#pragma GCC optimize(2)
// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define ms(s) memset(s, 0, sizeof(s))

const int inf = 1e9;
const int N = 15, M = 1e4 + 10;
//#define LOCAL

int n, w;
int cnt[27];
string g[N], f[N];


string calc(string origin, string s) {
	string res = "-----";

	for(int i = 0; i < 5; i++)
		if(origin[i] == s[i])
			res[i] = 'G';

	memset(cnt, 0, sizeof cnt);

	for(int i = 0; i < 5; i++) {
		if(res[i] == 'G') continue;

		int id = origin[i] - 'A';
		cnt[id] ++;
	}

	for(int i = 0; i < 5; i++) {
		if(res[i] == 'G')continue;

		int id = s[i] - 'A';
		if(cnt[id]) {
			res[i] = 'Y';
			cnt[id] --;
		}
	}

	return res;
}

bool check(string s) {
	for(int i = 0; i < n; i++) {
		string res = calc(s, g[i]);
		// cout << res << endl;
		if(res != f[i])
			return false;
	}

	return true;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> w;

	for(int i = 0; i < n; i++)
		cin >> g[i] >> f[i];


	vector<string>res;
	string s;
	for(int i = 0; i < w; i++){
		cin >> s;
		if(check(s)) res.push_back(s);
	}

	for(auto str: res)
		cout << str << endl;

    return 0;
}