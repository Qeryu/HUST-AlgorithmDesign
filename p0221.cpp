#include <algorithm>
#include <cstdio>
using namespace std;

const int T = 1e4 + 9;
int n, t, dp[T];

int main() {
    // freopen("test.in", "r", stdin);
    int h1, m1, h2, m2;
    scanf("%d:%d%d:%d%d", &h1, &m1, &h2, &m2, &n);
    t = (h2 - h1) * 60 + (m2 - m1);
    for (int i = 1; i <= n; ++i) {
        int ti, ci, pi;
        scanf("%d%d%d", &ti, &ci, &pi);
        if (pi == 0) {
            // 完全背包
            for (int k = 1; k * ti <= t; k <<= 1) {
                for (int j = t; j >= 0; --j) {
                    if (j >= k * ti)
                        dp[j] = max(dp[j], dp[j - k * ti] + k * ci);
                }
            }
        } else {
            // 01背包为多重背包特殊情况，可以合并
            for (int k = 1; k <= pi; k <<= 1) {
                for (int j = t; j >= 0; --j) {
                    if (j >= k * ti) {
                        dp[j] = max(dp[j], dp[j - k * ti] + k * ci);
                    }
                }
                pi -= k;
            }
            if (pi) {
                for (int j = t; j >= 0; --j) {
                    if (j >= pi * ti) {
                        dp[j] = max(dp[j], dp[j - pi * ti] + pi * ci);
                    }
                }
            }
        }
    }
    printf("%d\n", dp[t]);
    return 0;
}