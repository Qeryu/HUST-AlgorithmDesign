#include <algorithm>
#include <cstdio>
using namespace std;
const int T = 1e7 + 7;
int n, W, v, w, m;
long long dp[T];

int main() {
    // freopen("test.in", "r ", stdin);
    scanf("%d%d", &n, &W);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &v, &w, &m);
        // 按二进制拆分
        for (int k = 1; k <= m; k <<= 1) {
            for (int j = W; j >= 0; --j) {
                if (j >= k * w) {
                    dp[j] = max(dp[j], dp[j - k * w] + k * v);
                }
            }
            m -= k;
        }
        // 和上一个不同，上一个如果完全按照二进制拆分，最后组合出来的结果超出总容量的部分是肯定不会被计算的
        // 但是这个会出现类似5拆分124，但2+4=6>5的情况，需要进行一些处理
        if (m) {
            for (int j = W; j >= 0; --j) {
                if (j >= m * w) {
                    dp[j] = max(dp[j], dp[j - m * w] + m * v);
                }
            }
        }
    }
    printf("%lld\n", dp[W]);
    return 0;
}