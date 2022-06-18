//#pragma GCC optimize(2)
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const int N = 50007, M = 500007, INF = 0x3f3f3f3f;
const double inf = 1e100;
const double eps = 1e-8;

int n;

int sgn(double d)
{
    if(fabs(d) < eps)
        return 0;
    if(d < 0)
        return 1;
    return -1;
}

int dcmp(double x, double y)
{
    if(fabs(x - y) < eps)
        return 0;
    if(x > y)
        return 1;
    return -1;
}

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0):x(x), y(y) { }
};

struct Point_3D
{
    double x, y, z;
    Point_3D(double x = 0, double y = 0, double z = 0):x(x), y(y), z(z){ }
};

const int R = 6371009;

double torad(double deg)//角度转弧度
{
    return deg / 180 * acos(-1);
}
//经纬度（角度）转化为空间坐标
void get_coord(double lat, double lng, double &x, double &y, double &z)
{
    lat = torad(lat);
    lng = torad(lng);
    x = R * cos(lat) * cos(lng);
    y = R * cos(lat) * sin(lng);
    z = R * sin(lat);
}
//就离谱，这里没有加double竟然不报错，导致答案小了1 ???
double get_dist_3D(Point_3D A, Point_3D B)
{
    double fx = A.x - B.x;
    double fy = A.y - B.y;
    double fz = A.z - B.z;
    return sqrt(fx * fx + fy * fy + fz * fz);
}

Point p[N];

void solve() {
	for(int i = 2; i <= n; i++) {
		Point_3D a, b;
		Point A = p[i], B = p[i - 1];
		get_coord(A.x, A.y, a.x, a.y, a.z);
        get_coord(B.x, B.y, b.x, b.y, b.z);
		double distance = get_dist_3D(a, b);
		double hu = 2.0 * asin(distance / 2.0 / R) *R;
		printf("%lf", hu);
	}

	// foir (int i = 0; i <= n; i++)
}

bool deg[360];

void calc(int i, int j) {
	int l, r;
	if(p[i].y * p[j].y <= 0.) {
		double a = p[i].y, b = p[j].y;
		if(a > 0)swap(a, b);
		if(abs(a) + abs(b) > 180)
	}
	else {
		// if(p[i].y < 0) {
		// 	l = floor(min(p[i].y, p[j].y));
		// 	r = ceil(max(p[i].y, p[j].y));
		// }
		// else {

		// }
		l = ceil(min(p[i].y, p[j].y));
		r = floor(max(p[i].y, p[j].y));
		while(l < r) {
			deg[l - 180] = true;
			l++;
		}
	}
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);


	Point_3D a, b;
	
	cin >> n;
  
	for(int i = 1; i <= n; i++)
		cin >> p[i].x >> p[i].y;

	// solve();

	for(int i = 2; i <= n; i++) {
		calc(i, i - 1);
	}
	calc(n, 1);

    return 0;
}