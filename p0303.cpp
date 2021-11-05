#include <cstdio>

typedef long long ll;
const int N = 1e3 + 7;
int n, fa[N];
ll h, r;
struct Hole {
    ll x, y, z;
} a[N];

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    fa[r1] = r2;
}

ll dist(Hole a, Hole b) {
    ll res = (a.x - b.x) * (a.x - b.x);
    res += (a.y - b.y) * (a.y - b.y);
    res += (a.z - b.z) * (a.z - b.z);
    return res;
}

int main() {
    // freopen("test.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld%lld", &n, &h, &r);
        for (int i = 0; i <= n + 1; ++i) fa[i] = i;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
            if (a[i].z + r >= h) merge(i, n + 1);
            if (a[i].z <= r) merge(i, 0);
            for (int j = 1; j < i; ++j)
                if (dist(a[i], a[j]) <= 4 * r * r) merge(i, j);
        }
        if (find(n + 1) == find(0))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}