// cf #552 div3 - Minimum Possible LCM
// https://codeforces.com/contest/1154/problem/G

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e7 + 10;
int t[maxn];

map<int, int>mp;
int main(){
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin>>n;
    int a, b;
    ll res = 1e18;
    memset(t, 0, sizeof(t));
    for(int i = 1; i <= n; ++i){
        cin >> x;
        if(t[x] && (ll)x/__gcd(x,x)*x < res){
            a = t[x];
            b = i;
            res = (ll)x/__gcd(x,x)*x;
        }
        t[x] = i;
    }
    for(int i = 1; i < maxn; ++i){
        int cnt = 0;
        for(int j = i; j < maxn; j += i){
            if(!t[j])continue;
            if(!cnt)cnt = j;
            else {
                ll g = __gcd(cnt, j);
                if(res > cnt/g*j){
                    a = t[cnt];
                    b = t[j];
                    res = cnt/g*j;
                }
                break;
            }
        }
    }
    if(a > b)swap(a, b);
    cout << a << ' ' << b << '\n';
    return 0;
}

/*******
3
2 3 4

3
7 10 15
*******/
