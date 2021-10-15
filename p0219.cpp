#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e3 + 7;
int n, m, a[N], b[N], c[N], dp[N], maxc, cid[N][N];

int main() {
    freopen("test.in", "r", stdin);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) {
        int cc;
        scanf("%d%d%d", a + i, b + i, &cc);
        c[cc]++;
        cid[cc][c[cc]] = i;
        maxc = max(cc, maxc);
    }

    for (int i = 0; i <= maxc; ++i) {
        for (int j = m; j >= 0; --j) {
            for (int k = 1; k <= c[i]; ++k) {
                if (j >= a[cid[i][k]]) {
                    dp[j] = max(dp[j], dp[j - a[cid[i][k]]] + b[cid[i][k]]);
                }
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}