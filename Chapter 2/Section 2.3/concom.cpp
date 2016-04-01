/*
ID: xiaozhe7
PROG: concom
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

typedef long long LL;
int N, G[101][101];
bool cmd[101][101], visit[101][101][101];
void solve(int i, int j) {
	for (int k = 1; k <= 100; k++)
	if (i != k && cmd[i][k] == false && visit[i][j][k] == false) {
		G[i][k] += G[j][k];
		visit[i][j][k] = true;
		if (G[i][k] > 50) {
			cmd[i][k] = true;
			solve(i, k);
		}
	}
}
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
#endif // Clown
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		scanf("%d", &G[x][y]);
	}
	for (int i = 1; i <= 100; i++)
	for (int j = 1; j <= 100; j++)
	if (i != j && G[i][j] > 50) {
		cmd[i][j] = true;
		solve(i, j);
	}
	for (int i = 1; i <= 100; i++)
	for (int j = 1; j <= 100; j++)
	if (cmd[i][j]) printf("%d %d\n", i, j);
	return 0;
}
