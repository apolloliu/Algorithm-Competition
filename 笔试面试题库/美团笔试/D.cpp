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
#include <deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
// const int N = 12345;
#define LOCAL

const int N = 100000 + 100;
int a[N];
multiset<int>s;

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	/* code */
	ios::sync_with_stdio(false);
	cin.tie(0);

	deque<int>q;

	int n, m, k;
	cin >> n >> m >> k;
	int sum = 0, res = 0;

	s.clear();
	int i, j;
	for(i = 1, j = 1; i <= n; i++){
		if(i - j >= m){
			if(s.count(a[j])){
				auto it = s.find(a[j]);
				s.erase(it);
				sum -= a[j];
			}
			j++;
		}
		cin >> a[i];

		if(s.size() < k){
			s.insert(a[i]);
			sum += a[i];
		}
		else if(*s.begin() < a[i]){
			sum += a[i];
			sum -= *s.begin();
			s.erase(s.begin());
			s.insert(a[i]);
		}

		if(i - j >= m - 1)res += sum, cout << sum << endl;
	}

	cout << res << endl;
    return 0;
}