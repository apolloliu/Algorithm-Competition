// Binary Index Tree
// Fenwick's Tree

template <class T>

const int N = 1e5 + 10;

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
		assert(i <= size);
		T sum = 0;
		while(i > 0) {
			sum += bit[i];
			i -= lowbit(i);
		}
		return sum;
	}

};
