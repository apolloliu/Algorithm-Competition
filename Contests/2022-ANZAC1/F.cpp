#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 50, M = 4;
int idx[N];

// int dp[N][M][2]; // dp[i][j], 当前第i个字符，为c[j][k]，合法的方案数量

/***
 * dp[i][j]     到当前第i个字符，长度为j的， dp[i][j] += dp[i - j][i - j];
 * 
 * */

long long dp[N][N];
char c[M][2] = {{'(', ')'}, {'[', ']'}, {'<', '>'}, {'{', '}'}};
int cnt[M];

bool check(string s, int i, int j){
	stack<char>st;
	for(int k = i; k <= j; k++){
		if(s[k] == '?')st.push(s[k]);
		else if(s[k] == c[0][0] || s[k] == c[1][0] || s[k] == c[2][0] || s[k] == c[3][0])st.push(s[k]);
		else if(s[k] == c[0][1]){
			if(st.empty() || st.top() != '?' || st.top() != c[0][0])return false;
			st.pop();
		}
		else if(s[k] == c[1][1]){
			if(st.empty() || st.top() != '?' || st.top() != c[1][0])return false;
			st.pop();
		}
		else if(s[k] == c[2][1]){
			if(st.empty() || st.top() != '?' || st.top() != c[2][0])return false;
			st.pop();
		}
		else if(s[k] == c[3][1]){
			if(st.empty() || st.top() != '?' || st.top() != c[3][0])return false;
			st.pop();
		}
	}
	while(st.size()){
		if(st.top() == '?')st.pop();
		else return false;
	}

	return true;
}

int calc(string s, int l, int r){
	if(s[l] == '?' && s[r] == '?')return 4;

	for(int k = 0; k < M; k++){
		if(s[l] == c[k][0] && s[r] == c[k][1])return 1;
		else if(s[l] == '?' && s[r] == c[k][1])return 1;
		else if(s[l] == c[k][0] && s[r] == '?')return 1;
	}

	return 0;
}

int main(){
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	s = '$' + s;


	for(int i = 0; i <= n ; i++){
      dp[i + 1][i] = 1;
   }


	for(int len = 2; len <= n; len ++){
		for(int l = 1; l <= n; l++){
			int r = l + len - 1;
			// if(len == 1)dp[l][r] = 1;
			if(len == 2){
				dp[l][r] = calc(s, l, r);
			}
			else {
				for(int k = l + 1; k < r; k++){
					// if(check(s, l + 1, k - 1) && check(s, k + 1, r)){
						// if
						dp[l][r] += dp[l + 1][k - 1] * dp[k + 1][r] * calc(s, l, k);
					// }
				}
				// if(l + 1 <= r - 1 && check(s, l + 1, r - 1))
					dp[l][r] += dp[l + 1][r - 1] * calc(s, l, r);
			}
		}
	}

	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++){
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	cout << dp[1][n] << endl;

	return 0;
}

