#include <cstdio>
const long long mod = 1000000000000000ull;
const int N = 110;
int n, k;
struct bigNum {
    long long t0, t1;
    bigNum operator+(const bigNum& b) {
        bigNum a;
        a.t0 = t0 + b.t0;
        a.t1 = t1 + b.t1;
        a.t0 += a.t1 / mod;
        a.t1 %= mod;
        return a;
    }
    bigNum operator-(const bigNum& b) {
        bigNum a;
        a.t0 = t0 - b.t0;
        if (t1 < b.t1) {
            a.t1 = mod + t1 - b.t1;
            a.t0 -= 1;
        } else {
            a.t1 = t1 - b.t1;
        }
        return a;
    }
} dp[N][2], tmp = {0ll, 1ll};

void printBigNum(bigNum a) {
    if (a.t0)
        printf("%lld%015lld\n", a.t0, a.t1);
    else
        printf("%lld\n", a.t1);
}

int main() {
    // freopen("test.in", "r", stdin);
    while (scanf("%d%d", &n, &k) != EOF) {
        bigNum ans = {0ll, 1ll};

        dp[0][1] = {0ll, 1ll};
        dp[0][0] = {0ll, 0LL};

        for (int i = 1; i <= n; ++i) {
            ans = ans + ans;
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i][0];
            if (i == k)
                dp[i][1] = dp[i][1] - tmp;
            else if (i > k - 1)
                dp[i][1] = dp[i][1] - dp[i - k][0];
        }
        printBigNum(ans - dp[n][0] - dp[n][1]);
    }
    return 0;
}