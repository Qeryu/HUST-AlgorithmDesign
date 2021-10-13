#include <algorithm>
#include <cstdio>
using namespace std;
#define N 2010
int n, k, t[N], r[N], dp[N];
// dp[i]表示前i个人排队买票的最优时长
// t[i]表示第i个人只买自己票的用时
// r[i]表示第i个人和后面人一起买票的用时

int main() {
    // freopen("../test.in", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) scanf("%d", t + i);
        for (int i = 0; i < k - 1; ++i) scanf("%d", r + i);

        // dp计算买票时间
        dp[0] = t[0];
        dp[1] = min(t[0] + t[1], r[0]);
        for (int i = 2; i < k; ++i)
            dp[i] = min(dp[i - 2] + r[i - 1], dp[i - 1] + t[i]);

        // 格式化输出时间
        int h = dp[k - 1] / 3600 + 8;
        int m = (dp[k - 1] % 3600) / 60;
        int s = dp[k - 1] % 60;
        if (h <= 12)
            printf("%02d:%02d:%02d am\n", h, m, s);
        else {
            h %= 12;
            printf("%02d:%02d:%02d pm\n", h, m, s);
        }
    }
    return 0;
}