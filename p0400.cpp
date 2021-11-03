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
    int x;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        add(i, x);
    }
    int op, x1, x2;
    while (m--) {
        scanf("%d%d%d", &op, &x1, &x2);
        if (op == 1) {
            add(x1, x2);
        } else {
            printf("%d\n", getSum(x2) - getSum(x1 - 1));
        }
    }
    return 0;
}