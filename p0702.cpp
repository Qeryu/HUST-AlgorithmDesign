#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 1007;
const int M = 1007;
typedef pair<int, int> Point;
Point a[N];
int n, m, fa[N], pNum;
struct Path {
    int x, y;
    double l;
    Path() { x = y = l = 0; }
    Path(int x, int y, double l) : x(x), y(y), l(l) {}
} p[N * N];

auto cmpSort = [](const Path& l, const Path& r) { return l.l < r.l; };

int find(int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

double dist(Point a, Point b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
        fa[i] = i;
    }
    int fx, fy, kuai = n;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &fx, &fy);
        fx = find(fx);
        fy = find(fy);
        if (fx != fy) {
            kuai--;
            fa[fx] = fy;
        }
    }
    double ans = 0.0;
    if (kuai == 1) {
        printf("%.2lf\n", ans);
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            p[pNum++] = Path(i, j, dist(a[i], a[j]));
        }
    }
    sort(p, p + pNum, cmpSort);
    for (int i = 0; i < pNum; ++i) {
        fx = find(p[i].x);
        fy = find(p[i].y);
        if (fx != fy) {
            ans += p[i].l;
            kuai--;
            if (kuai == 1) break;
            fa[fx] = fy;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}