// 最小生成树模板题
#include <algorithm>
#include <cstdio>
using namespace std;

const int M = 2e5 + 7;
const int N = 5e3 + 7;
int n, m, fa[N];
struct Road {
    int x, y, l;
} a[M];

auto cmp = [](const Road& left, const Road& right) { return left.l < right.l; };

int find(int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].l);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    sort(a, a + m, cmp);

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int fx = find(a[i].x), fy = find(a[i].y);
        if (fx != fy) {
            sum += a[i].l;
            fa[fx] = fy;
        }
    }
    printf("%d\n", sum);
    return 0;
}