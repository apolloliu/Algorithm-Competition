#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 4;
int n, m, k;
int idx[N];
char c[N][N];
int a[N];

int main(){
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	string s;
	cin >> s;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			c[i][j] = '.';

	for(int i = 0; i < N; i ++){
		a[i] = s[i] + '0';
		int j = 3;
		while(a[i]){
			if(a[i] & 1)c[j][i] = '*';
			j--;
			a[i] /= 2;
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << c[i][j];
			if(j < N - 1)cout << ' ';
			if(j == 1)cout << "  ";
		}
		cout << endl;
	}

	return 0;
}