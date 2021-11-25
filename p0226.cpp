#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 7;
int n, a[N], b[N];

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    n = unique(a, a + n + 2) - a;

    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) b[a[i]]--;
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) b[a[i]]++;
    }

    int duan = 1;
    long long ans = 0;
    for (int i = 0; i <= 100000; ++i) {
        duan += b[i];
        ans += duan;
    }
    printf("%lld\n", ans);
    return 0;
}