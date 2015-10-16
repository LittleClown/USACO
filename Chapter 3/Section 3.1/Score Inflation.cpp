/*
ID: xiaozhe7
LANG: C++
PROG: inflate
DATE: 2015 / 10 / 16
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[10000 + 10];
int m, n, score, cost;
int main()
{
	//freopen("data.in", "r", stdin);
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &score, &cost);
		for (int j = cost; j <= m; ++j)
			dp[j] = max(dp[j], dp[j - cost] + score);
	}
	printf("%d\n", dp[m]);
	return 0;
}
