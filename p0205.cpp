#include <algorithm>
#include <cstdio>
using namespace std;
#define N 1010
int map[N][N], dp[5][N][N], n, m;
// map[i][j]表示第i行第j列可消耗的卡路里
// 可以根据碰面点把两人路径分成两段
// 注意，题目中的意思其实是两人有且仅有一个路径交点
// 从左上开始顺时针给顶点标号为1234
// dp[k][i][j]表示从第k个顶点出发，到(i, j)的最大卡路里消耗

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) scanf("%d", map[i] + j);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[1][i][j] = max(dp[1][i - 1][j], dp[1][i][j - 1]) + map[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 1; --j)
            dp[2][i][j] = max(dp[2][i - 1][j], dp[2][i][j + 1]) + map[i][j];
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp[3][i][j] = max(dp[3][i + 1][j], dp[3][i][j + 1]) + map[i][j];
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp[4][i][j] = max(dp[4][i + 1][j], dp[4][i][j - 1]) + map[i][j];
    int ans = -1;
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {
            ans = max(ans, dp[1][i - 1][j] + dp[3][i + 1][j] + dp[2][i][j + 1] +
                               dp[4][i][j - 1]);
            ans = max(ans, dp[2][i - 1][j] + dp[4][i + 1][j] + dp[1][i][j - 1] +
                               dp[3][i][j + 1]);
        }
    }
    printf("%d\n", ans);

    return 0;
}