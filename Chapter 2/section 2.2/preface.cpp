///*
//ID: xiaozhe7
//PROG: preface
//LANG: C++
//Date: 15/ 07/ 07
//*/
//
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int numT[] = { 0, 1, 2, 3, 1, 0, 1, 2, 3, 1 };
//const int numF[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 };
//const int sumT[] = { 0, 1, 3, 6, 7, 7, 8, 10, 13, 14 };
//const int sumF[] = { 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5 };
//int f['X' + 1];
//
//int main()
//{
//	freopen("preface.in", "r", stdin); 
//	freopen("preface.out", "w", stdout);
//	//freopen("data.in", "r", stdin);
//	int n, a, b, c, d;
//	scanf("%d", &n);
//	d = n % 10; c = n / 10 % 10; b = n / 100 % 10; a = n / 1000 % 10;
//	f['I'] = (a * 100 + b * 10 + c) * 14 + sumT[d];
//	f['V'] = (a * 100 + b * 10 + c) * 5 + sumF[d];
//	f['X'] = (a * 10 + b) * 150 + sumT[max(0, c - 1)] * 10 + c + numT[c] * (d + 1) + (d == 9);
//	f['L'] = (a * 10 + b) * 50 + sumF[max(0, c - 1)] * 10 + numF[c] * (d + 1);
//	f['C'] = a * 1500 + sumT[max(0, b - 1)] * 100 + b * 10 + numT[b] * (c * 10 + d + 1) + (c == 9) * (d + 1);
//	f['D'] = a * 500 + sumF[max(0, b - 1)] * 100 + numF[b] * (c * 10 + d + 1);
//	f['M'] = sumT[max(0, a - 1)] * 1000 + a * 100 + numT[a] * (b * 100 + c * 10 + d + 1) + (b == 9) * (c * 10 + d + 1);
//	if (f['I'] > 0) printf("I %d\n", f['I']);
//	if (f['V'] > 0) printf("V %d\n", f['V']);
//	if (f['X'] > 0) printf("X %d\n", f['X']);
//	if (f['L'] > 0) printf("L %d\n", f['L']);
//	if (f['C'] > 0) printf("C %d\n", f['C']);
//	if (f['D'] > 0) printf("D %d\n", f['D']);
//	if (f['M'] > 0) printf("M %d\n", f['M']);
//	return 0;
//}