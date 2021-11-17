#include <algorithm>
#include <cstdio>
using namespace std;

typedef unsigned long long ull;
const int N = 1e6 + 7;
const int M = 1e5 + 7;
const int NN = 1420000;
const ull INF = -1;

int n, m;
bool isPrime[NN];
int base[M];
ull dp[N], primes[NN];
int primeNum;
pair<ull, int> tmp[100];
int tmpn;

void getPrimes(int n) {
    for (ull i = 2; primeNum < n; ++i) {
        if (!isPrime[i]) primes[primeNum++] = i;
        for (int j = 0; primes[j] * i < NN; ++j) {
            isPrime[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

pair<ull, int> heap[M];
int heapSz;
void swim(int p) {
    int q = p >> 1;
    pair<ull, int> a = heap[p];
    while (q && a.first < heap[q].first) {
        heap[p] = heap[q];
        p = q;
        q = p >> 1;
    }
    heap[p] = a;
}
void insert(ull a, int b) {
    heapSz++;
    heap[heapSz].first = a;
    heap[heapSz].second = b;
    swim(heapSz);
}
void sink(int p) {
    int q = p << 1;
    pair<ull, int> a = heap[p];
    while (q <= heapSz) {
        if (q < heapSz && heap[q + 1].first < heap[q].first) q++;
        if (heap[q] >= a) break;
        heap[p] = heap[q];
        p = q;
        q = p << 1;
    }
    heap[p] = a;
}
void pop() {
    heap[1] = heap[heapSz--];
    sink(1);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d%d", &m, &n);
    getPrimes(m);

    int l = primeNum;
    for (int i = 0; i < l; ++i) {
        insert(primes[i], i);
        base[i] = 1;
    }
    dp[1] = 1;
    for (int i = 2; i <= n + 1; ++i) {
        pair<ull, int> ans = heap[1];
        dp[i] = ans.first;

        tmpn = 0;
        while (heapSz && heap[1].first == dp[i]) {
            base[heap[1].second]++;
            tmp[tmpn++] = heap[1];
            pop();
        }
        for (int j = 0; j < tmpn; ++j) {
            insert(dp[base[tmp[j].second]] * primes[tmp[j].second],
                   tmp[j].second);
        }
        printf("%llu ", dp[i]);
    }
    return 0;
}