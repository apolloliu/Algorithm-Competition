#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int N = 12345;
#define LOCAL

stack<int>st;

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	/* code */
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n;
	cin >> s;
	
	int i = 0;
	int sum = 0;
	while(i < n){
		while(st.size()){
			if(st.size() && s[st.top()] == '(' && s[i] == ')'){
				sum += 2;
				st.pop();
			}
			else {
				st.push(i);
			}
		}
	}
	while(i < n){

		i++;
	}

	if(st.size() <= 1)cout << sum << endl;
	else {
		sum = 0;
		int t = st.top();
		st.pop();
		std::vector<int> v;
		v.push_back(t - 0);
		while(st.size() > 1){
			while(st.size() > 1 && st.top() == t + 1)st.pop();
			v.push_back(st.top() - t - 1);
			t = st.top();
			st.pop();
		}
		v.push_back(n - 1 - st.top());
		cout << v[0] << ' ';
		for(int i = 1; i < v.size(); i++){
			// cout << v[i] << ' ';
			sum = max(sum, v[i] + v[i - 1]);
		}
		cout << endl;
		cout << sum << endl;
	}
    return 0;
}