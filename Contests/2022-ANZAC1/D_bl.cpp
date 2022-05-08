#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int N = 65;
// #define LOCAL

int n, m;
int a[N][N];
int n0, n1, n2;

ll calc() {
	ll res = 1e18;
	if(n == 1) {
		ll mult1 = 1;
		for(int i = 1; i < m; i ++) {
			mult1 *= a[1][i];
			ll mult2 = 1;
			for(int j = i + 1; j <= m; j++) {
				mult2 *= a[1][j];
			}
			res = min(res, abs(mult1 - mult2));
		}
	}
	else {
		ll mult1 = 1;
		for(int i = 1; i < n; i ++) {
			mult1 *= a[i][m];
			ll mult2 = 1;
			for(int j = i + 1; j <= n; j++) {
				mult2 *= a[j][m];
			}
			res = min(res, abs(mult1 - mult2));
		}
	}

	return res;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	n0 = n1 = n2 = 0;

	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			// cout << a[i][j] << ' ';
			if(!a[i][j])n0++;
			else if(a[i][j] == 2)n2++;
			else if(a[i][j] == 1)n1++;
		}
		// cout << endl;
	}

	// cout << "2: " << n2 << endl;

	ll res = 0;
	if(n == 1 || m == 1)
		cout << calc() << endl;
	else {
		if(n0 == 0){
			ll b = 1LL << (n2 / 2), c = 1LL << (n2 - n2 / 2);
			// cout << (n2 / 2) << ' ' << (n2 - n2 / 2) << endl;
			// cout << (1 << 31) << ' ' << (1 << 32) << endl;
			cout << abs(b - c) << endl;
		}
		else {
			if(n0 >= 2)cout << 0 << endl;
			else cout << (n1 ? 1 : 2) << endl;
		}
	}


    return 0;
}