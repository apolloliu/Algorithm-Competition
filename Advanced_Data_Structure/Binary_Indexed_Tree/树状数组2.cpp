#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
const int N = 2e5 + 10;
const int inf = 2e9;

// Binary Index Tree
// Fenwick's Tree
template <class T>

struct BIT {
	// map<T, T>bit;
	T bit[N];
	int size;

	void resize(T s) { size = s; }

	T lowbit(T x) { return x & (-x); }

	void update(T i, T x) {
		assert(i != 0);
		while(i <= size) {
			bit[i] += x;
			i += lowbit(i);
		}
	}

	T getsum(T i) {
		T sum = 0;
		while(i > 0) {
			sum += bit[i];
			i -= lowbit(i);
		}
		return sum;
	}

};


BIT<ll>c1, c2; // c1:d[i] c2:i*d[i];

// a_l a_l+1 a_l+2 ... a_r
// d_l += d, d_r+1 -= d
// a_1 = d_1, a_2 = d_1 + d_2, a_3 = d_1 + d_2 + d_3
// a_x = x * d_1 + (x - 1) * d_2 + ... + d_x
//     = sigma_i ( x - i + 1 ) * d_i
//     = sigma_i (x + 1) * d_i - sigma i * d_i

int main(int argc, char * argv[]) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int n, q;
	cin >> n >> q;

	c1.resize(n);
	c2.resize(n);

	while(q--) {
		int op, x, l, r;
		ll d;
		cin >> op;
		if(op == 1) {
			cin >> l >> r >> d;
			c1.update(l, d);
			c1.update(r + 1, -d);
			c2.update(l, l * d);
			c2.update(r + 1, (r + 1) * (-d));
		}
		else {
			cin >> x;
			cout << c1.getsum(x) * (x + 1) - c2.getsum(x) << '\n';
		}
	}

    return 0;
}