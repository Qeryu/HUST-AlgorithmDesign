#include <algorithm>
#include <cstdio>
using namespace std;

const int M = 507;
const int N = 1007;
typedef pair<int, int> Tree;
int n, m, monkey[M], pathNum, fa[N];
Tree tree[N];
struct Path {
    int x, y, l;
    Path() { x = y = l = 0; }
    Path(int x, int y, int l) : x(x), y(y), l(l) {}
} path[N * N];

auto cmpSort = [](const Path& l, const Path& r) { return l.l < r.l; };

int dist(Tree a, Tree b) {
    return (a.first - b.first) * (a.first - b.first) +
           (a.second - b.second) * (a.second - b.second);
}

int find(int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", monkey + i);
        monkey[i] *= monkey[i];
    }
    sort(monkey + 1, monkey + m + 1);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &tree[i].first, &tree[i].second);
        for (int j = 1; j < i; ++j) {
            path[++pathNum] = Path(i, j, dist(tree[i], tree[j]));
        }
        fa[i] = i;
    }
    sort(path + 1, path + pathNum + 1, cmpSort);
    int kuai = n, maxDist = 0;
    for (int i = 1; i <= pathNum; ++i) {
        int fx = find(path[i].x), fy = find(path[i].y);
        if (fx != fy) {
            maxDist = max(maxDist, path[i].l);
            kuai--;
            if (kuai == 1) break;
            fa[fx] = fy;
        }
    }
    int ans = monkey + m + 1 - lower_bound(monkey + 1, monkey + m + 1, maxDist);
    printf("%d\n", ans);
    return 0;
}