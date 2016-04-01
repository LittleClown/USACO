/*
ID: xiaozhe7
TASK: kimbits
LANG: C++
DATE: 2015/ 10/ 23
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 33;
long long C[maxn][maxn], S[maxn][maxn], N, L, I;

int main()
{
#ifdef Clown
freopen("data.in", "r", stdin);
#else
freopen("kimbits.in", "r", stdin);
freopen("kimbits.out", "w", stdout);
#endif // Clown
    ios:: sync_with_stdio(false);
    cin >> N >> L >> I;
    for(int i = 0; i < maxn; ++i) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    for(int i = 0; i < maxn; ++i) {
        S[i][0] = 1;
        for(int j = 1; j < maxn; ++j) S[i][j] = S[i][j - 1] + C[i][j];
    }
    while(N--) {
        if(S[N][L] < I) {
            cout << "1";
            I -= S[N][L--];
        } else cout << "0";
    }
    cout << endl;
    return 0;
}
