/*
ID: xiaozhe7
PROG: hamming
LANG: C++
DATE: 15 / 06 / 25
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, b, d, x, tmp, cnt, tot, f[66];

void check() {
	for (int i = 0; i < tot; i++) {
		for (tmp = x ^ f[i], cnt = 0; tmp; tmp >>= 1)
		if (tmp & 1) ++cnt;
		if (cnt < d) return;
	}
	f[tot++] = x;
}

int main()
{
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	//freopen("data.in", "r", stdin);
	scanf("%d%d%d", &n, &b, &d);
	for (x = tot = 0, b = (1 << b + 1) - 1; x < b && tot < n; x++) check();
	for (int i = 0; i < tot - 1; i++) {
		printf("%d", f[i]);
		printf("%c", i % 10 == 9 ? '\n' : ' ');
	}
	printf("%d\n", f[tot - 1]);
	return 0;
}
