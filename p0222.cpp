#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e3 + 7;
int n, a[N << 1], sum[N << 1];
int dp[N << 1][N << 1], p[N << 1][N << 1];

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }

    for (int i = 1; i <= (n << 1); i++) {
        sum[i] = sum[i - 1] + a[i];
        p[i][i] = i;
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= (n << 1); ++l) {
            int r = l + len - 1;
            dp[l][r] = max(dp[l][l] + dp[l + 1][r], dp[l][r - 1] + dp[r][r]) +
                       sum[r] - sum[l - 1];
        }
    }

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i][i + n - 1]);
    }
    printf("%d\n", ans);
    return 0;
}