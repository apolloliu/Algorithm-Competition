// Q2. Calculate daily prices
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

void printValue() {
	vector<double>arr({100.1, 101.2, 99.8, 102.0, 103.4, 98.0, 98.2, 99.1, 99.2, 99.3});
	
	sort(arr.begin(), arr.end());

	cout << "Maximum Value: " << arr.back() << endl;
	cout << "Minimum Value: " << arr[0] << endl;
	cout << "Mean Value: " << accumulate(arr.begin(), arr.end(), 0.0) / arr.size() << endl;
	cout << "Median Value: " << (arr[4] + arr[5]) / 2. << endl;
}


int main(){
	printValue();
}