#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

/* 常用的常量定义 */
const double INF = 1E200;
const double EP = 1E-10;
const int MAXV = 300;
const double PI = 3.14159265;

/* 基本几何结构 */
struct POINT {
  double x;
  double y;
  POINT(double a = 0, double b = 0) {
    x = a;
    y = b;
  } // constructor
};
struct LINESEG {
  POINT s;
  POINT e;
  LINESEG(POINT a, POINT b) {
    s = a;
    e = b;
  }
  LINESEG() {}
};
struct LINE // 直线的解析方程 a*x+b*y+c=0  为统一表示，约定 a >= 0
{
  double a;
  double b;
  double c;
  LINE(double d1 = 1, double d2 = -1, double d3 = 0) {
    a = d1;
    b = d2;
    c = d3;
  }
};

double dist(POINT p1, POINT p2) // 返回两点之间欧氏距离
{
  return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}

/*****************************\
*                             *
*      线段及直线的基本运算   *
*                             *
\*****************************/

/* 判断点与线段的关系,用途很广泛
本函数是根据下面的公式写的，P是点C到线段AB所在直线的垂足
                AC dot AB
        r =     ---------
                 ||AB||^2
             (Cx-Ax)(Bx-Ax) + (Cy-Ay)(By-Ay)
          = -------------------------------
                          L^2
    r has the following meaning:
        r=0      P = A
        r=1      P = B
        r<0         P is on the backward extension of AB
        r>1      P is on the forward extension of AB
        0<r<1     P is interior to AB
*/
double dotmultiply(POINT p1, POINT p2, POINT p0) {
  return ((p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y));
}

double relation(POINT p, LINESEG l) {
  LINESEG tl;
  tl.s = l.s;
  tl.e = p;
  return dotmultiply(tl.e, l.e, l.s) / (dist(l.s, l.e) * dist(l.s, l.e));
}
// 求点C到线段AB所在直线的垂足 P
POINT perpendicular(POINT p, LINESEG l) {
  double r = relation(p, l);
  POINT tp;
  tp.x = l.s.x + r * (l.e.x - l.s.x);
  tp.y = l.s.y + r * (l.e.y - l.s.y);
  return tp;
}
/* 求点p到线段l的最短距离,并返回线段上距该点最近的点np
注意：np是线段l上到点p最近的点，不一定是垂足 */
double ptolinesegdist(POINT p, LINESEG l, POINT &np) {
  double r = relation(p, l);
  if (r < 0) {
    np = l.s;
    return dist(p, l.s);
  }
  if (r > 1) {
    np = l.e;
    return dist(p, l.e);
  }
  np = perpendicular(p, l);
  return dist(p, np);
}
//----------------------------------------------------------------

int main() {
  int x, y, w, h, r, xs, ys, xe, ye;
  cin >> x >> y >> w >> h;
  cin >> r >> xs >> ys >> xe >> ye;
  POINT pen1(x, y), pen2(x + w, y), pen3(x + w, y + h), pen4(x, y + h), result;
  POINT ps(xs, ys), pe(xe, ye);
  LINESEG l(ps, pe);
  double dist1 = ptolinesegdist(pen1, l, result);
  double dist2 = ptolinesegdist(pen2, l, result);
  double dist3 = ptolinesegdist(pen3, l, result);
  double dist4 = ptolinesegdist(pen4, l, result);
  double maxdist = max(max(max(dist1, dist2), dist3), dist4);
  if (maxdist > r) {
    cout << "Safe" << endl;
  } else
    cout << "Oh no!" << endl;
  return 0;
}