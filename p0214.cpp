#include <algorithm>
#include <cstdio>
using namespace std;

typedef unsigned long long ull;
const int N = 2e6 + 7;
ull n, m, a[N];

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%llu%llu", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%llu", a + i);

    sort(a, a + n);
    int startp = 0;
    while (a[startp] < 1) startp++;
    if (a[startp] != 1) {
        printf("No answer!!!\n");
        return 0;
    }

    ull tmpN = 0, ans = 0, k;
    for (ull i = startp; i < n - 1; ++i) {
        if (a[i] == 0) continue;
        if (a[i + 1] > m) {
            a[i + 1] = m;
            n = i + 1;
            break;
        }
        if (tmpN < a[i + 1] - 1) {
            k = (a[i + 1] - 2 - tmpN) / a[i] + 1;
            tmpN += a[i] * k;
            ans += k;
            if (tmpN >= m) {
                printf("%llu\n", ans);
                return 0;
            }
        }
    }
    k = (m - tmpN) / a[n - 1];
    tmpN += a[n - 1] * k;
    ans += k;
    if (tmpN != m) ans++;
    printf("%llu\n", ans);
    return 0;
}