/**
 c1, c2, c3, ..., cn
 t1, t2, t3, ..., tn
 Phase 1: s + t1 + t2 + ... + ti
 Phase 2: s + t_(i+1) + ... + tj
 ...
 Phase m: s + t_(j+1) + ... + tn
**/

/**
f[i] 表示当前处理到第i个任务，分批之后的最小费用
f[i] = min(f[j] + t[i] * (c[i] - c[j]) + S * (c[n] - c[j]))
这里S在每一批次中都会和相应的费用相乘，可以直接写成S * (c[n] - c[j])


斜率优化过程：
令 f[i] = f[j] + t[i] * (c[i] - c[j]) + S * (c[n] - c[j])
f[i] = f[j] + t[i] * c[i] - t[i] * c[j] + S * c[n] - S * c[j]
f[i] = f[j] + c[j] * (-t[i] - S) + t[i] * c[i] + S * c[n]
则,
f[j] = (t[i] + S) * c[j] + f[i] - t[i] * c[i] - S * c[n]
y    = k * x + b
由于k不再具有单调性，但是x仍具有单调性，也就是说x是递增的，仍然可以利用凸包算法筛选合理的点（能达到最优解，即满足斜率值大于等于当前斜率的线段的左边的点，这里需要利用二分来求解）

11首(查询)：
(f[q[hh + 1]] - f[q[hh]]) / (c[q[hh + 1]] - c[q[hh]]) <= t[i] + S
这里不删除点，但是需要二分找到最优点

尾(插入)：
(f[q[tt]] - f[q[tt - 1]]) / (c[q[tt]] - c[q[tt - 1]]) >= (f[i] - f[q[tt]]) / (c[i] - c[q[tt]])
**/

#include <bits/stdc++.h>

using namespace std;
// typedef __int128 ll;
typedef long long ll;
const int N = 3e5 + 10;
ll t[N], c[N], f[N], q[N];


int main() {

	int n, S;
	cin >> n >> S;

	for(int i = 1; i <= n; i++)
		cin >> t[i] >> c[i],
		t[i] += t[i - 1],
		c[i] += c[i - 1];

	int hh = 0, tt = 0;
	q[0] = 0;

	memset(f, 0x7f, sizeof f);
	f[0] = 0;

	for(int i = 1; i <= n; i++) {
		int l = hh, r = tt;
		while(l < r) {
			int m = l + r >> 1;
			if((f[q[m + 1]] - f[q[m]]) >= double(t[i] + S) * (c[q[m + 1]] - c[q[m]])) r = m;
			else l = m + 1;
		}
		int j = q[r];
		f[i] = f[j] + t[i] * (c[i] - c[j]) + S * (c[n] - c[j]);
		// 这里的等号不能省
		// double 是为了防止溢出
		while(hh < tt && double(f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt]]) >= double(f[i] - f[q[tt]]) * (c[q[tt]] - c[q[tt - 1]]))tt--;
		q[++tt] = i;
	}

	cout << f[n] << endl;
	return 0;
}