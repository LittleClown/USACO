/*
ID: xiaozhe7
PROG: cowtour
LANG: C++
DATE: 15/ 8/ 14
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
const int INF = -1u >> 1;
const double DNF = (double)(-1u >> 1);
const int maxn = 151;
struct node{
	int x, y;
	node(int x = 0, int y = 0) : x(x), y(y) {}
};
node point[maxn];
bool Path[maxn][maxn];
int N, F[maxn];
double dist[maxn][maxn], L[maxn], ans, shorest;
int root(int x) {
	return F[x] ? F[x] = root(F[x]) : x;
}
inline void Union(int x, int y) {
	int xx = root(x), yy = root(y);
	if (xx == yy) return;
	F[xx] = yy;
}
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
#endif // Clown
#define REP(i, a, n) for(int i = a; i < n; i++)
#define square(a) (a)*(a)
	scanf("%d", &N);
	N++;
	REP(i, 1, N) scanf("%d%d%*c", &point[i].x, &point[i].y);
	REP(i, 1, N) {
		REP(j, 1, N) {
			Path[i][j] = getchar() - '0';
			if (Path[i][j]) Union(i, j);
		}
		getchar();
	}
	REP(i, 1, N) REP(j, i, N)  {
		if (Path[i][j] == false) dist[i][j] = dist[j][i] = DNF;
		else dist[i][j] = dist[j][i] = sqrt(square(point[i].x - point[j].x) + square(point[i].y - point[j].y));
	}
	REP(k, 1, N) REP(i, 1, N) REP(j, i + 1, N) dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);
	REP(i, 1, N) REP(j, 1, N) if (dist[i][j] != DNF) L[i] = max(L[i], dist[i][j]);
	REP(i, 1, N) ans = max(ans, L[i]);
	shorest = DNF;
	REP(i, 1, N) {
		int R = root(i);
		REP(j, 1, N) if (i != j && root(j) != R){
			shorest = min(shorest, L[i] + L[j] + sqrt(square(point[i].x - point[j].x) + square(point[i].y - point[j].y)));
		}
	}
	printf("%.6lf\n", max(ans, shorest));
	return 0;
}
