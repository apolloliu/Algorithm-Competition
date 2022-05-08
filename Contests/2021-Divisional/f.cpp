#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define eps 1e-11

const int N = 2e6 + 10;

typedef pair<double, double> point;

bool check(double k, double b, double R, vector<point>& P){
    for(auto p: P){
        // if((p.first - x)*(p.first - x) + (p.second - y)*(p.second - y) - R * R > eps)return true;
        auto [x, y] = p;
        cout << x << ' ' << y << endl;
        // line: kx - y + b = 0
        double dis = abs(k * x - y + b) / sqrt(k * k + 1);
        cout << "dis: " << dis << " R: " << R << endl;
        if(dis - R > eps) return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    clock_t start_time = clock();
    double x, y, w, h;
    cin >> x >> y >> w >> h;

    vector<point>v;
    v.clear();
    v.push_back({x, y});
    v.push_back({x + w, y});
    v.push_back({x + w, y + h});
    v.push_back({x, y + h});

    double x0, y0, x1, y1, R;
    cin >> R >> x0 >> y0 >> x1 >> y1;

    double slp_x = x1 - x0, slp_y = y1 - y0;
    double slp_k = slp_y / slp_x;
    double b = y1 - slp_k * x1;
    cout << "k : " << slp_k << endl;


    // ll k = 525990;
    // bool flag = true;
    // int sum = 0;
    // for(; x1 - x0 > eps || y1 - y0 > eps; x0 = x0 + slp_x * 1. / k, y0 = y0 + slp_y * 1. / k){
    //     if(!check(x0, y0, R, v)){
    //         flag = false;
    //         // sum ++;
    //         break;
    //     }
    // }

    bool flag = false;
    if(check(slp_k, b, R, v)) flag = true;

    // cout << sum << endl;
    if(!flag)puts("Oh no!");
    else puts("Safe");
    // clock_t end_time = clock();

    // cout << "time: " << end_time - start_time << endl;
    return 0;
}
