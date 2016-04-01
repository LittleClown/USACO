/*
ID: xiaozhe7
PROG: maze1
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
const int INF = -1u >> 1;
const int maxn = 222 * 444;
const int nx[] = { -1, 0, 1, 0 };
const int ny[] = { 0, 1, 0, -1 };
struct node{
	int x, y, step;
	node(int x = 0, int y = 0, int step = 1) : x(x), y(y), step(step){}
};
char map[222][444];
int W, H, DW, DH, front, rear, cnt;
node exist[2], Q[maxn], now;
int Step[222][444];
int BFS() {
	int ans = 0;
	for (rear = 0; rear < cnt; rear++) Q[rear] = exist[rear];
	for (int i = 0; i < DH; i++)
	for (int j = 0; j < DW; j++)
		Step[i][j] = INF;
	for (int i = 0; i < cnt; i++) Step[exist[i].x][exist[i].y] = 1;
	for (front = 0; front != rear; front++) {
		now = Q[front];
		for (int i = 0; i < 4; i++) {
			int mx = now.x + nx[i];
			int my = now.y + ny[i];
			if (map[mx][my] != ' ') continue;
			mx += nx[i]; my += ny[i];
			if (mx < 0 || my < 0 || mx >= DH || my >= DW) continue;
			if (Step[mx][my] <= now.step + 1) continue;
			Step[mx][my] = now.step + 1;
			Q[rear++] = node(mx, my, now.step + 1);
		}
	}
	for (int i = 0; i < DH; i++)
	for (int j = 0; j < DW; j++)
	if (Step[i][j] != INF) ans = max(Step[i][j], ans);
	return ans;
}
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
#endif // Clown
	scanf("%d%d%*c", &W, &H);
	DW = (W << 1) | 1;
	DH = (H << 1) | 1;
	bool ok = true;
	for (int i = 0; i < DH; i++) {
		for (int j = 0; j < DW; j++) {
			map[i][j] = getchar();
			if (map[i][j] == '\n') {
				ok = false;
				for (; j < DW; j++) map[i][j] = ' ';
			}
		}
		if (ok) getchar();
		else ok = true;
	}
	for (int i = 1; i < DH; i += 2)
	if (map[i][0] == ' ') exist[cnt++] = node(i, 1);
	else if (map[i][DW - 1] == ' ') exist[cnt++] = node(i, DW - 2);
	for (int i = 1; i < DW; i += 2)
	if (map[0][i] == ' ') exist[cnt++] = node(1, i);
	else if (map[DH - 1][i] == ' ') exist[cnt++] = node(DH - 2, i);
	if (cnt == 2 && exist[0].x == exist[1].x && exist[0].y == exist[1].y) --cnt;
	printf("%d\n", BFS());
	return 0;
}
