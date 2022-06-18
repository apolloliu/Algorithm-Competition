#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b;
    cin>>n;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        if(b - a >= 2)res++;
    }
    cout <<res <<endl;
    return 0;
}