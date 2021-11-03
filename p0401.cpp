#include <cctype>
#include <cstdio>

const int N = 5e5 + 7;
int n, m, c[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int i, int k) {
    while (i <= n) {
        c[i] += k;
        i += lowbit(i);
    }
}

int getSum(int i) {
    int res = 0;
    while (i > 0) {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    int prex = 0, nowx;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nowx);
        add(i, nowx - prex);
        prex = nowx;
    }
    int op, x, y, k;
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &x, &y, &k);
            add(x, k);
            add(y + 1, -k);
        } else if (op == 2) {
            scanf("%d", &x);
            printf("%d\n", getSum(x));
        }
    }
    return 0;
}