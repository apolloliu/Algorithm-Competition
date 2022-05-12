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

string words[M];
char valid[5];
vector<char> invalid[5];
int have[27], notHave[27], tmp_have[27], tmp_notHave[27];
int cnt[27];
set<char>char_set;

void record(string s, string feed) {
	memset(tmp_have, 0, sizeof(tmp_have));
	memset(tmp_notHave, 0, sizeof(tmp_notHave));

	for(int i = 0; i < 5; i++) {
		int j = s[i] - 'A';
		if(feed[i] == 'G') {
			valid[i] = s[i];
			char_set.insert(s[i]);
		}
		else if(feed[i] == 'Y') {
			invalid[i].push_back(s[i]);
			tmp_have[j]++;
		}
		else {
			tmp_notHave[j]++;
		}
	}

	for(int i = 0; i < 27; i++)
		have[i] = max(have[i], tmp_have[i]),
		notHave[i] = max(notHave[i], tmp_notHave[i]);
}


void decreases() {
}

bool check(string s) {
	for(int i = 0; i < 5; i ++) {
		if(valid[i] != 'a' && valid[i] != s[i]) return false;
	}

	for(int i = 0; i < 5; i++) {
		for(auto c : invalid[i]) {
			if(c == s[i])
				return false;
		}
	}

	memset(cnt, 0, sizeof cnt);

	for(int i = 0; i < 5; i++) {
		// if(valid[i] != 'a' && valid[i] == s[i]) continue;

		int id = s[i] - 'A';
		cnt[id]++;
	}


	for(int i = 0; i < 27; i++){
		if(cnt[i] < have[i]){
			// cout << char(i + 'A') << ' ' << cnt[i] << ' ' << have[i] << endl;
			return false;
		}
	}

	for(int i = 0; i < 27; i++){
		if(!have[i] && !char_set.count(char('A' + i))) {
			if(notHave[i] && cnt[i]) {
				// cout << "nohave: " << notHave[i] << ' ' << "cnt: " << cnt[i] << endl; 
				return false;
			}
		}
		// else if(cnt[i] > notHave[i]){
		// 	return false;
		// }
		if(have[i] && notHave[i]) {
			if(cnt[i] != have[i])
				return false;
		}
	}

	// memset(cnt, 0, sizeof cnt);
	// for(int i = 0; i < 5; i++) {
	// 	int id = s[i] - 'A';

	// }


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

	string s, feed;
	int n, w;
	cin >> n >> w;

	for(int i = 0; i < 5; i++)valid[i] = 'a';

	for(int i = 0; i < n; i++) {
		cin >> s >> feed;
		record(s, feed);
	}


	// cout << "have" << endl;
	// for(int i = 0; i < 27; i++)
	// 	cout << char(i + 'A') << ' ' << have[i] << endl;

	// cout << "nothave" << endl;
	// for(int i = 0; i < 27; i++)
	// 	cout << char(i + 'A') << ' ' << notHave[i] << endl;

	vector<string>res;

	while(w--) {
		cin >> s;
		if(check(s))res.push_back(s);
	}

	for(auto str: res)
		cout << str << endl;

    return 0;
}