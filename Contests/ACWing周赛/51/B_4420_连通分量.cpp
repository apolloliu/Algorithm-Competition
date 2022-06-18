// 开O2才过的
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define ms(s) memset(s, 0, sizeof(s))

const int inf = 1e9;
const int N = 1010;
//#define LOCAL

int n, m;
char g[N][N], c[N][N];
int st[N][N], id[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pii>v;
unordered_map<int, int>sum;


bool go(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int x, int y, int val) {
	queue<pii>q;
	q.push({x, y});
	st[x][y] = 1;

	int cnt = 0;
	while(q.size()) {
		auto t = q.front();
		q.pop();
		x = t.first; y = t.second;
		cnt++;
		id[x][y] = val;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(go(nx, ny) && !st[nx][ny] && g[nx][ny] == '.') {
				st[nx][ny] = 1;
				q.push({nx, ny});
			}
		}

	}

	return cnt;
}

int calc(int x, int y) {
	set<int>s;
	int res = 0;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(go(nx, ny) && g[nx][ny] == '.' && !s.count(id[nx][ny])) {
			s.insert(id[nx][ny]);
			res += sum[id[nx][ny]];
		}
	}

	return res;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	// ios::sync_with_stdio(false);
	// cin.tie(0);

	// cin >> n >> m;
	scanf("%d%d", &n, &m);
	v.clear();
	sum.clear();

	for(int i = 0; i < n; i++){
		scanf("%s", g[i]);
		for(int j = 0; j < m; j++) {
			if(g[i][j] == '*')
				v.push_back({i, j});
			c[i][j] = g[i][j];
		}
	}

	memset(st, 0, sizeof st);

	int k = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			if(g[i][j] == '.' && !st[i][j]) {
				int cnt = bfs(i, j, k);
				sum[k++] = cnt;
				// cout << i << ' ' << j << ' ' << cnt << endl;
			}
			
		}
	}

	for(auto a: v) {
		int x = a.first, y = a.second;
		int t = (calc(x, y) + 1) % 10;
		c[x][y] = t + '0';
	}


	for(int i = 0; i < n; i++)
		printf("%s\n", c[i]);

    return 0;
}