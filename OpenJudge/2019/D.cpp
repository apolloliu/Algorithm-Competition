// D - Jumping Cows
// http://bailian.openjudge.cn/practice/2181/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    std::vector<int> a(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int i = 0, t = 1;
    int res = 0;
    while(i < n){
        while(i+1<n && a[i] <= a[i+1]){
            ++i;
        }
        if(i < n)res += a[i];
        i++;
        while(i+1<n && a[i] >= a[i+1]){
            ++i;
        }
        // NOTE: if i is n-1, just skip
        if(i < n && i != n-1)res -= a[i];
        i++;
    }
    cout << res << endl;
    return 0;
}
