#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int s[N], v[N][N], w[N][N];
int f[N];

int main(int argc, char const *argv[])
{
	int n, V;
	cin >> n >> V;

	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		for(int j = 0; j < s[i]; j++)
			cin >> v[i][j] >> w[i][j];
	}


	for(int i = 1; i <= n; i++)
		for(int j = V; j >= 0; j--)
			for(int k = 0; k < s[i]; k++)
				if(j - v[i][k] >= 0)
				f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

	cout << f[V] << endl;

	return 0;
}