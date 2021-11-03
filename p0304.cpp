#include <cstdio>
#include <cstdlib>

const int N = 30000;
int fa[N + 7], sz[N + 7], w[N + 7];
// fa[i] 为第i艘船的并查集fa[i]
// sz[i] 为第i艘船所在列的船的数量，合并时使用
// w[i] 为第i艘船到并查集中父节点的权重，也就是距离

int find(int x) {
    if (fa[x] == x) return x;
    int old_fa = fa[x];
    fa[x] = find(fa[x]);
    sz[x] = sz[fa[x]];
    w[x] += w[old_fa];
    return fa[x];
}

int main() {
    // freopen("test.in", "r", stdin);
    int T;
    scanf("%d\n", &T);
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        sz[i] = 1;
        w[i] = 0;
    }
    char op;
    int i, j;
    while (T--) {
        scanf("%c%d%d\n", &op, &i, &j);
        if (op == 'M') {
            i = find(i);
            j = find(j);
            fa[i] = j;
            w[i] += sz[j];
            sz[j] += sz[i];
            sz[i] = sz[j];
        } else if (op == 'C') {
            if (find(i) != find(j)) {
                printf("-1\n");
            } else {
                printf("%d\n", abs(w[i] - w[j]) - 1);
            }
        }
    }
    return 0;
}