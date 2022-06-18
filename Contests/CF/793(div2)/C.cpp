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
const int N = 2e5 + 10;
//#define LOCAL

int d[N], a[N], b[N];
int b_search(int x,int s,int e){
    while(s < e){
        int mid = s+(e-s)/2;
        if(d[mid] >= x) e = mid;
        else s = mid+1;
    }
    return s;
}
int LIS(int A[],int n){
    memset(d,0,sizeof d);
    int len = 1;
    d[1] = A[0];
    for(int i = 1;i < n;i++){
        if(A[i] >= d[len])  d[++len] = A[i];
        else{
            int p = b_search(A[i],1,len);
            d[p] = A[i];
        }
    }
//  for(int i = 0;i < len;i++)  cout << d[i+1]<<" ";
    return len;
}
 

int calc(int list[], int n) {
	list[0] = -1; d[0] = -1;
	int len = 0;
	for (int i = 1; i <= n; i++) {
		if (list[i] != d[len]) {
			int pos = lower_bound(d + 1, d + len + 1, list[i]) - d;
			d[pos] = list[i];
			if (list[i] > d[len]) len++;
		}
	}
	return len;
}

map<int, int>cnt;
void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i], b[n - i + 1] = a[i];
	int res = 1;
	// res = min(res, calc(a, n));
	// res = min(res, calc(b, n));

	cnt.clear();
	for(int i = 1; i <= n; i++)
		cnt[a[i]]++;
	int odd = 0, even = 0;
	for(auto x : cnt) {
		auto [k, v] = x;
		if(v == 1)odd++;
		else even++;
	} 
	// cout << "odd: " << odd << " even: " << even<< endl;
	res = max(res, even + (odd + 1) / 2);
	// res = even + odd / 2;

	cout << res << endl;

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
	cin >> T;

	while(T--) {
		solve();
	}
	

    return 0;
}