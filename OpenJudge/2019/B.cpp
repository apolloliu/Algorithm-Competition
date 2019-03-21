// B - 方便记忆的电话号码
// http://bailian.openjudge.cn/practice/1002/
#include <bits/stdc++.h>
using namespace std;

bool check(char c){
    if(c >= '0' && c <= '9')return true;
    if(c >= 'A' && c <= 'Z')return true;
    return false;
}
int main(int argc, char const *argv[]){
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    map<string, int>mp;
    mp.clear();
    for(int i = 0; i < n; ++i){
        cin >> s;
        string str = "";
        for(int j = 0; j < s.size(); ++j){
            if(!check(s[j]))continue;
            if(s[j] >= '0' && s[j] <= '9'){
                str += s[j];
            }
            else {
                int c = s[j] - 'A';
                if(s[j] >= 'Q')c--;
                str += to_string(c/3+2);
            }
        }
        str = str.substr(0, 3) + '-' + str.substr(3);
        mp[str]++;
    }
    bool flag = false;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(it->second >= 2){flag = true; cout << it->first << " " << it->second << '\n';}
    }
    if(!flag)cout << "No duplicates." << endl;
    return 0;
}
