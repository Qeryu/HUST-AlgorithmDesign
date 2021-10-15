#include <algorithm>
#include <cstdio>
using namespace std;
const int T = 1e3 + 7;
int dp[T], t, m, ct, cv;

int main() {
    // freopen("../test.in", "r", stdin);
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &ct, &cv);
        for (int j = t; j >= 0; --j) {
            if (j >= ct) dp[j] = max(dp[j], dp[j - ct] + cv);
        }
    }
    printf("%d\n", dp[t]);
    return 0;
}