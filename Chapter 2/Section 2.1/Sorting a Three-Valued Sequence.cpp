/*
ID: xiaozhe7
PROG: sort3
LANG: C++
DATE: 15 / 06 / 25
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mem(A) memset(A, 0, sizeof A)
using namespace std;

int main()
{
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	//freopen("data.in", "r", stdin);
	int m, ans, a[4][4], s[4], f[1000];
	mem(a), mem(s);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", f + i), s[f[i]]++;
	for (int i = 1, *t = f; i <= 3; i++)
	for (int *r = t + s[i]; t < r; t++)
		a[i][*t]++;
	ans = a[2][1] + a[3][1] + a[3][2] + max(a[1][2] - a[2][1], 0);
	printf("%d\n", ans);
	return 0;
}
