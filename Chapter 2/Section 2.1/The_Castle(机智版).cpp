///*
//ID: xiaozhe7
//PROG: castle
//LANG: C++
//DATE: 15/ 06/ 24
//*/
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int inf = -0x7fffff;
//const int maxn = 50 + 1;
//int m, n, x, y, color, t1, t2, t3, Ans;
//int room_map[maxn << 1][maxn << 2], ans[maxn << 1][maxn << 2], room_size[maxn * maxn], tot = 0;
//bool visit[maxn << 1][maxn << 2], East;
//
//void dfs(int x, int y, const int& color, int& cnt) {
//	if (x < 0 || y < 0 || x >= (m << 1) || y >= (n << 2)) return;
//	if (room_map[x][y] && room_map[x][y] >= -1) return;
//	if (visit[x][y]) return;
//	if (room_map[x][y] == 0) room_map[x][y] = color, ++cnt;
//	else visit[x][y] = true;
//	dfs(x + 1, y, color, cnt); dfs(x - 1, y, color, cnt);
//	dfs(x, y + 1, color, cnt); dfs(x, y - 1, color, cnt);
//}
//
//int main()
//{
//	freopen("castle.in", "r", stdin);	
//	freopen("castle.out", "w", stdout);
//	//freopen("data.in", "r", stdin);
//	color = Ans = t1 = t2 = x = y = t3 = 0;
//	East = false;
//	memset(room_size, 0, sizeof room_size);
//	memset(ans, 0, sizeof ans);
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i <= (m << 1); i++)
//	for (int j = 0; j <= (n << 2); j++)
//	if (i & 1) {
//		if (j & 3) room_map[i][j] = 0;
//		else room_map[i][j] = -1;
//	}
//	else room_map[i][j] = -1;
//	for (int i = 0; i < m; i++)
//	for (int j = 0; j < n; j++) {
//		scanf("%d", &t1);
//		for (int k = 0; k < 4; k++) {
//			if ((t1 & 1) == 0) {
//				switch (k) {
//				case 0: 
//				case 2: room_map[(i << 1) | 1][(j + k / 2) << 2] = inf; break;
//				case 1:
//				case 3: for (int l = 1; l < 4; l++) room_map[(i << 1) + k - 1][(j << 2) + l] = inf;
//					break;
//				}
//			}
//			t1 >>= 1;
//		}
//	}
//	for (int i = 1; i < (m << 1); i++)
//	for (int j = 1; j < (n << 2); j++) {
//		if (room_map[i][j] == 0) {
//			memset(visit, 0, sizeof visit);
//			++color;
//			dfs(i, j, color, room_size[color]);
//		}
//	}
//	for (t1 = room_size[1], t2 = 2; t2 <= color; t2++) t1 = max(t1, room_size[t2]);
//	printf("%d\n%d\n", color, t1 / 3);
//	for (int j = 1; j <= n; j++)
//	for (int i = n; i >= 1; i--) {
//		t1 = (i - 1 << 1), t2 = (j << 2) - 1;
//		if (i > 1 && t1 > 0 && t2 > 0 && room_map[t1][t2] == -1) {
//			if (room_map[t1 + 1][t2] != room_map[t1 - 1][t2]) {
//				t3 = room_size[room_map[t1 + 1][t2]] + room_size[room_map[t1 - 1][t2]];
//				if (Ans < t3) Ans = t3, x = i, y = j, East = false;
//			}
//		}
//		t1 = (i << 1) - 1, t2 = (j << 2);
//		if (j < n && t1 > 0 && t2 > 0 && room_map[t1][t2] == -1) {
//			if (room_map[t1][t2 - 1] != room_map[t1][t2 + 1]) {
//				t3 = room_size[room_map[t1][t2 - 1]] + room_size[room_map[t1][t2 + 1]];
//				if (Ans < t3) Ans = t3, x = i, y = j, East = true;
//			}
//		}
//	}
//	printf("%d\n%d %d ", Ans / 3, x, y);
//	if(East) printf("E\n");
//	else printf("N\n");
//	return 0;
//}
