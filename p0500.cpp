#include <cstdio>

typedef long long ll;
const int N = 1e5 + 7;
int n, m;
ll a[N], segTree[N * 3], lazyTag[N * 3];

void buildTree(int l, int r, int p) {
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
}

void updateLazyTag(int s, int e, int mid, int lchild, int rchild, int p) {
    // 向下推广lazyTag
    if (lazyTag[p]) {
        segTree[lchild] += (mid - s + 1) * lazyTag[p];
        lazyTag[lchild] += lazyTag[p];
        segTree[rchild] += (e - mid) * lazyTag[p];
        lazyTag[rchild] += lazyTag[p];
    }
    lazyTag[p] = 0;
}

void updateAdd(int l, int r, ll k, int s, int e, int p) {
    // 如果当前区间被操作区间包含了，直接进行操作，记得标记lazyTag
    if (l <= s && e <= r) {
        segTree[p] += (e - s + 1) * k;
        lazyTag[p] += k;
        return;
    }
    int mid = s + ((e - s) >> 1);
    int lchild = p << 1;
    int rchild = lchild | 1;
    updateLazyTag(s, e, mid, lchild, rchild, p);
    // 对左半区间进行更新
    if (l <= mid) updateAdd(l, r, k, s, mid, lchild);
    // 对右半区间进行更新
    if (r > mid) updateAdd(l, r, k, mid + 1, e, rchild);
    segTree[p] = segTree[lchild] + segTree[rchild];
}

ll getSum(int l, int r, int s, int e, int p) {
    if (l <= s && e <= r) return segTree[p];
    int mid = s + ((e - s) >> 1);
    int lchild = p << 1;
    int rchild = lchild | 1;
    updateLazyTag(s, e, mid, lchild, rchild, p);
    ll sum = 0;
    if (l <= mid) sum += getSum(l, r, s, mid, lchild);
    if (r > mid) sum += getSum(l, r, mid + 1, e, rchild);
    return sum;
}

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    buildTree(1, n, 1);
    int op, x, y;
    ll k;
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%lld", &x, &y, &k);
            updateAdd(x, y, k, 1, n, 1);
        } else if (op == 2) {
            scanf("%d%d", &x, &y);
            printf("%lld\n", getSum(x, y, 1, n, 1));
        }
    }
    return 0;
}