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
const int N = 123;
#define LOCAL

string s[N];
unordered_map<char, string>hash;

void dfs(string s, int i)

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		hash[s[0]]
	}

	for(int i = 0; 1 << n; i++) {

	}
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n;
	cin >> T;

	for(int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		cout << solve() << '\n';
	}

    return 0;
}