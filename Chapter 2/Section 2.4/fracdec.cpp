/*
ID: xiaozhe7
PROG: fracdec
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
const int maxn = 2e5;
int N, D, Ans[maxn], exist[maxn], tot, s, Base, G;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
#endif // Clown
#define REP(i, a, n) for(int i = a; i < n; i++)
	scanf("%d%d", &N, &D);
	G = gcd(N, D);
	N /= G; D /= G;
	printf("%d.", N / D);
	for (int i = N / D; i; i /= 10) Base++;
	if (Base == 0) Base = 1;
	Base += 2;
	exist[N % D] = 1; tot = 1;
	for (s = N % D * 10; s && tot < maxn; s = s % D * 10) {
		Ans[++tot] = s / D;
		if (exist[s % D]) break;
		exist[s % D] = tot;
	}
	if (s == 0) {
		if (tot != 1) REP(i, 2, tot + 1) printf("%d", Ans[i]);
		else printf("0");
	}
	else {
		int first = exist[s % D];
		for (int i = 2; i <= first; Base++, i++) {
			if (Base % 76 == 0) printf("\n");
			printf("%d", Ans[i]);
		}
		printf("(");
		for (int i = first + 1; i <= tot; Base++, i++) {
			if (Base % 76 == 0) printf("\n");
			printf("%d", Ans[i]);
		}
		printf(")");
	}
	printf("\n");
	return 0;
}
