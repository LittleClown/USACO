/*
ID: xiaozhe7
LANG: C++
PROG: subset
DATE: 15/ 07/ 08
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, s, len;
long long M[1600];
int main()
{
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	//freopen("data.in", "r", stdin);
	scanf("%d", &n);
	if ((n & 3) == 1 || (n & 3) == 2) printf("0\n");
	else {
		s = (n + 1) * n >> 2;
		M[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = min(len + i, s) - i; j >= 0; j--)
				M[j + i] += M[j];
			len += i;
		}
		printf("%lld\n", M[s] >> 1);
	}
	return 0;
}
