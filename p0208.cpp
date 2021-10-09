#include <cstdio>
typedef unsigned long long ull;
const int N = 25;
int n, a, b;
ull c[N][N], dp[N], sum[N];

int main() {
    // freopen("test.in", "r", stdin);
    for (int i = 0; i < N; ++i) {
        c[i][0] = c[i][i] = 1;
    }
    for (int i = 2; i < N; ++i) {
        for (int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i < 2) {
            dp[i] = 1;
            continue;
        }
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - 1 - j] * c[i - 1][j];
        }
        dp[i] >>= 1;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        if (b == 1)
            printf("%d %d\n", a, 1);
        else
            printf("%d %llu\n", a, dp[b] << 1LL);
    }
    return 0;
}