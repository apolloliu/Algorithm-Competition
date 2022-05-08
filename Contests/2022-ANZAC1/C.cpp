#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 5e5 + 10;
typedef long long ll;
ll d[N], sum[N], ending[N], cnt[N];
int n;
ll p, k;

ll ok(int i){
	ll l = 0, r = 2e9;
	while(l < r){
		ll m = l + r + 1 >> 1;
		ll total = m / n * sum[n] + sum[i + (m % n - 1)] - sum[i - 1];
		// if(i == n)cout << m << endl;
		if(total <= p)l = m;
		else r = m - 1;
	}
	return l;
}

int main(){
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> p >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> d[i];
		d[i + n] = d[i];
	}

	for(int i = 1; i <= n * 2; i++)sum[i] = d[i] + sum[i - 1];

	for(int i = 1; i <= n; i++){
		ll count = ok(i);
		ll c = count % n;
		ending[i] = (i + c > n ? i + c - n : i + c);
		cnt[i] = count;
	}

	int T = 0;
	ll len, last;
	for(int j = 1; j <= n; j++){
		len = 0, last = j, T = 0;
		for(int i = 1; i <= n; i++){
			len += cnt[last];
			last = ending[last];
			T ++;
			if(len % n == 0)break;
		}
		if(len % n == 0)break;
	}

	ll res = k / T * len / n;

	k %= T;

	int t = 1;
	ll total = 0;
	while(k--){
		total += cnt[t];
		t = ending[t];
	}

	res += total / n;
	cout << res << endl;

	return 0;
}

/**
 * 
 * 
4 8 9
2
7
2
3 

2 10 2
1
1

 3 10 2
5
6
7


3 9 5
1
2
3

4 10 5
3
2
4
6
**/