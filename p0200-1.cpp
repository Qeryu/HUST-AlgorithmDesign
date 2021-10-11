#include <algorithm>
#include <cstdio>
using namespace std;

#define N 1010
int a[N][N], dp[N][N], n;

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    // 读入金字塔到a[i][j]
    // a[i][j]表示金字塔第i行第j列的值
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    // 计算dp
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
            }
        }
    }

    // 找最后一行的最大值
    int ans = -1;
    for (int j = 0; j < n; ++j) {
        if (dp[n - 1][j] > ans) {
            ans = dp[n - 1][j];
        }
    }
    printf("%d\n", ans);
    return 0;
}