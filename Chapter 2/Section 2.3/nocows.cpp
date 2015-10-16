/*
ID: xiaozhe7
PROG: nocows
LANG: C++
DATE: 15/ 8/ 13
*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int N, K, ans[200][100];
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
#endif // Clown
	scanf("%d%d", &N, &K);
	for (int h = 1; h <= K; h++) ans[1][h] = 1;
	for (int h = 1; h <= K; h++)
	for (int node = 3; node <= N; node += 2)
	for (int left = 1; left <= node - 2; left++)
		ans[node][h] = (ans[node][h] + ans[left][h - 1] * ans[node - left - 1][h - 1]) % 9901;
	printf("%d\n", (ans[N][K] - ans[N][K - 1] + 9901) % 9901);
	return 0;
}
