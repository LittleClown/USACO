/*
ID: xiaozhe7
LANG: C++
PROG: stamps
DATE: 2015 / 10 / 16
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int stamps[50], K, N, M, ans;
int dp[2000000 + 10], tot;
int main()
{
	//freopen("data.in", "r", stdin);
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	scanf("%d%d", &K, &N);
	for (int i = 0; i < N; ++i) scanf("%d", stamps + i);
	for (int i = 0; i < N; ++i) M = max(M, stamps[i]);
	M *= K;
	for (int i = 1; i <= M; ++i) {
		dp[i] = K + 1;
		for (int k = 0; k < N; ++k)
			if(i >= stamps[k]) dp[i] = min(dp[i], dp[i - stamps[k]] + 1);
	}
	while (ans <= M && dp[ans] <= K) ++ans;
	printf("%d\n", ans - 1);
	return 0;
}