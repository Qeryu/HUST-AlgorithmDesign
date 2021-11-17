#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

const int N = 10000007;
pair<int, int> boundaries[N];
int n;
multiset<int> heap;

int main() {
    // freopen("test.in", "r", stdin);
    int l, h, r;
    while (scanf("%d%d%d", &l, &h, &r) != EOF) {
        boundaries[n++] = {l, -h};
        boundaries[n++] = {r, h};
    }
    sort(boundaries, boundaries + n);
    heap.insert(0);

    int pre = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        pair<int, int> b = boundaries[i];
        if (b.second < 0) {
            heap.insert(-b.second);
        } else {
            heap.erase(heap.find(b.second));
        }

        cur = *heap.rbegin();
        if (cur != pre) {
            printf("%d %d ", b.first, cur);
            pre = cur;
        }
    }
    return 0;
}