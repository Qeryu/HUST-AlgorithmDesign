#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;

const int N = 1e5 + 7;
int n, m, log2[N], dp[N][22];

int read() {
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void pre(int n) {
    log2[1] = 0;
    log2[2] = 1;
    for (int i = 3; i <= n; ++i) {
        log2[i] = log2[i >> 1] + 1;
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    pre(n);
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = read();
    }
    for (int j = 1; (1 << j) <= n; ++j) {
        // 注意区间[i, i+(1<<j))左闭右开
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    int l, r, len;
    while (m--) {
        l = read();
        r = read();
        len = log2[r - l + 1];
        printf("%d\n", max(dp[l][len], dp[r - (1 << len) + 1][len]));
    }
    return 0;
}