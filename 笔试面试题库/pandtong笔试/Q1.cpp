// Q1. Fibonacci Number

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <math.h>
#include <queue>
#include <time.h>
#include <unordered_map>

using namespace std;

// int fibo(int n){
// 	std::vector<int> f(n + 1, 0);
// 	f[1] = f[2] = 1;
// 	for(int i = 3; i <= n; i++){
// 		f[i] = f[i - 1] + f[i - 2];
// 	}

// 	return f[n];
// }


template <typename T>
T fibo(T n) {
	if ((int)n == 1 || (int)n == 2)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}


int main(){
	cout << fibo(4) << endl;
	cout << fibo(5) << endl;
}
