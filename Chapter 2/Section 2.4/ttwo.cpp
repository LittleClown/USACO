/*
ID: xiaozhe7
PROG: ttwo
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
const int nx[] = { -1, 0, 1, 0 };
const int ny[] = { 0, 1, 0, -1 };
char map[12][12];
bool visit[11][11][4][11][11][4];
struct Tode {
	int x, y, d;
	Tode(int x = 0, int y = 0, int d = 0) : x(x), y(y), d(d) {}
};
struct node {
	Tode F, C;
	int step;
	node(int step = 0) : step(step) {}
	node(Tode F, Tode C, int step = 0) : F(F), C(C), step(step) {}
};
node Q[11 * 11 * 4 * 11 * 11 * 4], now;
Tode Farm, Cow;
int front, rear;
int BFS() {
	Q[0] = node(Farm, Cow);
	for (front = 0, rear = 1; front < rear; front++) {
		now = Q[front];
		if (now.F.x == now.C.x && now.F.y == now.C.y) return now.step;
		Farm = now.F;
		if (map[Farm.x + nx[Farm.d]][Farm.y + ny[Farm.d]] != '*')
			Farm.x += nx[Farm.d], Farm.y += ny[Farm.d];
		else Farm.d = (Farm.d + 1) % 4;
		Cow = now.C;
		if (map[Cow.x + nx[Cow.d]][Cow.y + ny[Cow.d]] != '*')
			Cow.x += nx[Cow.d], Cow.y += ny[Cow.d];
		else Cow.d = (Cow.d + 1) % 4;
		if (visit[Farm.x][Farm.y][Farm.d][Cow.x][Cow.y][Cow.d]) continue;
		visit[Farm.x][Farm.y][Farm.d][Cow.x][Cow.y][Cow.d] = true;
		Q[rear++] = node(Farm, Cow, now.step + 1);
	}
	return 0;
}
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
#endif // Clown
	for (int i = 1; i <= 10; i++) scanf("%s", map[i] + 1);
	for (int i = 0; i < 12; i++)
		map[0][i] = map[11][i] = '*',
		map[i][0] = map[i][11] = '*';
	for (int i = 1; i <= 10; i++)
	for (int j = 1; j <= 10; j++)
	if (map[i][j] == 'F') Farm = Tode(i, j);
	else if (map[i][j] == 'C') Cow = Tode(i, j);
	printf("%d\n", BFS());
	return 0;
}
