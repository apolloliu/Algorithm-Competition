#include<iostream>
using namespace std;
const int N = 3e5 + 10;
int a[N], s[N], f[N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    
    int hh, tt;
    hh = tt = 0;
    int res = -1e9;
    for(int i = 1; i <= n; i++) {
        if(i - f[hh] > m)hh++;
        res = max(res, s[i] - s[f[hh]]);
        while(hh <= tt && s[i] <= s[f[tt]])tt--;
        f[++tt] = i;
    }
    cout << res << endl;
    
    return 0;
}