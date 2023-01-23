#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
class Solution {
    int range, k, n;
public:
    bool check(vector<ll>& sum, ll x) {
        // int sz = sum.size();
        int t = k;
        vector<int>d(n + 2, 0), a(n + 2, 0);
        for(int i = 1; i <= n; i++) {
            if(sum[i] + range * t < x) {
                return false;
            }
            int diff = ((x - sum[i]) + range + 1) / range;
            t -= diff;
            d[i] += diff;
            d[min(n, 2 * range + 1)] -= diff;   
        }
        for(int i = 1; i <= n; i++) {
            a[i] = a[i - 1] + d[i];
            if(sum[i] + a[i] < x) return false;
        }
        return true;
    }
    long long maxPower(vector<ll>& stations, int R, int k) {
        this->n = stations.size();
        // n ++;
        this->k = k;
        this->range = R;
        vector<ll>sum(n + 2, 0);
        partial_sum(stations.begin(), stations.end(), sum.begin() + 1);

        ll l = 0, r = sum.back() + k;
        while(l < r) {
            ll mid = (l + r) >> 1;
            if(check(sum, mid)) l = mid;
            else r = mid - 1;
        }
        return l;        
    }
};

int main(int argc, char const *argv[])
{
    vector<int>v = {1, 1, 0, 0, 3, 2};
    int n = v.size();
    vector<int>sum(n + 2, 0);
    partial_sum(v.begin(), v.end(), sum.begin() + 1);
    for(int i = 0; i <= n; i++)
        printf("%d %d\n", i, sum[i]);
    return 0;
}
