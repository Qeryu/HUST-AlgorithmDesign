#include <cstdio>
#define N 25
struct pos {
    int x, y;
};

pos a = {0, 0}, b, ma;
int map[N][N];
unsigned long long ans[N][N];
int xma[9] = {0, -1, 1, 2, 2, 1, -1, -2, -2};
int yma[9] = {0, -2, -2, -1, 1, 2, 2, 1, -1};

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d%d%d", &b.x, &b.y, &ma.x, &ma.y);
    for (int i = 0; i < 9; ++i) {
        if (ma.x + xma[i] <= b.x && ma.x + xma >= 0) {
            if (ma.y + yma[i] <= b.y && ma.y + yma >= 0) {
                map[ma.x + xma[i]][ma.y + yma[i]] = 1;
            }
        }
    }
    for (int i = 0; i <= b.x; ++i) {
        for (int j = 0; j <= b.y; ++j) {
            if (map[i][j]) {
                ans[i][j] = 0;
            } else if (!i && j) {
                ans[i][j] = ans[i][j - 1];
            } else if (!j && i) {
                ans[i][j] = ans[i - 1][j];
            } else if (!i && !j) {
                ans[i][j] = 1ull;
            } else {
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
        }
    }
    printf("%llu\n", ans[b.x][b.y]);
    return 0;
}