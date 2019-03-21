// C - 马走日
// http://bailian.openjudge.cn/practice/4123/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int sx, sy;
bool vis[10][10];
int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
int res;
bool go(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y){
    int t = 0;
    for(int i = 0; i < n; ++i)for(int j = 0; j < m; ++j)if(!vis[i][j])t++;
    if(!t){res ++; return;}
    for(int i = 0; i < 8; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!go(nx,ny))continue;
        if(!vis[nx][ny]){
            vis[nx][ny] = 1;
            dfs(nx, ny);
            vis[nx][ny] = 0;
        }
    }
    return;
}

int main(int argc, char const *argv[]){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> sx >> sy;
        res = 0;
        memset(vis, 0, sizeof(vis));
        vis[sx][sy] = 1;
        dfs(sx, sy);
        cout << res << endl;
    }
    return 0;
}
