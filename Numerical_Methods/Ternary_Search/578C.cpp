// http://codeforces.com/problemset/problem/578/C
// Ternary Search
#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

#define MEM(a,b)    memset(a, b, sizeof(a))
#define UN(a)       sort(all(a)), a.erase(unique(all(a)), a.end())
#define REV(a)      reverse(all(a))
#define MP(a, b)    make_pair(a, b)
#define PAIR(a, b)  pair<int, int>(a, b)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int maxn = 212345;
const double EPS = 1e-8;

double a[maxn];

double cal(double m, int n){
    double sum = 0., maxx = 0., minn = 0., res = 0.;
    for(int i = 0; i < n; ++i){
        sum += a[i] - m;
        maxx = max(maxx, sum);
        minn = min(minn, sum);
        res = max(res, max(maxx-sum, sum-minn));
    }
    return res;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(9);
    cout << fixed;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    double l = -1e6, r = 1e6;
    double res = 1e9;
    int t = 200;
    while(t--){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double vx = cal(m1, n), vy = cal(m2, n);
        if(vx < vy)r = m2;
        else l = m1;
        // cout << vx << " " << vy << ' ' << m << endl;
        res = min(res, max(vx, vy));
    }
    cout << res << endl;
    return 0;
}
// Binary Search
#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

#define MEM(a,b)    memset(a, b, sizeof(a))
#define UN(a)       sort(all(a)), a.erase(unique(all(a)), a.end())
#define REV(a)      reverse(all(a))
#define MP(a, b)    make_pair(a, b)
#define PAIR(a, b)  pair<int, int>(a, b)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int maxn = 212345;
const double EPS = 1e-8;

double a[maxn];

void cal(double m, double& vx, double& vy, int n){
    double sumx = 0., sumy = 0.;
    for(int i = 0; i < n; ++i){
        sumx = sumx + a[i] - m;
        if(sumx < 0.)sumx = 0.;
        vx = max(vx, sumx);
    }
    for(int i = 0; i < n; ++i){
        sumy = sumy - a[i] + m;
        if(sumy < 0.)sumy = 0.;
        vy = max(vy, sumy); 
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(9);
    cout << fixed;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    double l = -1e6, r = 1e6;
    double res = 1e9;
    int t = 200;
    while(t--){
        double m = (l + r) / 2;
        double vx = 0., vy = 0.;
        cal(m, vx, vy, n);
        if(vx > vy)l = m;
        else r = m;
        // cout << vx << " " << vy << ' ' << m << endl;
        res = min(res, max(vx, vy));
    }
    cout << res << endl;
    return 0;
}
