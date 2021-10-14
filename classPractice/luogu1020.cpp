#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define N 100005
int n, a[N], dpup[N], dpdown[N], ans1, ans2;
// dpup 最长不上升子序列，nlogn做法
// dpdown 最长上升子序列，nlogn做法

int main() {
    // freopen("../test.in", "r", stdin);
    while (scanf("%d", a + (n++)) != EOF)
        ;
    n--;
    dpup[ans1++] = a[0];
    dpdown[ans2++] = a[0];
    for (int i = 1; i < n; ++i) {
        if (dpup[ans1 - 1] >= a[i]) {
            dpup[ans1++] = a[i];
        } else {
            int p = upper_bound(dpup, dpup + ans1, a[i], greater<int>()) - dpup;
            dpup[p] = a[i];
        }

        // 由DilWorth定理可以确定，覆盖全序列需要的不上升子序列的数量等于最大上升子序列长度
        if (dpdown[ans2 - 1] < a[i]) {
            dpdown[ans2++] = a[i];
        } else {
            int p = lower_bound(dpdown, dpdown + ans2, a[i]) - dpdown;
            dpdown[p] = a[i];
        }
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}