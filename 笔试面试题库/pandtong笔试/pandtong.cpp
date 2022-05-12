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

// Q1. Fibonacci Number
// int fibo(int n){
// 	std::vector<int> f(n + 1);
// 	f[0] = f[1] = f[2] = 1;
// 	for(int i = 1; i <= n; i++){
// 		f[i] = f[i - 1] + f[i - 2];
// 	}
// }


template <typename T>
T fibo(T n) {
	vector<T> f(n + 1, 0);
	f[1] = f[2] = 1;
	for(int i = 3; i <= n; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}


// Q2. Calculate daily prices

void printValue() {
	vector<double>arr({100.1, 101.2, 99.8, 102.0, 103.4, 98.0, 98.2, 99.1, 99.2, 99.3});
	
	sort(arr.begin(), arr.end());

	cout << "Maximum Value: " << arr.back() << endl;
	cout << "Minimum Value: " << arr[0] << endl;
	cout << "Mean Value: " << accumulate(arr.begin(), arr.end(), 0.0) / arr.size() << endl;
	cout << "Median Value: " << (arr[4] + arr[5]) / 2. << endl;
}


// Q3. Dynamic ticks

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


// int main(){
// 	cout << fibo(4) << endl;
// 	printValue();
// 	cout << calculateFinalPrice(4.99, 5) << endl;
// }


// Q4. Simulated Exchange

struct Order
{
	int orderId; // 订单编号
	int side; // ⽅向，0 is buy, 1 is sell
	int price; // 价格
	int volume; // 数量
	double filledPrice; // 平均成交价格
	int filledVolume; // 累计成交数量
	int unfillVolume()
	{
		return volume - filledVolume;
	}

	time_t orderTime; // 订单提交时间
	int totalTransactionPrice; // 总成交价格

	Order(): totalTransactionPrice(0), filledVolume(0), filledPrice(0.0){}
	Order(int id, int s, int p, int v, time_t t): orderId(id), side(s), price(p), volume(v), orderTime(t), totalTransactionPrice(0), filledVolume(0), filledPrice(0.0) {}
};

// Define comparasion function for buying case
struct cmpBuy
{
	bool operator() (Order oa, Order ob) {
		if (oa.price == ob.price) return oa.orderTime > ob.orderTime;
		else return oa.price < ob.price;
	}
}; 

// Define comparasion function for selling case
struct cmpSell
{
	bool operator() (Order oa, Order ob) {
		if (oa.price == ob.price) return oa.orderTime > ob.orderTime;
		else return oa.price > ob.price;
	}
};

class Exchange {
private:
	static int totalOrderId;
	priority_queue<Order, vector<Order>, cmpBuy>orderQueueBuy;
	priority_queue<Order, vector<Order>, cmpSell>orderQueueSell;
	unordered_map<int, Order>orderMap;

public:
	// InputOrder receives order, and return assigned order Id.
	// Parameters:
	// 		int side: 0 is buy, 1 is sell
	// 		int volume: order's quantity
	// 		int price: order's price
	// Return:
	// 		int: order Id
	int inputOrder(int side, int volume, int price);
	// QueryOrderTrade queries order's trade volume and average price.
	// Parameters:
	// 		int orderId: assigned order Id
	// Return:
	// 		Order order: order stored in exchange
	Order& QueryOrder(int orderId);

	// Constructor function
	Exchange();
};


int Exchange::totalOrderId = 0; // Assign the static variable with 0

int Exchange::inputOrder(int side, int volume, int price) {
	// Calculate current time
	time_t current_time = time(NULL);

	++totalOrderId;

	// Declare new order object
	Order orderActive = Order(totalOrderId, side, price, volume, current_time);

	if (side == 0) { // buy order
		vector<Order>tmpSell;

		// match buy order with all sell orders
		while(orderQueueSell.size() && orderActive.unfillVolume() > 0) {
			Order orderPassive = orderQueueSell.top();
			orderQueueSell.pop();

			// Check whether it can be matched
			if(orderActive.price >= orderPassive.price){
				
				// transactionVolume is the volume of this transaction
				int transactionVolume = min(orderActive.unfillVolume(), orderPassive.unfillVolume());
				// transactionPrice is the price of this transaction
				int transactionPrice = orderPassive.price;

				orderActive.filledVolume += transactionVolume;
				orderPassive.filledVolume += transactionVolume;

				// Calculate the total transaction price
				orderActive.totalTransactionPrice += transactionVolume * transactionPrice;
				orderPassive.totalTransactionPrice += transactionVolume * transactionPrice;

				// Update the passvie order
				orderMap[orderPassive.orderId] = orderPassive;
			}

			if(orderPassive.unfillVolume() > 0) {
				tmpSell.push_back(orderPassive);
			}

		}

		// Put all unfinished orders into the corresponding queue
		for(auto& od: tmpSell) {
			orderQueueSell.push(od);
		}

		// Push an order into its corresponding queue
		if (orderActive.unfillVolume() > 0) {
			orderQueueBuy.push(orderActive);
		}
	}
	else { // sell order
		vector<Order>tmpBuy;

		// match sell order with all buy orders
		while(orderQueueBuy.size() && orderActive.unfillVolume() > 0) {
			Order orderPassive = orderQueueBuy.top();
			orderQueueBuy.pop();
			// cout << orderPassive.orderId << ' ' << orderPassive.price << endl;

			// Check whether it can be matched
			if(orderActive.price <= orderPassive.price){
				
				// transactionVolume is the volume of this transaction
				int transactionVolume = min(orderActive.unfillVolume(), orderPassive.unfillVolume());
				// transactionPrice is the price of this transaction
				int transactionPrice = orderPassive.price;

				orderActive.filledVolume += transactionVolume;
				orderPassive.filledVolume += transactionVolume;

				// Calculate the total transaction price
				orderActive.totalTransactionPrice += transactionVolume * transactionPrice;
				orderPassive.totalTransactionPrice += transactionVolume * transactionPrice;

				// Update the passvie order
				orderMap[orderPassive.orderId] = orderPassive;
			}

			if(orderPassive.unfillVolume() > 0) {
				tmpBuy.push_back(orderPassive);
			}
		}

		// Put all unfinished orders into the corresponding queue
		for(auto& od: tmpBuy) {
			orderQueueBuy.push(od);
		}

		// Push an order into its corresponding queue
		if (orderActive.unfillVolume() > 0) {
			orderQueueSell.push(orderActive);
		}
	}

	// Update current order info
	orderMap[totalOrderId] = orderActive;

	return totalOrderId;
}

Exchange::Exchange() {
	orderMap.clear();
}

Order& Exchange::QueryOrder(int orderId) {
	auto& order = orderMap[orderId];
	// cout << order.totalTransactionPrice << ' ' << order.filledVolume << endl;

	// Calculate the filledPrice if and only if the value of filledVolume is not 0
	if(order.filledVolume != 0)s
		order.filledPrice = (double)order.totalTransactionPrice * 1. / order.filledVolume;

	return order;
}


int main() {
	Exchange ex;
	std::vector<int> orderIds;
	orderIds.push_back(ex.inputOrder(0, 1, 100));
	orderIds.push_back(ex.inputOrder(0, 2, 101)); 
	orderIds.push_back(ex.inputOrder(0, 3, 102));
	orderIds.push_back(ex.inputOrder(1, 4, 100)); 
	orderIds.push_back(ex.inputOrder(1, 5, 101));
	orderIds.push_back(ex.inputOrder(1, 6, 102));

	for (auto& orderId : orderIds)
	{
		auto& order = ex.QueryOrder(orderId);
		std::cout << "orderId: " << orderId << " filledVolume: " <<
		order.filledVolume << " filledPrice: "<< order.filledPrice << std::endl;
	}

	return 0; 
}
