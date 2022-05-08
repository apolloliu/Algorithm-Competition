#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// inline ll abs(ll x){
// 	if(x < 0) return -x;
// 	return x;
// }

const int N = 70;
ll a[N][N], L[N], R[N];
bool st[N][N], vis[N][N];
int n, m;
ll res, mmin, total;
bool yes;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool check(int x, int y, int cnt){
	queue<pii>q;
	q.push({x, y});

	memcpy(vis, st, sizeof st);
	vis[x][y] = 1;
	cnt ++;
	while(q.size()){
		auto t = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = t.first + dx[i], ny = t.second + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
				vis[nx][ny] = 1;
				cnt++;
				q.push({nx, ny});
			}
		}
	}
	if(cnt == n * m)return true;
	else return false;
}

void dfs(int x, int y, int cnt, vector<ll> v, ll product){
	ll val = abs(total / product - product);
	// cout << val << endl;
	if(val >= res && product > total / product)return;

	int ta, tb;
	bool flag = false;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!st[i][j]){ta = i, tb = j; flag = true; break;}
		}
		if(flag)break;
	}
	
	if(flag && !check(ta, tb, cnt))return;
	res = min(res, val);
	
	if(cnt >= n * m - 1)return;

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && !st[nx][ny]){
			st[nx][ny] = 1;
			v.push_back(a[nx][ny]);
			dfs(nx, ny, cnt + 1, v, product * a[nx][ny]);
			v.pop_back();
			st[nx][ny] = 0;
		}
	}
}


int main(){
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(st, false, sizeof st);
	cin >> n >> m;

	ll zero = 0, two = 0;
	
	total = 1LL;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			total *= a[i][j];
			if(!a[i][j])zero++;
			else mmin = min(mmin, a[i][j]);
			if(a[i][j] == 2)two ++;
		}
	}

	if(zero >= 2) cout << 0 << endl;
	else if(zero == 1){
		mmin = 2;
		if(n == 1 || m == 1){
			if(n == 1){
				if(a[0][m - 1])mmin = min(mmin, a[0][m - 1]);
				if(a[0][0])mmin = min(mmin, a[0][0]);
			}
			else {
				if(a[0][0])mmin = min(mmin, a[0][0]);
				if(a[n - 1][0])mmin = min(mmin, a[n - 1][0]);
			}
		}
		else {
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(a[i][j])
					mmin = min(mmin, a[i][j]);
				}
			}
		}

		
		cout << mmin << endl;
	}
	else {
		if(n == 1 || m == 1){
			res = total;
			vector<ll>v;
			v.push_back(a[0][0]);
			st[0][0] = 1;
			dfs(0, 0, 1, v, a[0][0]);
			cout << res << endl;
		}
		else {
			ll p1 = pow(2, two / 2);
			ll p2 = pow(2, two - two / 2);
			res = abs(p1 - p2);
			cout << res << endl;
		}
	}
		


	return 0;
}

/**
 

8 8
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2


1 64
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2

1 64
1 0 0 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 2 1 2

1 5
2 1 1 1 1

1 5
2 0 1 1 0

1 4
0 0 1 1

1 3
0 1 2


3 4
0 1 2 2
2 2 2 2
2 2 2 2



3 4
0 2 2 2
2 2 1 2
2 2 2 2

1

1 3
1 0 2
**/