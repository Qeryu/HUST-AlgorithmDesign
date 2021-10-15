#include <algorithm>
#include <cstdio>
using namespace std;
const int T = 3e4 + 7;
int dp[T], n, m, v, w;

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &v, &w);
        for (int j = n; j >= 0; --j) {
            if (j >= v) dp[j] = max(dp[j], dp[j - v] + w * v);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}