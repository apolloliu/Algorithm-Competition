// I- 树的转换
// http://bailian.openjudge.cn/practice/4081/
// 递推：当前节点深度 = 父节点深度 + 兄弟节点的个数
// 
// Test Data:
// dduu
// dududduu
// dudduduudu
// ddduduudduduu   3 => 5

#include <bits/stdc++.h>
using namespace std; 
const int M=10010;

int v[M];
int h1, h2;
void dfs(string s){
    int n = s.size(), dep = 0;
    memset(v, 0, sizeof(v));
    for(int i = 0; i < n; ++i){
        if(s[i] == 'd'){
            dep ++;
            v[dep]++;
            int sum = 0;
            for(int i = 1; i <= dep; ++i)sum += v[i];
            h2 = max(h2, sum);
            if(i + 1 < n && s[i+1] == 'u'){
                v[dep+1] = 0;
            }
        }
        else {
            dep --;
            if(i + 1 < n && s[i+1] == 'u'){
                v[dep+1] = 0;
            }
        }
        h1 = max(h1, dep);
    }
    cout << h1 << " => " << h2 << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    dfs(s);
} 
