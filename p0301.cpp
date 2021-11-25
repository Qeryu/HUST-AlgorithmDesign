#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e3 + 7;
const int M = 1e5 + 7;
int n, m, fa[N];
struct Path {
    int x, y, t;
} p[M];

auto cmpSort = [](const Path& l, const Path& r) { return l.t < r.t; };

int find(int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 0; i < m; ++i) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].t);
    sort(p, p + m, cmpSort);
    int kuai = n, ans = -1;
    for (int i = 0; i < m; ++i) {
        int fx = find(p[i].x), fy = find(p[i].y);
        if (fx != fy) {
            kuai--;
            if (kuai == 1) ans = p[i].t;
            fa[fx] = fy;
        }
    }
    printf("%d\n", ans);
    return 0;
}