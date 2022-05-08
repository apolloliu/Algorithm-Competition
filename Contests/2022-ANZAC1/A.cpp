#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 4;
int idx[N];

int main(){
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n, m;
	cin >> n >> m;
	int res = 0;
	int sum = m;
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s.size() == 1){
			int t = s[0] - '0';
			if(sum < t)res ++, sum = m, sum -= t;
			else sum -= t;
		}
		else {
			int t = s[0] - '0';
			t ++;
			if(sum < t)res ++, sum = m, sum -= t;
			else sum -= t;
		}
	}

	cout << res << endl;

	return 0;
}