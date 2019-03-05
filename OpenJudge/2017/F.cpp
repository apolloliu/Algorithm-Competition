// F - 水淹七军
// 这题只能找到类似的题目提交，但是要注意两个题样例存在差别，题意说的是比放水点低的地方都会淹没，不知为何poj给的样例输出是No，没法提交因此没法实验其他想法
// 方法是从放水点依次搜一下即可，但是竟然没有超时，说明数据没有考虑极限情况
// http://www.bnuoj.com/problem_show.php?pid=1023

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x7f7f7f7f;
const int maxn = 1010;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
int sx, sy;

int mp[210][210];
int vis[210][210];
bool go(int x, int y){
    return x >= 1 && x <= m && y >= 1 && y <= n;

}

bool bfs(int x, int y){
    queue<pii>q;
    while(!q.empty())q.pop();
    q.push({x, y});
    memset(vis, 0, sizeof(vis));
    vis[x][y] = 1;
    while(!q.empty()){
        pii t = q.front();
        q.pop();
        int a = t.fi, b = t.se;
        if(a == sx && b == sy)return true;
        for(int i = 0; i < 4; ++i){
            int nx = a + dx[i], ny = b + dy[i];
            if(!go(nx, ny))continue;
            if(!vis[nx][ny] && mp[nx][ny] <= mp[a][b]){
                vis[nx][ny] = 1;
                q.push({nx, ny});
                mp[nx][ny] = mp[a][b];
            }
        }
    }
    return false;
}

int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int T, x, y, p;
    cin >> T;
    while(T--){
        cin >> m >> n;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> mp[i][j];
            }
        }
        cin >> sx >> sy;
        cin >> p;
        bool flag = false;
        for(int i = 0; i < p; ++i){
            cin >> x >> y;
            if(!flag && bfs(x, y))flag = true;
        }

        if(flag)puts("Yes");
        else puts("No");
    }

}
