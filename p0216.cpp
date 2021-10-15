#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 33;
const int V = 20010;
int v, n, w[N], dp[N][V];
// dp[i][j]表示前i个物品选择结束后，在总容量为j的箱子中能占的最大空间

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &v, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
        for (int j = v; j >= 0; --j) {
            if (j >= w[i])
                // 状态转移方程，可以把体积等同于价值，问题等价于01背包
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + w[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d\n", v - dp[n][v]);
    return 0;
}