#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define N 100010
int n, x[N], y, map[N], t[N], dp[N], ans;

// 由于题目比较特殊，给出的元素是1-n的不会出现重复的序列
// 所以可以有一些优化的思路
// 建立map记录x中元素与其标号的关系，即建立了一个1-n中元素与x标号的关系
// 对y中元素可以通过map找到其在x中的标号，建立对应标号序列t
// 找到这个对应标号序列t的最长上升子序列，也就找到了LCS
// 即把LCS问题转换为O(nlogn)可解的LIS问题

int main() {
    // freopen("../test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", x + i);
        map[x[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &y);
        t[i] = map[y];
        int p = lower_bound(dp, dp + ans, t[i]) - dp;
        dp[p] = t[i];
        ans = max(ans, p + 1);
    }
    printf("%d\n", ans);
    return 0;
}