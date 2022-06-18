#include <bits/stdc++.h>

using namespace std;

stack<char>op;
stack<int>num;

void calc() {
	int n2 = num.top(); num.pop();
	int n1 = num.top(); num.pop();
	int res;
	char c = op.top(); op.pop();

	if(c == '+') res = n1 + n2;
	else if(c == '-') res = n1 - n2;
	else if(c == '*') res = n1 * n2;
	else if(c == '/') res = n1 / n2;

	num.push(res);
}

int main() {

	// 定义运算符优先级
	unordered_map<char, int> prior = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
	string s;
	cin >> s;

	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(isdigit(s[i])) {
			int j = i, sum = 0;
			while(j < n && isdigit(s[j])) sum = sum * 10 + s[j++] - '0';
			i = j - 1;
			num.push(sum);
		}
		else if(s[i] == '(') op.push(s[i]);
		else if(s[i] == ')') {
			// 把括号里的计算一遍
			while(op.size() && op.top() != '(') calc();
			op.pop();
		}
		else {
			// 从左到右计算
			while(op.size() && op.top() != '(' && prior[op.top()] >= prior[s[i]]) calc();
			op.push(s[i]);
		}
	}

	while(op.size()) calc();

	cout << num.top() << endl;

	return 0;
}