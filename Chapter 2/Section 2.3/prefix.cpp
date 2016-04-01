/*
ID: xiaozhe7
PROG: prefix
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

typedef char element[12];
element s[200];
char word[200000 + 1];
bool ok[200], visit[200000 + 1];
int len[200], cnt, Len;
bool check(const int& id, int pos) {
	if (pos == len[id]) return false;
	for (int i = 0, k; i < cnt; i++) if (i != id) {
		if (len[id] - pos < len[i]) continue;
		for (k = 0; k < len[i] && s[id][pos + k] == s[i][k]; k++);
		if (k == len[i] && check(id, pos + len[i]) == false) return false;
	}
	return true;
}
inline void Init() {
	for (cnt = 0; scanf("%s", s[cnt]), s[cnt][0] != '.'; cnt++)
		len[cnt] = strlen(s[cnt]);
	for (Len = 0; scanf("%c", word + Len) == 1;)
	if (word[Len] >= 'A' && word[Len] <= 'Z') Len++;
	for (int i = 0; i < cnt; i++) ok[i] = check(i, 0);
	int newcnt = 0;
	for (int i = 0; i < cnt; i++) if (ok[i]) {
		if (i != newcnt) strcpy(s[newcnt], s[i]), len[newcnt] = len[i];
		newcnt++;
	}
	cnt = newcnt;
}
int ans = 0;
void DFS(int pos) {
	if (pos == Len) return;
	for (int i = 0, k; i < cnt; i++) {
		int newpos = len[i] + pos;
		if (newpos > Len) continue;
		for (k = 0; k < len[i] && word[pos + k] == s[i][k]; k++);
		if (k == len[i]) {
			if (visit[newpos]) continue;
			visit[newpos] = true;
			if (newpos > ans) ans = newpos;
			DFS(newpos);
		}
	}
}
int main()
{
#ifdef Clown
	freopen("data.in", "r", stdin);
#else
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
#endif // Clown
	Init();
	DFS(0);
	printf("%d\n", ans);
	return 0;
}
