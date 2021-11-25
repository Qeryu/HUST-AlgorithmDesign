#include <bits/stdc++.h>
using namespace std;
// int A[2000001];
vector<int> A;
// dp[i]：价值为i所用到的最少钱币数
// array<int,2000000> dp;
int dp[1000000];
int main() {
    int m, n, temp;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        A.push_back(temp);
    }
    // dp.fill(m+1);
    for (int i = 1; i < 1000000; i++) {
        dp[i] = m + 1;
    }
    dp[0] = 0;
    for (int i = 0; i <= m; i++) {
        //这么用o
        // for (auto j : A)
        for (auto j : A) {
            if ((i - j) < 0)  // break;
                continue;
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    int printmax = 0;
    for (int i = 0; i <= m; i++) {
        //要看他们最多需要多少个
        printmax = max(printmax, dp[i]);
    }
    if (printmax == m + 1)
        printf("No answer!!!");
    else
        printf("%d\n", printmax);
}