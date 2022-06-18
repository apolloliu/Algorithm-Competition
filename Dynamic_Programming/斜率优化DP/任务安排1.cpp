/**
 c1, c2, c3, ..., cn
 t1, t2, t3, ..., tn
 Phase 1: s + t1 + t2 + ... + ti
 Phase 2: s + t_(i+1) + ... + tj
 ...
 Phase m: s + t_(j+1) + ... + tn
**/

// f[i] 表示当前处理到第i个任务，分批之后的最小费用
// f[i] = min(f[j] + t[i] * (c[i] - c[j]) + S * (c[n] - c[j]))
// 这里S在每一批次中都会和相应的费用相乘，可以直接写成S * (c[n] - c[j]))
#include <bits/stdc++.h>

using namespace std;

const int N = 5050;


long long f[N];
long long t[N], c[N];

int main() {

	int n, S;
	cin >> n >> S;

	for(int i = 1; i <= n; i++)
		cin >> t[i] >> c[i],
		t[i] += t[i - 1],
		c[i] += c[i - 1];

	memset(f, 0x7f, sizeof f);
	f[0] = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			f[i] = min(f[i], f[j] + t[i] * (c[i] - c[j]) + S * (c[n] - c[j]));

	cout << f[n] << endl;

	return 0;
}