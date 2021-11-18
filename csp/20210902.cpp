#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 10007;
const int M = 500007;
int a[M], b[N];
int n;

int main() {
    // freopen("../test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    n = unique(a, a + n + 2) - a;

    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) b[a[i]]--;
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) b[a[i]]++;
    }

    int ans = 0, tmpSum = 1;
    for (int i = 0; i < N; ++i) {
        tmpSum += b[i];
        ans = max(ans, tmpSum);
    }
    printf("%d\n", n == 1 ? 0 : ans);
    return 0;
}
