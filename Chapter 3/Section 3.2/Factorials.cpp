/*
ID: xiaozhe7
TASK: fact4
LANG: C++
DATE: 2015/ 10/ 23
Executing...
   Test 1: TEST OK [0.008 secs, 3500 KB]
   Test 2: TEST OK [0.016 secs, 3500 KB]
   Test 3: TEST OK [0.008 secs, 3500 KB]
   Test 4: TEST OK [0.008 secs, 3500 KB]
   Test 5: TEST OK [0.011 secs, 3500 KB]
   Test 6: TEST OK [0.011 secs, 3500 KB]
   Test 7: TEST OK [0.011 secs, 3500 KB]
   Test 8: TEST OK [0.016 secs, 3500 KB]
   Test 9: TEST OK [0.011 secs, 3500 KB]
   Test 10: TEST OK [0.008 secs, 3500 KB]

All tests OK.
Your program ('fact4') produced all correct answers!  This is your
submission #2 for this problem.  Congratulations!
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 5e3;
const int mod = 10;

bool v[maxn];
int N, ans, prim[700], tot;

void GetPrim() {
    for(int i = 2; i < maxn; ++i) {
        if(!v[i]) prim[tot++] = i;
        for(int j = 0; j < tot && prim[j] * i < maxn; ++j) {
            v[prim[j] * i] = true;
            if(i % prim[j] == 0) break;
        }
    }
}

int ModPower(int x, int y) {
    int ans = 1;
    for(; y; y >>= 1, x = x * x % mod)
        if(y & 1) ans = ans * x % mod;
    return ans;
}

int GetNum(int r, int s = 0) {
    for(int t = r; t <= N; t *= r) s += N / t;
    return s;
}

int main()
{
#ifdef Clown
freopen("data.in", "r", stdin);
#else
freopen("fact4.in", "r", stdin);
freopen("fact4.out", "w", stdout);
#endif // Clown
    ios:: sync_with_stdio(false);
    GetPrim();
    cin >> N;
    ans = ModPower(2, GetNum(2) - GetNum(5)) * ModPower(3, GetNum(3)) % 10;
    for(int i = 3; prim[i] <= N; ++i) ans = ans * ModPower(prim[i], GetNum(prim[i])) % 10;
    cout << ans << endl;
    return 0;
}
