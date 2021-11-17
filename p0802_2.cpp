#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef unsigned long long ull;
const int N = 1e6 + 7;
const int M = 1e5 + 7;
const int NN = 1420000;
const ull INF = -1;

int n, m;
bool isPrime[NN];
ull base[N], dp[N];
vector<ull> primes;

void getPrimes(int n) {
    for (int i = 2; primes.size() < n; ++i) {
        if (!isPrime[i]) primes.push_back(i);
        for (int p : primes) {
            if (p * i > NN) break;
            isPrime[p * i] = true;
            if (i % p == 0) break;
        }
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d%d", &m, &n);
    getPrimes(m);

    int l = primes.size();
    for (int i = 0; i < l; ++i) base[i] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n + 1; ++i) {
        ull res = INF;
        for (int j = 0; j < l; ++j) {
            res = min(dp[base[j]] * primes[j], res);
        }

        for (int j = 0; j < l; ++j) {
            if (dp[base[j]] * primes[j] == res) {
                base[j]++;
            }
        }
        dp[i] = res;
        printf("%llu ", res);
    }
    return 0;
}