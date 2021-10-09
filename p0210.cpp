#include <cstdio>
#define N 110
int n, a[N], l[N], r[N];

int main() {
    freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) {
        printf("i == %d\n", i);
        for (int j = i - 1; j >= 0; --j) {
            printf("i == %d j == %d\n", i, j);
            if (a[j] < a[i] && l[i] < l[j] + 1) {
                l[i] = l[j] + 1;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        printf("i == %d\n", i);
        for (int j = i + 1; j < n; ++j) {
            printf("i == %d j == %d\n", i, j);
            if (a[i] > a[j] && r[i] < r[j] + 1) {
                r[i] = r[j] + 1;
            }
        }
    }
    printf("!!!\n");
    int maxLen = -1;
    for (int i = 0; i < n; ++i) {
        if (maxLen < (l[i] + r[i] + 1)) {
            maxLen = l[i] + r[i] + 1;
        }
    }
    printf("%d\n", maxLen);
    return 0;
}