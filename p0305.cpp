#include <cstdio>
#include <cstring>
const int N = 1010;
int n, m, fa[N];

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

int main() {
    // freopen("test.in", "r", stdin);
    while (scanf("%d%d", &n, &m) && n) {
        for (int i = 1; i <= n; ++i) fa[i] = i;
        int c1, c2;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &c1, &c2);
            c1 = find(c1);
            c2 = find(c2);
            if (c1 != c2) {
                fa[c1] = c2;
                if (n) n--;
            }
        }
        printf("%d\n", n - 1);
    }
    return 0;
}