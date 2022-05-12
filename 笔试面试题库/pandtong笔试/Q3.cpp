// Q3. Dynamic ticks
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

// Rounding macro definition
#define round(r) ((r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5))

// Calcalate the reaonable stock price according to the stock price range
double calculateRoundingStockPrice(double price) {
	if(price >= 0.0 && price < 0.5)
		return round(price * 1000) / 1000;
	else if(price >= 0.5 && price < 5.)
		return round(price * 100) / 100;
	else if(price >= 5. && price < 100.)
		return round(price * 2) / 2;
	else if(price >= 100. && price <= 10000.)
		return round(price);
	else return price;
}

// Parameters:
//		double price: base price
// 		int ticks: number of ticks to adjust base price. (Note: negative means to substract).
// Reutrn:
// 		order price
double calculateFinalPrice(double basePrice, int ticks) {
	double orderPrice = calculateRoundingStockPrice(basePrice);
	bool substractOrNot = ticks < 0 ? true : false;

	for(int i = 0; i < abs(ticks); ++i) {
		if(orderPrice >= 0.0 && orderPrice < 0.5)
			orderPrice += 0.001 * (substractOrNot ? -1 : 1);
		else if(orderPrice >= 0.5 && orderPrice < 5.)
			orderPrice += 0.01 * (substractOrNot ? -1 : 1);
		else if(orderPrice >= 5. && orderPrice < 100.)
			orderPrice += 0.5 * (substractOrNot ? -1 : 1);
		else if(orderPrice >= 100. && orderPrice <= 10000.)
			orderPrice += 1 * (substractOrNot ? -1 : 1);

		// calculate the reasonable price after each update
		orderPrice = calculateRoundingStockPrice(orderPrice);
	}
	
	return orderPrice;
}


int main(){
	cout << calculateFinalPrice(7, -5) << endl;
	cout << calculateFinalPrice(4.99, 5) << endl;
	cout << calculateFinalPrice(7, -6) << endl;
}