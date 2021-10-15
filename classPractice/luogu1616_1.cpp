#include <algorithm>
#include <cstdio>
using namespace std;
const int T = 1e7 + 7;
int t, m, ct, cv;
long long dp[T];

int main() {
    // freopen("../test.in", "r", stdin);
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &ct, &cv);
        for (int j = 0; j <= t; ++j) {
            if (j >= ct) dp[j] = max(dp[j], dp[j - ct] + cv);
        }
    }
    printf("%lld\n", dp[t]);
    return 0;
}