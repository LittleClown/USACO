/*
ID: xiaozhe7
PROG: comehome
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
const int INF = -1u >> 2;
const double DNF = (double)(-1u >> 1);
int P, Path[52][52], x, y;
inline int intread() {
	char c;
	while (c = getchar(), c < 'A' || c > ' z' || (c > 'Z' && c < 'a'));
	if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
	return c - 'a';
}
inline int Intread(int s = 0) {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	for (; c >= '0' && c <= '9'; c = getchar()) s = s * 10 + c - '0';
	return s;
}
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
#endif // Clown
#define REP(i, a, n) for(int i = a; i < n; i++)
	scanf("%d", &P);
	REP(i, 0, 52) REP(j, 0, 52) if (i != j) Path[i][j] = INF;
	REP(i, 0, P) {
		x = intread(); y = intread();
		Path[x][y] = Path[y][x] = min(Path[x][y], Intread());
	}
	REP(k, 0, 52) REP(i, 0, 52) REP(j, 0, 52) Path[i][j] = min(Path[i][j], Path[i][k] + Path[k][j]);
	char word;
	int ans = INF;
	REP(i, 26, 51) if (Path[i][51] < ans) ans = Path[i][51], word = 'A' + i - 26;
	printf("%c %d\n", word, ans);
	return 0;
}
