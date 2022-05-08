#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("1.txt", "w", stdin);

	srand(time(0));

	int n, m;
	n = rand() % 8 + 1, m = rand() % 8 + 1;
	if(n == 1 && m == 1)n++;
	printf("%d %d\n", n, m);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			printf("%d ", rand() % 3);
		}
		printf("\n");
	}

	return 0;
}