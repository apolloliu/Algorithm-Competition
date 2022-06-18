//#pragma GCC optimize(2)
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 12345;
//#define LOCAL

void solve() {
	int n;
	scanf("%d", &n);
	int a, b, c;
	if(n % 3 == 0) a = n / 3, c = a - 1, b = a + 1;
	else if(n % 3 == 1) a = n / 3, b = a + 2, c = a - 1;
	else if(n % 3 == 2) a = n / 3 + 1, b = n / 3 + 2, c = n - a - b;
	// c = n / 3;
	// if(c > 1) c -= 1;
	// a = c + 2;
	// b = n - a - c;
	// while(a >= b) {
	// 	b += 1, c -= 1;
	// 	if(c == 0) a -= 1, c += 1;
	// } 
	
	printf("%d %d %d\n", a, b, c);
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	scanf("%d", &T);

	while(T--) {
		solve();
	}
	

    return 0;
}