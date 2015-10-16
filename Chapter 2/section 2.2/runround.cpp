///*
//ID: xiaozhe7
//LANG: C++
//PROG: runround
//DATE: 15/ 07/ 08
//*/
//
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//short int bit[10], total, cnt, pos;
//int n, tmp;
//bool visit[10];
//bool check() {
//	memset(visit, 0, sizeof visit);
//	cnt = 0; pos = (1 + bit[1]) % total;
//	while (cnt < total) {
//		if (visit[pos]) return false;
//		visit[pos] = true; ++cnt;
//		pos = (pos + bit[pos]) % total;
//	}
//	return true;
//}
//bool ok() {
//	memset(visit, 0, sizeof visit);
//	for (tmp = n, visit[0] = true; tmp; tmp /= 10)
//	if (visit[tmp % 10]) return false;
//	else visit[tmp % 10] = true;
//	return true;
//}
//void renew() {
//	do{ n++; } while (ok() == false);
//}
//int main()
//{
//	freopen("runround.in", "r", stdin);
//	freopen("runround.out", "w", stdout);
//	//freopen("data.in", "r", stdin);
//	scanf("%d", &n);
//	renew();
//	while (1) {
//		for (tmp = n, total = 0; tmp; tmp /= 10)
//			bit[++total] = tmp % 10;
//		for (tmp = 1; tmp <= total / 2; tmp++)
//			swap(bit[tmp], bit[total - tmp + 1]);
//		bit[0] = bit[total];
//		if (check()) break;
//		renew();
//	}
//	printf("%d\n", n);
//	return 0;
//}