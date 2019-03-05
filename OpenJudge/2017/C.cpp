// C - 二维数组回形遍历
// http://noi.openjudge.cn/ch0108/23/

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e15L;
const int maxn = 123456;
int a[110][110];
int n, m;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

#define check()  if(!t)break

void solve(){
    int row = n-1, col = m, t = n*m, x = 1, y = 0;
    while(t){
        for(int i = 1; i <= col; ++i){cout << a[x][y+i] << endl; t--; check(); }
        check(); y += col; col--;
        for(int i = 1; i <= row; ++i){cout << a[x+i][y] << endl; t--; check(); }
        check(); x += row; row--;
        for(int i = 1; i <= col; ++i){cout << a[x][y-i] << endl; t--; check(); }
        check(); y -= col; col--;
        for(int i = 1; i <= row; ++i){cout << a[x-i][y] << endl; t--; check(); }
        check(); x -= row; row--;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
    solve();
    return 0;

}

/** 
4 5
1 2 3 4 5
14 15 16 17 6
13 20 19 18 7
12 11 10 9 8
**/
