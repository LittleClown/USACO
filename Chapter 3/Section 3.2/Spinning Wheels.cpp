/*
ID: xiaozhe7
TASK: spin
LANG: C++
DATE: 2015/ 10/ 26
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int s[5], w[5], sw[5][5], ew[5][5];

int main()
{
#ifdef Clown
freopen("data.in", "r", stdin);
#else
freopen("spin.in", "r", stdin);
freopen("spin.out", "w", stdout);
#endif // Clown
    for(int i = 0; i < 5; ++i) {
        scanf("%d%d", s + i, w + i);
        for(int t = 0; t < w[i]; ++t)
            scanf("%d%d", sw[i] + t, ew[i] + t);
    }

    return 0;
}
