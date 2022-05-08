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
// #define LOCAL

int a[N], b[N];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int i;
	for(i = 0; i < n; i++)cin >> a[i];
	for(i = 0; i < n; i++)cin >> b[i];

	stack<int>s;
	int j = 0;
	for(i = 0; i < n && j < n;){
		int &x = b[i];
		if(x == a[j])j++, i++;
		else {
			if(s.size() && s.top() == x)s.pop(), i++;
			else s.push(a[j++]);
		}
	}
	// cout << i << ' ' << j << endl;

	i == n && j == n ? puts("marvelous") : puts("error");

    return 0;
}