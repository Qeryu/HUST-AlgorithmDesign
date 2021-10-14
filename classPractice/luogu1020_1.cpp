#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define N 100005
int n, a[N], dpup[N], ans1, sumSystem, endSystem[N];

int main() {
    // freopen("../test.in", "r", stdin);
    while (scanf("%d", a + (n++)) != EOF)
        ;
    n--;
    dpup[ans1++] = a[0];
    endSystem[++sumSystem] = a[0];
    for (int i = 1; i < n; ++i) {
        if (dpup[ans1 - 1] >= a[i]) {
            dpup[ans1++] = a[i];
        } else {
            int p = upper_bound(dpup, dpup + ans1, a[i], greater<int>()) - dpup;
            dpup[p] = a[i];
        }

        int updateSystem = 0;
        for (int j = 1; j <= sumSystem; ++j) {
            if (endSystem[j] >= a[i]) {
                if (!updateSystem || endSystem[j] < endSystem[updateSystem])
                    updateSystem = j;
            }
        }
        if (!updateSystem)
            endSystem[++sumSystem] = a[i];
        else
            endSystem[updateSystem] = a[i];
    }

    printf("%d\n%d\n", ans1, sumSystem);
    return 0;
}