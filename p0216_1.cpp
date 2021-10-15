#include <algorithm>
#include <cstdio>
using namespace std;

const int V = 20010;
int v, n, w, dp[V];
// dp[j]表示当前物品选择结束后，在总容量为j的箱子中能占的最大空间

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &v, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w);
        for (int j = v; j >= 0; --j) {
            if (j >= w)
                // 状态转移方程，可以把体积等同于价值，问题等价于01背包
                dp[j] = max(dp[j], dp[j - w] + w);
        }
    }
    printf("%d\n", v - dp[v]);
    return 0;
}