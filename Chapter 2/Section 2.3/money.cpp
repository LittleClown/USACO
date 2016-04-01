/*
ID: xiaozhe7
PROG: money
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
const int maxn = 1e4 + 1;
int money[25], V, N;
LL M[maxn], Tmp[maxn];
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
#endif // Clown
	scanf("%d%d", &V, &N);
	for (int i = 0; i < V; i++) scanf("%d", money + i);
	for (int i = 0; i <= N; i += money[0]) M[i] = 1;
	for (int i = 1; i < V; i++) {
		for (int j = 0; j <= N; j += money[i])
		for (int k = 0; k + j <= N; k++)
			Tmp[k + j] += M[k];
		for (int j = 0; j <= N; j++) M[j] = Tmp[j];
		memset(Tmp, 0, sizeof Tmp);
	}
	printf("%lld\n", M[N]);
	return 0;
}
