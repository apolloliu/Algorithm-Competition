// A - 奖学金
// 提交地址：http://noi.openjudge.cn/ch0110/04/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct stu{
    int id, a, b, c;
    bool operator < (const stu& sb){
        int suma = a + b + c;
        int sumb = sb.a + sb.b + sb.c;
        if(suma != sumb)return suma > sumb;
        if(a != sb.a)return a > sb.a;
        return id < sb.id;
    }
}st[310];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n ; ++i){
        cin >> st[i].a >> st[i].b >> st[i].c;
        st[i].id = i+1;
    }
    sort(st, st+n);
    for(int i = 0; i < 5; ++i){
        cout << st[i].id << " " << st[i].a + st[i].b + st[i].c << endl;
    }
    return 0;
}
