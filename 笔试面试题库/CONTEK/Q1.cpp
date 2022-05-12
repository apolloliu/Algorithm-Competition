/**
Q1

1. 接口按需求实现，题目描述有点模糊，没弄懂snapshot输出那部分和两个接口是啥关系。 
2. 缺陷：我是按自己的理解去实现的接口，由于没有测试样例，没有伙伴一起讨论需求，最后无法判断是否符合要求，还请谅解。
3. main函数里提供调用示例, 可以直接运行

**/

#include<bits/stdc++.h>

using namespace std;

#define P first
#define Q second

typedef pair<int, int> PII;

// Define comparasion function for bids order
struct cmpBids
{
	bool operator() (PII& oa, PII& ob) {
		return oa.P < ob.P;
	}
}; 

// Define comparasion function for asks order
struct cmpAsks
{
	bool operator() (PII& oa, PII& ob) {
		return oa.P > ob.P;
	}
};

class Orderbook{
private:
	string type;
	priority_queue<PII, vector<PII>, cmpBids>bids; // 使用优先队列优化
	priority_queue<PII, vector<PII>, cmpAsks>asks;

public:
	Orderbook(vector<PII>& bids_N, vector<PII>& asks_N);

	vector<PII> bids_output(int L);
	vector<PII> asks_output(int L);
};

Orderbook::Orderbook(vector<PII>& bids_N, vector<PII>& asks_N) {
	for(auto bid : bids_N)bids.push(bid);
	for(auto ask : asks_N)asks.push(ask);
}

vector<PII> Orderbook::bids_output(int L) {
	vector<PII> res;

	// 撮合买单
	while(bids.size() && L) {
		auto b = bids.top();
		bids.pop();

		if(b.Q <= L){
			res.push_back({b.P, b.Q});
			L -= b.Q;
		}
		else {
			bids.push({b.P, b.Q - L});
		}
	}

	return res;
}

vector<PII> Orderbook::asks_output(int L) {
	vector<PII> res;

	// 撮合卖单
	while(asks.size() && L) {
		auto a = asks.top();
		asks.pop();

		if(a.Q <= L){
			res.push_back({a.P, a.Q});
			L -= a.Q;
		}
		else {
			asks.push({a.P, a.Q - L});
		}
	}


	return res;
}

int main(){
	// 初始数据
	vector<PII>bids = {{47, 5}, {50, 1}, {48, 3}};
	vector<PII>asks = {{58, 2}, {51, 1}, {55, 8}};

	Orderbook ob = Orderbook(bids, asks);

	// 调用接口1
	vector<PII>bid_output = ob.bids_output(5);
	for(auto b : bid_output)
		cout << b.P << ' ' << b.Q << endl;

	cout << "-------------------" << endl;

	// 调用接口1
	vector<PII>ask_output = ob.asks_output(5);
	for(auto a : ask_output)
		cout << a.P << ' ' << a.Q << endl;

	return 0;
}