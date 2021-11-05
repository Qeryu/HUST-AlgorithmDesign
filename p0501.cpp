#include <cstdio>

typedef long long ll;
const int N = 1e5 + 7;
int n, m;
ll mod, a[N], segTree[N * 3], lazyTagMul[N * 3], lazyTagAdd[N * 3];

void buildTree(int l, int r, int p) {
    lazyTagMul[p] = 1;
    lazyTagAdd[p] = 0;
    if (l == r) {
        segTree[p] = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    int lchild = p << 1;
    int rchild = lchild | 1;
    buildTree(l, mid, lchild);
    buildTree(mid + 1, r, rchild);
    segTree[p] = segTree[lchild] + segTree[rchild];
    segTree[p] %= mod;
}

void downLazyTag(int s, int e, int mid, int lchild, int rchild, int p) {
    if (lazyTagMul[p] != 1) {
        lazyTagMul[lchild] *= lazyTagMul[p];
        lazyTagMul[lchild] %= mod;
        lazyTagMul[rchild] *= lazyTagMul[p];
        lazyTagMul[rchild] %= mod;
        lazyTagAdd[lchild] *= lazyTagMul[p];
        lazyTagAdd[lchild] %= mod;
        lazyTagAdd[rchild] *= lazyTagMul[p];
        lazyTagAdd[rchild] %= mod;
        segTree[lchild] *= lazyTagMul[p];
        segTree[lchild] %= mod;
        segTree[rchild] *= lazyTagMul[p];
        segTree[rchild] %= mod;
        lazyTagMul[p] = 1;
    }
    if (lazyTagAdd[p]) {
        lazyTagAdd[lchild] += lazyTagAdd[p];
        lazyTagAdd[lchild] %= mod;
        lazyTagAdd[rchild] += lazyTagAdd[p];
        lazyTagAdd[rchild] %= mod;
        segTree[lchild] += lazyTagAdd[p] * (mid - s + 1);
        segTree[lchild] %= mod;
        segTree[rchild] += lazyTagAdd[p] * (e - mid);
        segTree[rchild] %= mod;
        lazyTagAdd[p] = 0;
    }
}

void updateMul(int l, int r, int k, int s, int e, int p) {
    if (l <= s && e <= r) {
        lazyTagMul[p] *= k;
        lazyTagMul[p] %= mod;
        lazyTagAdd[p] *= k;
        lazyTagAdd[p] %= mod;
        segTree[p] *= k;
        segTree[p] %= mod;
        return;
    }
    int mid = s + ((e - s) >> 1);
    int lchild = p << 1;
    int rchild = lchild | 1;
    downLazyTag(s, e, mid, lchild, rchild, p);
    if (l <= mid) updateMul(l, r, k, s, mid, lchild);
    if (mid < r) updateMul(l, r, k, mid + 1, e, rchild);
    segTree[p] = segTree[lchild] + segTree[rchild];
    segTree[p] %= mod;
}

void updateAdd(int l, int r, int k, int s, int e, int p) {
    if (l <= s && e <= r) {
        lazyTagAdd[p] += k;
        lazyTagAdd[p] %= mod;
        segTree[p] += k * (e - s + 1);
        segTree[p] %= mod;
        return;
    }
    int mid = s + ((e - s) >> 1);
    int lchild = p << 1;
    int rchild = lchild | 1;
    downLazyTag(s, e, mid, lchild, rchild, p);
    if (l <= mid) updateAdd(l, r, k, s, mid, lchild);
    if (mid < r) updateAdd(l, r, k, mid + 1, e, rchild);
    segTree[p] = segTree[lchild] + segTree[rchild];
    segTree[p] %= mod;
}

ll getSum(int l, int r, int s, int e, int p) {
    if (l <= s && e <= r) {
        return segTree[p];
    }
    int mid = s + ((e - s) >> 1);
    int lchild = p << 1;
    int rchild = lchild | 1;
    downLazyTag(s, e, mid, lchild, rchild, p);
    ll sum = 0;
    if (l <= mid) sum += getSum(l, r, s, mid, lchild);
    sum %= mod;
    if (mid < r) sum += getSum(l, r, mid + 1, e, rchild);
    sum %= mod;
    return (sum + mod) % mod;
}

int main() {
    freopen("test.in", "r", stdin);
    scanf("%d%d%lld", &n, &m, &mod);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    buildTree(1, n, 1);
    int op, x, y, k;
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &x, &y, &k);
            updateMul(x, y, k, 1, n, 1);
        } else if (op == 2) {
            scanf("%d%d%d", &x, &y, &k);
            updateAdd(x, y, k, 1, n, 1);
        } else if (op == 3) {
            scanf("%d%d", &x, &y);
            printf("%lld\n", getSum(x, y, 1, n, 1));
        }
    }
    return 0;
}