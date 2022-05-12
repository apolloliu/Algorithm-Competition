// Q4. Simulated Exchange
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

	// 构造函数
	Order(): totalTransactionPrice(0), filledVolume(0), filledPrice(0.0){}
	Order(int id, int s, int p, int v, time_t t): orderId(id), side(s), price(p), volume(v),
		orderTime(t), totalTransactionPrice(0), filledVolume(0), filledPrice(0.0) {}
};

// Define comparasion function for buy order
struct cmpBuy
{
	bool operator() (Order oa, Order ob) {
		if (oa.price == ob.price) return oa.orderTime > ob.orderTime;
		else return oa.price < ob.price;
	}
}; 

// Define comparasion function for sell order
struct cmpSell
{
	bool operator() (Order oa, Order ob) {
		if (oa.price == ob.price) return oa.orderTime > ob.orderTime;
		else return oa.price > ob.price;
	}
};

class Exchange {
private:
	// record the total Ids which have been assigned.
	static int totalOrderId;

	// Use heap as the data structure of Buy and Sell queue
	priority_queue<Order, vector<Order>, cmpBuy>orderQueueBuy;
	priority_queue<Order, vector<Order>, cmpSell>orderQueueSell;

	// Search the specific order with hashmap
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

	// Increase total order Id
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

			// Retain unfinished order
			if(orderPassive.unfillVolume() > 0) {
				tmpSell.push_back(orderPassive);
			}

		}

		// Put all unfinished orders into the corresponding queue
		for(auto& od: tmpSell) {
			orderQueueSell.push(od);
		}

		// Push this buy order into its corresponding queue
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

			// Retain unfinished order
			if(orderPassive.unfillVolume() > 0) {
				tmpBuy.push_back(orderPassive);
			}
		}

		// Put all unfinished orders into the corresponding queue
		for(auto& od: tmpBuy) {
			orderQueueBuy.push(od);
		}

		// Push this sell order into its corresponding queue
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
	if(order.filledVolume != 0)
		// 平均成交价格 = 总成交金额 / 总成交股数
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
