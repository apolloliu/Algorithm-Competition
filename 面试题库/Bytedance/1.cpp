
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

const ll MOD = 1e9 + 7;
const int inf = 0x7f7f7f7f;
const int maxn = 312345;
const double EPS = 1e-8;

map<int, std::vector<int>> mp;
int v[maxn];
int BinarySearchMax(const std::vector<int>& data, int target)
{
   int left = 0;
   int right = data.size();
   int mid;
   while (left < right) {
       mid = (left + right) / 2;
       if (data[mid] < target)
           left = mid+1;
       else
           right = mid;
       // cout << mid << '\n';
   }
   if (data[mid] <= target)
       return mid;
   return -1;
}

int BinarySearchMin(const std::vector<int>& data, int target)
{
   int left = 0;
   int right = data.size();
   while (left < right) {
       int mid = (left + right) / 2;
       if (data[mid] >= target)
           right = mid;
       else
           left = mid+1;
   }
   // cout << right << endl;
   if (data[right] >= target)
       return right;
   return -1;
}


int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, n, l, r, k, x;
    mp.clear();
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        v[i] = x;
        mp[x].push_back(i);
    }
    cin >> q;
    while(q--){
        cin >> l >> r >> k;
        l --; r --;
        int a = lower_bound(mp[k].begin(), mp[k].end(), l) - mp[k].begin();
        int b = upper_bound(mp[k].begin(), mp[k].end(), r) - mp[k].begin();
        cout << b - a << endl;
        
    }
    return 0;
}
// 4
// 1 2 3 3
// 1
// 3 4 1

// 5
// 1 2 3 3 2
// 1
// 6 6 2
