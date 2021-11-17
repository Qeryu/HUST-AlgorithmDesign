#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef unsigned long long ull;
const int N = 1e6 + 7;
const int M = 1e5 + 7;
const int NN = 1420000;
const ull INF = -1;

int n, m;
bool isPrime[NN];
ull base[M], dp[N];
vector<ull> primes;
vector<pair<ull, int> > tmp;

void getPrimes(int n) {
    for (ull i = 2; primes.size() < n; ++i) {
        if (!isPrime[i]) primes.push_back(i);
        for (int p : primes) {
            if (p * i >= NN) break;
            isPrime[p * i] = true;
            if (i % p == 0) break;
        }
    }
}

auto cmp = [](const pair<ull, int>& l, const pair<ull, int>& r) {
    return l.first > r.first;
};
priority_queue<pair<ull, int>, vector<pair<ull, int> >, decltype(cmp)> heap(
    cmp);

int main() {
    scanf("%d%d", &m, &n);
    getPrimes(m);

    int l = primes.size();
    for (int i = 0; i < l; ++i) {
        heap.emplace(primes[i], i);
        base[i] = 1;
    }
    dp[1] = 1;
    for (int i = 2; i <= n + 1; ++i) {
        pair<ull, int> ans = heap.top();
        dp[i] = ans.first;

        tmp.clear();
        while (!heap.empty() && heap.top().first == dp[i]) {
            ans = heap.top();
            base[ans.second]++;
            tmp.push_back(ans);
            heap.pop();
        }
        for (pair<ull, int> t : tmp) {
            heap.emplace(dp[base[t.second]] * primes[t.second], t.second);
        }
        printf("%llu ", dp[i]);
    }
    return 0;
}