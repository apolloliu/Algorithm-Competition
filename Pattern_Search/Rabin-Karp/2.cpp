#include <bits/stdc++.h>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const ll p = 256;  //p is a prime
ll calculate_hash(string s, int len){
    ll res = 0;
    for(int i = 0; i < len; ++i){
        res += s[i] * (ll)pow(p, len - i - 1) % mod;
    }
    return res;
}
void RabinKarp(string text, string pattern){
    int st = text.size();
    int sp = pattern.size();
    int i, j;
    ll h = 1;
    ll hash_t = 0; //calculate_hash(text, sp);
    ll hash_p = 0; //calculate_hash(pattern, sp);
    for (i = 0; i < sp - 1; i++)
    h = (h*p)%mod;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < sp; i++)
    {
        hash_p = (p*hash_p + pattern[i])%mod;
        hash_t = (p*hash_t + text[i])%mod;
    }
    //cout << hash_p << endl;
    //cout << hash_t << endl;
    for(i = 0; i <= st - sp; ++i){
       if(hash_t == hash_p){
            for(j = 0; j < sp && i + j < st; ++j){
                if(pattern[j] != text[i + j]){
                    break;
                    }
            }
            if(j == sp)
            cout << i << '\n';
        }
        if(i < st - sp) {
            hash_t = (p * (hash_t - text[i] * h) + text[i + sp]) % mod;
            if(hash_t < 0)hash_t += mod; // keep in mind hash value should be positive
        }
    }
}


// Driver program to test above function
int main()
{
    freopen("input.txt", "r", stdin);
    string text ;
    string pat ;
    //KMPSearch(pat, txt);
    int n;
    while(cin >> n >> pat >> text){
        RabinKarp(text, pat);
        cout <<'\n';
    }
    return 0;
}
