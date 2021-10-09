#include <algorithm>
#include <cstdio>
#define N 1010
int n, a, dp[N], tmp[N];
using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            scanf("%d", &a);
            if (j == 0)
                tmp[j] = dp[j] + a;
            else if (j == i)
                tmp[j] = dp[j - 1] + a;
            else
                tmp[j] = max(dp[j], dp[j - 1]) + a;
        }
        for (int j = 0; j < i + 1; ++j) {
            dp[j] = tmp[j];
        }
    }

    int maxn = -1;
    for (int j = 0; j < n; ++j) {
        maxn = max(maxn, dp[j]);
    }
    printf("%d\n", maxn);
    return 0;
}