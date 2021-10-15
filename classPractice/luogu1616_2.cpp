#include <algorithm>
#include <cstdio>
using namespace std;
const int T = 1e7 + 7;
int t, m, ct, cv;
long long dp[T];

int main() {
    // freopen("../test.in", "r", stdin);
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &ct, &cv);
        for (long long k = 1; k * ct <= t; k <<= 1) {
            for (int j = t; j >= 0; --j) {
                if (j >= k * ct) dp[j] = max(dp[j], dp[j - k * ct] + k * cv);
            }
        }
    }
    printf("%lld\n", dp[t]);
    return 0;
}