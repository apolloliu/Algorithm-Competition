#include<bits/stdc++.h>

using namespace std;


const int N = 1e5 + 10;
typedef unsigned long long ull;


// 字符串hash模板，输入字符串之后，记得计算hash值
struct string_hash {
	int size;  // 字符串长度
	char s[N]; // 输入的字符串，从1开始
	int base = 131; // base 取 131或者 13331， mod = 2^64
	vector<ull>h, p; // h 表示字符串前缀的hash值，p表示p进制数

	void resize(int n) {
		size = n;
		h.resize(size + 1, 0);
		p.resize(size + 1, 0);
	}

	// 计算前缀字符串的hash值
	void calc_hash() {
		p[0] = 1;
		for(int i = 1; i <= size; i++) {
			p[i] = p[i - 1] * base;
			// 字符的值不能为0
			assert(s[i] != 0);
			h[i] = h[i - 1] * base + s[i];
		}
	}

	// 计算某段字符串的hash值
	ull get(int l, int r) {
		return h[r] - h[l - 1] * p[r - l + 1];
	}
};


string_hash strHash;

int main() {

	int n, m;
	scanf("%d%d", &n, &m);

	strHash.resize(n);
	scanf("%s", strHash.s + 1);
	strHash.calc_hash();

	while(m--) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if(strHash.get(x1, y1) == strHash.get(x2, y2)) puts("Yes");
		else puts("No");
	}

	return 0;
}