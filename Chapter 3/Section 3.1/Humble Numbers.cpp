/*
ID: xiaozhe7
LANG: C++
PROG: humble
DATE: 2015 / 10 / 16
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

long long prim[111], hum[100000 + 10];
int K, N, last[111];

int BinarySearch(int L, int R, long long p, long long v) {
	while (L < R) {
		int mid = L + R >> 1;
		if (hum[mid] * p <= v) L = mid + 1;
		else R = mid;
	}
	return L;

}
int main()
{
	//freopen("data.in", "r", stdin);
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	scanf("%d%d", &K, &N);
	for (int i = 0; i < K; ++i) scanf("%lld", prim + i);
	sort(prim, prim + K);
	hum[0] = 1;
	for (int i = 1; i <= N; ++i) {
		long long MIN = -1u;
		int arg = i;
		for (int k = 0; k < K; ++k) {
			arg = BinarySearch(last[k], arg, prim[k], hum[i - 1]);
			if (arg < i && hum[arg] * prim[k] < MIN) {
				MIN = hum[arg] * prim[k];
				last[k] = arg++;
			}
		}
		hum[i] = MIN;
	}
	printf("%lld\n", hum[N]);
	return 0;
}
