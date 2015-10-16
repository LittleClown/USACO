///*
//ID: xiaozhe7
//LANG: C++
//PROG: agrinet
//DATE: 2015/ 10 / 16
//*/
//#include <ctime>
//#include <cmath>
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cassert>
//#include <iostream>
//#include <algorithm>
//#define REP(i, a, n) for(int i = a; i < (n); ++i)
//#define DEP(i, a, n) for(int i = a; i > (n); --i)
//#define REPIN(i, a, n) for(int i = a; i <= (n); ++i)
//#define DEPIN(i, a, n) for(int i = a; i >= (n); --i)
//#define LL long long
//using namespace std;
//
//typedef unsigned LL LLU;
//typedef unsigned int uint;
//
//const int INF = (uint)(-1) >> 2;
//const LL LNF = (LLU)(-1) >> 2;
//const int mod = 1e9 + 7;
//const LL Mod = 1e15 + 7;
//const double eps = 1e-10;
//
//struct Edge{
//	int x, y, cost;
//	Edge(int x = 0, int y = 0, int cost = 0) : x(x), y(y), cost(cost) {}
//	bool operator < (const Edge& arg) const { return cost < arg.cost; }
//};
//
//int *f;
//
//int root(int x) { return f[x] ? f[x] = root(f[x]) : x; }
//
//int main()
//{
//	//freopen("data.in", "r", stdin);
//	freopen("agrinet.in", "r", stdin);
//	freopen("agrinet.out", "w", stdout);
//	int n, tot = 0, cost;
//	scanf("%d", &n);
//	Edge *E = new Edge[n * n / 2];
//	f = new int[n + 1]();
//	REP(i, 0, n) REP(j, 0, n) {
//		scanf("%d", &cost);
//		if (cost && i < j) E[tot++] = Edge(i, j, cost);
//	}
//	sort(E, E + tot);
//	cost = 0;
//	REP(i, 0, tot) {
//		Edge& now = E[i];
//		int x = root(now.x);
//		int y = root(now.y);
//		if (x != y) cost += now.cost, f[x] = y;
//	}
//	printf("%d\n", cost);
//	return 0;
//}