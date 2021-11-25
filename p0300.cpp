#include <cstdio>

const int N = 5e3 + 7;
int n, m, p, fa[N];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i) fa[i] = i;

    int fx, fy;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &fx, &fy);
        fx = find(fx);
        fy = find(fy);
        if (fx != fy) fa[fx] = fy;
    }
    while (p--) {
        scanf("%d%d", &fx, &fy);
        fx = find(fx);
        fy = find(fy);
        if (fx == fy)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}