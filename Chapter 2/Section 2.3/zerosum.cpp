/*
ID: xiaozhe7
PROG: zerosum
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

int N, DN;
char ans[20];
int Getnum(int& front) {
	int s = ans[front] - '0';
	while (front + 1 < DN && ans[front + 1] == ' ')s = s * 10 + ans[front += 2] - '0';
	return s;
}
inline int cal(int cur = 0) {
	int s = Getnum(cur);
	cur++;
	while (cur < DN) {
		switch (ans[cur]) {
		case '+': s += Getnum(++cur); break;
		case '-': s -= Getnum(++cur); break;
		}
		++cur;
	}
	return s;
}
void DFS(int cur = 0) {
	ans[cur << 1] = cur + '1';
	if (cur == N - 1) {
		if (cal() == 0) puts(ans);
		return;
	}
	ans[(cur << 1) | 1] = ' '; DFS(cur + 1);
	ans[(cur << 1) | 1] = '+'; DFS(cur + 1);
	ans[(cur << 1) | 1] = '-'; DFS(cur + 1);
}
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
#endif // Clown
	scanf("%d", &N);
	DN = (N << 1) - 1;
	DFS();
	return 0;
}
