#pragma GCC optimize(2)
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
const int N = 300000 + 10;;
// #define LOCAL

int a[N], b[N];
multiset<int>oa, ob;


inline int readint(){
    char c = getchar();
    while(!isdigit(c))c=getchar();
    int x=0;
    while(isdigit(c)){
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}


int buf[ 10 ];   //   buf的大小有输出数据的长度决定
inline void writeint(int i){
    int p = 0;
    if(i == 0)p++;
    else while(i){
        buf[ p++ ] = i % 10;
        i /= 10;
    }
    for(int j = p - 1; j >= 0; j--) putchar('0'+buf[j]);
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("1.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	// ios::sync_with_stdio(false);
	// cin.tie(0);

	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		a[i] = readint();
		// scanf("%d", &a[i]);
	}

	for(int i = 1; i <= n; i++){
		b[i] = readint();
		// scanf("%d", &a[i]);
	}

	oa.clear();
	ob.clear();

	int sum = 0;
	cout << b[1];
	oa.insert(a[1]);
	ob.insert(b[1]);

	int i = 2;
	for(; i <= n; i++) {
		while(ob.size() && oa.size()) {
			auto it = ob.begin();
			int val = *it;
			if(oa.count(val)) {
				auto ia = oa.find(val);
				oa.erase(ia);
				ob.erase(it);
			}
			else {
				break;
			}
		}

		if(!oa.size() && !ob.size()) {
			printf(" #");
		}

		// cout << oa.size() << ' ' << ob.size() <<endl;
		printf(" %d", b[i]);

		oa.insert(a[i]);
		ob.insert(b[i]);
	}

	printf("\n");

    return 0;
}