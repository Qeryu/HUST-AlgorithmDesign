#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100010
long long n, pos[N][4], dp[N][4];
// pos[i][j]表示第i个位置种第j种树
// dp[i][j]表示1-i个位置在当前状态为j的情况下的最优解
// j = 0 当前种高度为10的树，比两边都矮
// j = 1 当前种高度为20的树，比两边都矮
// j = 2 当前种高度为20的树，比两边都高
// j = 3 当前种高度为30的树，比两边都高

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld%lld", pos[i], pos[i] + 1, pos[i] + 2);
    }
    // 枚举第一个位置可能种的树的种类
    long long ans = -0xffffffffll;
    for (int j = 0; j < 4; ++j) {
        memset(dp, 0, sizeof(dp));
        // 初始化第一个位置
        for (int j2 = 0; j2 < 4; ++j2) {
            dp[0][j2] = -0xffffffffll;
        }
        if (j == 0)
            dp[0][j] = pos[0][0];
        else if (j == 1)
            dp[0][j] = pos[0][1];
        else if (j == 2)
            dp[0][j] = pos[0][1];
        else if (j == 3)
            dp[0][j] = pos[0][2];
        // dp找后面的位置，转移方程显然
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][2], dp[i - 1][3]) + pos[i][0];
            dp[i][1] = dp[i - 1][3] + pos[i][1];
            dp[i][2] = dp[i - 1][0] + pos[i][1];
            dp[i][3] = max(dp[i - 1][0], dp[i - 1][1]) + pos[i][2];
        }
        // 根据第一棵树的高度选择最后一棵树的值作为结果
        if (j == 0)
            ans = max(ans, max(dp[n - 1][2], dp[n - 1][3]));
        else if (j == 1)
            ans = max(ans, dp[n - 1][3]);
        else if (j == 2)
            ans = max(ans, dp[n - 1][0]);
        else if (j == 3)
            ans = max(ans, max(dp[n - 1][0], dp[n - 1][1]));
    }
    printf("%lld\n", ans);
    return 0;
}