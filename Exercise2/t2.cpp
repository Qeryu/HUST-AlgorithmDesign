#include <cstdio>

const unsigned int u1 = 0xaf128e66;
const unsigned int u2 = 0x3365b701;
const int mod = 2021;
const int N = 3e5 + 7;
unsigned int a[N];
int n, m;

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }

    int l, r;
    unsigned int u;
    unsigned long long sum;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &l, &r);
        if (!(1 <= l && r <= n)) continue;
        sum = 0;
        for (int j = l; j <= r; ++j) {
            sum += a[j] % mod;
        }
        printf("%llu\n", sum);

        if (!(sum & 1))
            u = u1;
        else
            u = u2;
        for (int j = l; j <= r; ++j) {
            a[j] ^= u2;
        }
    }
    return 0;
}