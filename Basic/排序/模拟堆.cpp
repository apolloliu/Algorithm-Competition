#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

class Heap {
private:
	// n is heap size
	int h[N], n;

public:
	void init() {
		n = 0;
	}

	// 替换或者删除任意位置上的元素才会用到
	void up(int x) {
		while(x > 1) {
			int fa = x / 2;
			if(h[fa] > h[x]) {
				swap(h[fa], h[x]);
			}
			x /= 2;
		}
	}

	void down(int x) {
		
		while(x <= n) {
			int idx = x, val = h[x];
			int lf = x * 2, rf = x * 2 + 1;

			if(lf <= n && val > h[lf]) {
				idx = lf;
				val = h[lf];
			}

			if(rf <= n && val > h[rf]) {
				idx = rf;
				val = h[rf];
			}

			// swap
			swap(h[x], h[idx]);
			if(x == idx) break;
			x = idx;
		}
	}

	// 插入一个数 x
	void insert(int x) {
		h[++n] = x;
		up(n);
	}

	// 输出当前集合中的最小值
	int get_minimum() {

		// for(int i = 1; i <= n; i++)
		// 	cout << h[i] << ' ';
		// cout << endl;
		
		return h[1];
	}

	// 删除当前集合中的最小值（数据保证此时的最小值唯一）
	void delete_minimum() {
		// h[1] is the minimum
		h[1] = h[n];
		n--;
		down(1);
	}

	// 删除第 k 个插入的数
	void delete_k(int k) {
		h[k] = h[n];
		n--;

		down(k);
		up(k);
	}

	// 修改第 k 个插入的数，将其变为 x
	void update(int k, int x) {
		h[k] = x;

		down(k);
		up(k);
	}

}heap;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	heap.init();

	int n, x, k;

	cin >> n;
	while(n--) {
		string op;
		cin >> op;

		if(op == "I") {
			cin >> x;
			heap.insert(x);
		}
		else if(op == "PM") {
			cout << heap.get_minimum() << endl;
		}
		else if(op == "DM") {
			heap.delete_minimum();
		}
		else if(op == "D") {
			cin >> k;
			heap.delete_k(k);
		}
		else if(op == "C") {
			cin >> k >> x;
			heap.update(k, x);
		}
	}

	return 0;
}