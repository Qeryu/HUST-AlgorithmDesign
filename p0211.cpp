#include <algorithm>
#include <cstdio>
using namespace std;
#define N 5010
int n, a[N], dp[N], maxlen;
// dp[i] 以第i个元素结尾的最长下降子序列长度
unsigned long long sum[N], maxSum;

int main() {
    freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[i] < a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxlen = max(maxlen, dp[i]);
        if (dp[i] == 1) sum[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (dp[i] == dp[j] + 1 && a[i] < a[j]) {
                sum[i] += sum[j];
            } else if (dp[i] == dp[j] && a[i] == a[j]) {
                printf("i == %d j == %d\n", i, j);
                sum[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i] == maxlen) {
            maxSum += sum[i];
        }
    }
    printf("%d %llu\n", maxlen, maxSum);
    return 0;
}