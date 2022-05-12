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

const int inf = 1e9;
const int N = 12345;
//#define LOCAL


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

	// int a = -1;
	// cout << unsigned(a) << endl;

	char buff[1024];

	FILE *in=fopen("input.txt", "r");
	// fgets(buff, 1024, in);
	// printf("%s\n", buff);
	// // cout << "size: " << strlen(buff) << endl;
	// printf("size: %d\n", strlen(buff)) << endl;
	char c;
	int i = 0;
	// while((c=sscanf(in, "%s", c)) != EOF){
	// 	puts(c);
	// 	// if(c == '\0')cout <<i <<endl;
	// 	i++;
	// }

	while((c=fgetc(in)) != EOF){
		putchar(c);
	}
	fclose(in);
	// freopen("input.txt", "w", stdout);
	// printf("abc\0");
	// printf("ee\0");

    return 0;
}