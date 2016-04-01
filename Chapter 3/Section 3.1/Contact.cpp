/*
ID: xiaozhe7
LANG: C++
TASK: contact
DATE: 2015/ 10/ 22
Executing...
   Test 1: TEST OK [0.005 secs, 3652 KB]
   Test 2: TEST OK [0.003 secs, 3652 KB]
   Test 3: TEST OK [0.003 secs, 3652 KB]
   Test 4: TEST OK [0.005 secs, 3652 KB]
   Test 5: TEST OK [0.038 secs, 3652 KB]
   Test 6: TEST OK [0.062 secs, 3652 KB]
   Test 7: TEST OK [0.059 secs, 3652 KB]

All tests OK.
Your program ('contact') produced all correct answers!  This is your
submission #8 for this problem.  Congratulations!
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int A, B, N, M, Count[1 << 13];
bool input[maxn];
struct node{
    int x, y;
    node(int x = 0, int y = 0): x(x), y(y) {}
    bool operator < (const node& arg) const { return x > arg.x || x == arg.x && y < arg.y; }
}ans[1 << 13];

void show(int num) {
    char show_num[15];
    int tot = 0;
    for(; num; num >>= 1) show_num[tot++] = (num & 1) + '0';
    for(int i = tot - 2; i >= 0; i--) putchar(show_num[i]);
}

int main()
{
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    scanf("%d%d%d", &A, &B, &N);
    while(~scanf("%1d", input + M)) ++M;
    for(int i = 0; i < M; ++i) {
        int num = 1;
        for(int l = 0; i + l < M && l < A - 1; ++l) num = num << 1 | input[i + l];
        for(int l = A - 1; l < B && i + l < M; ++l) {
            num = num << 1 | input[i + l];
            ++Count[num];
        }
    }
    int tot = 0;
    for(int F = 1 << A, R = 1 << B + 1; F < R; ++F)
        if(Count[F]) ans[tot++] = node(Count[F], F);
    sort(ans, ans + tot);
    for(int i = 0, j = 0; i < tot && j < N; ++j) {
        bool first = true;
        int num = ans[i].x;
        int cnt = 0;
        printf("%d\n", num);
        while(i < tot && ans[i].x == num) {
            if(first) first = false;
            else putchar(' ');
            show(ans[i++].y);
            ++cnt;
            if(cnt % 6 == 0) first = true, putchar('\n');
        }
        if(cnt % 6) putchar('\n');
    }
    return 0;
}
