/*
ID: xiaozhe7
LANG: C++
PROG: lamps
DATE: 15/ 07/ 08
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int bright[101], dark[100];
int n, a, b, c, d, e, tmp, tot1, tot2, tot;
bool ans[1 << 4], done, A, B, C, D;
char lamps[1 << 4][102], *s;
bool lamp(const int& n) {
	bool shine = true;
	if (A) shine = !shine;
	if (B && (n & 1)) shine = !shine;
	if (C && (n & 1) == 0) shine = !shine;
	if (D && (n - 1) % 3 == 0) shine = !shine;
	return shine;
}
void check() {
	A = a & 1, B = b & 1, C = c & 1, D = d & 1;
	for (tmp = 0; tmp < tot1; tmp++)
	if (lamp(bright[tmp]) == false) return;
	for (tmp = 0; tmp < tot2; tmp++)
	if (lamp(dark[tmp])) return;
	done = true;
	ans[(D << 3) + (C << 2) + (B << 1) + A] = true;
}
int main()
{
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	//freopen("data.in", "r", stdin);
	scanf("%d%d", &n, &e);
	while (scanf("%d", &tmp) == 1 && tmp != -1) bright[tot1++] = tmp;
	while (scanf("%d", &tmp) == 1 && tmp != -1) dark[tot2++] = tmp;
	if (e > 4) e = 4 - (e & 1);
	for (a = 0; a <= e; a++)
	for (b = 0; b + a <= e; b++)
	for (c = 0; c + b + a <= e; c++) {
		d = e - a - b - c;
		check();
	}
	if (done == false) printf("IMPOSSIBLE\n");
	else {
		for (int i = 0; i < 16; i++)
		if (ans[i]) {
			A = i & 1; B = i & (1 << 1);
			C = i & (1 << 2); D = i & (1 << 3);
			for (int j = 1; j <= n; j++) lamps[tot][j] = lamp(j) + '0';
			lamps[tot++][n + 1] = '\0';
		}
		memset(ans, 0, sizeof ans);
		for (int cnt = 0, pos = 0; cnt < tot; cnt++) {
			for (int i = 0; i < tot; i++)
			if(ans[i] == false){
				s = lamps[i] + 1; pos = i;
				for (int j = 0; j < tot; j++)
				if (j != i && ans[j] == false && strcmp(s, lamps[j] + 1) > 0)
					s = lamps[j] + 1, pos = j;
				printf("%s\n", s);
				ans[pos] = true;
			}
		}
	}
	return 0;
}
