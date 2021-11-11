#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 1e6 + 7;
int n, a[N], b[N];

struct HeapNode {
    int val, i, j;
    HeapNode(int val, int i, int j) : val(val), i(i), j(j) {}
    bool operator<(const HeapNode& a) const { return val > a.val; }
};

priority_queue<HeapNode> heap;

int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    sort(b, b + n);

    // for (int i = 0; i < n; ++i) heap.push(HeapNode(a[i] + b[0], i, 0));
    for (int i = 0; i < n; ++i) heap.emplace(a[i] + b[0], i, 0);
    for (int i = 0; i < n; ++i) {
        HeapNode top = heap.top();
        heap.pop();
        printf("%d ", top.val);
        // heap.push(HeapNode(a[top.i] + b[top.j + 1], top.i, top.j + 1));
        heap.emplace(a[top.i] + b[top.j + 1], top.i, top.j + 1);
    }

    return 0;
}