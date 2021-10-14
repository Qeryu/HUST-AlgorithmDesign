#include <cstdio>
#define N 1010
int n, x[N], y[N], b[N][N], c[N][N];

// 打印LCS的内容
void printLCS(int b[N][N], int x[N], int i, int j) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == 0) {
        printLCS(b, x, i - 1, j - 1);
        printf("%d ", x[i]);
    } else if (b[i][j] == 1) {
        printLCS(b, x, i - 1, j);
    } else if (b[i][j] == 2) {
        printLCS(b, x, i, j - 1);
    }
}

int main() {
    // freopen("../test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", x + i);
    for (int i = 1; i <= n; ++i) scanf("%d", y + i);

    for (int i = 1; i <= n; ++i) c[i][0] = 0;
    for (int j = 0; j <= n; ++j) c[0][j] = 0;
    // O(n^2)dp做法，照抄课本内容
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i] == y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2;
            }
        }
    }
    // printLCS(b, x, n, n);
    // putchar('\n');
    printf("%d\n", c[n][n]);
    return 0;
}