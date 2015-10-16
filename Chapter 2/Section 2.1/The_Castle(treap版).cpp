/*
ID: xiaozhe7
PROG: castle
LANG: C++
DATE: 15/ 06/ 24
*/

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int x, rank;
	node* ch[2];
	node(int x = -1) : x(x) {
		rank = rand();
		ch[0] = ch[1] = NULL;
	}
	int cmp(const int& x) const {
		if (x == this->x) return -1;
		return x > this->x;
	}
};

struct treap{
	node* root;
	~treap(){ cls(root); }
	treap() { build(); }
	void insert(const int& x){
		insert(root, x);
	}
	void remove(const int& x){
		remove(root, x);
	}
	bool empty() const{
		return _size <= 0;
	}
	int size() const{
		return _size;
	}
	int top() {
		return top(root);
	}
	void pop() {
		remove(top());
	}
	void cls() { cls(root), build(); }
private:
	void build() { root = new node; root->rank = 0x7fffffff; _size = 1; }
	void rotate(node* &o, bool d) {
		node* k = o->ch[!d];
		o->ch[!d] = k->ch[d];
		k->ch[d] = o; o = k;
	}
	void insert(node* &o, const int& x) {
		if (o == NULL) {
			o = new node;
			o->x = x;
			++_size;
			return;
		}
		int d = o->cmp(x);
		if (d == -1) return;
		insert(o->ch[d], x);
		if (o->rank < o->ch[d]->rank) rotate(o, !d);
	}
	void remove(node* &o, const int& x) {
		if (o == NULL) return;
		int d = o->cmp(x);
		if (d == -1) {
			node* item = o;
			if (o->ch[0] == NULL) o = o->ch[1];
			else if (o->ch[1] == NULL) o = o->ch[0];
			else {
				d = o->ch[0]->rank > o->ch[0]->rank;
				rotate(o, d);
				remove(o->ch[d], x);
				return;
			}
			delete item;
			--_size;
			return;
		}
		remove(o->ch[d], x);
	}
	int top(node* &o) const{
		if (o->ch[1] == NULL) return o->x;
		return top(o->ch[1]);
	}
	void cls(node* &o) {
		if (o == NULL) return;
		cls(o->ch[0]); cls(o->ch[1]);
		delete o;
	}
	int _size;
};

const int inf = -0x7fffff;
const int maxn = 50 + 1;
int m, n, x, y, color, t1, t2, t3, item;
int room_map[maxn << 1][maxn << 2], room_size[maxn * maxn];
bool visit[maxn << 1][maxn << 2];
treap s;

void dfs(int x, int y, const int& color, int& cnt) {
	if (x < 0 || y < 0 || x >= (m << 1) || y >= (n << 2)) return;
	if (room_map[x][y] && room_map[x][y] >= -1) return;
	if (visit[x][y]) return;
	if (room_map[x][y] == 0) room_map[x][y] = color, ++cnt;
	else visit[x][y] = true;
	dfs(x + 1, y, color, cnt); dfs(x - 1, y, color, cnt);
	dfs(x, y + 1, color, cnt); dfs(x, y - 1, color, cnt);
}

int main()
{
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	//freopen("data.in", "r", stdin);
	color = t1 = t2 = x = y = 0; t3 = 0;
	memset(room_size, 0, sizeof room_size);
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= (m << 1); i++)
	for (int j = 0; j <= (n << 2); j++)
	if (i & 1) {
		if (j & 3) room_map[i][j] = 0;
		else room_map[i][j] = -1;
	}
	else room_map[i][j] = -1;
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++) {
		scanf("%d", &t1);
		for (int k = 0; k < 4; k++) {
			if ((t1 & 1) == 0) {
				switch (k) {
				case 0:
				case 2: room_map[(i << 1) | 1][(j + k / 2) << 2] = inf; break;
				case 1:
				case 3: for (int l = 1; l < 4; l++) room_map[(i << 1) + k - 1][(j << 2) + l] = inf;
					break;
				}
			}
			t1 >>= 1;
		}
	}
	for (int i = 1; i < (m << 1); i++)
	for (int j = 1; j < (n << 2); j++) {
		if (room_map[i][j] == 0) {
			memset(visit, 0, sizeof visit);
			++color;
			dfs(i, j, color, room_size[color]);
		}
	}
	for (t1 = room_size[1], t2 = 2; t2 <= color; t2++) t1 = max(t1, room_size[t2]);
	printf("%d\n%d\n", color, t1 / 3);
	s.root->x = room_size[1] + room_size[2];
	for (int i = 1; i < color; i++)
	for (int j = i + 1; j <= color; j++)
		s.insert(room_size[i] + room_size[j]);
	while (!s.empty()) {
		item = s.top(); s.pop();
		for (int j = 1; j < (n << 2); j++)
		for (int i = (m << 1) - 1; i > 0; i--)
		if(room_map[i][j] == -1){
			for (t3 = 0; t3 < 2; t3++) {
				switch (t3) {
				case 0:	t1 = room_map[i - 1][j], t2 = room_map[i + 1][j]; break;
				case 1: t1 = room_map[i][j - 1], t2 = room_map[i][j + 1]; break;
				}
				if (t1 > 0 && t2 > 0 && t1 != t2 && room_size[t1] + room_size[t2] == item) {
					x = i, y = j; goto output;
				}
			}
		}
	}
	s.cls();
output:
	if (t3 == 0) printf("%d\n%d %d N\n", item / 3, (x >> 1) + 1, (y >> 2) + 1);
	else if(t3 == 1) printf("%d\n%d %d E\n", item / 3, x + 1 >> 1, y >> 2);
	return 0;
}
