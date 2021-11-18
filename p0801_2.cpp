#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int N = 10000007;
struct Boundary {
    int l, h, r;
    Boundary() { l = h = r = 0; }
    Boundary(int l, int h, int r) : l(l), h(h), r(r) {}
};
vector<Boundary> boundaries;

auto cmpHeap = [](const Boundary& child, const Boundary& parent) {
    if (child.h == parent.h) {
        return child.r > parent.r;
    } else {
        return child.h < parent.h;
    }
};
auto cmpSort = [](const Boundary& left, const Boundary& right) {
    return left.l < right.l;
};
priority_queue<Boundary, vector<Boundary>, decltype(cmpHeap)> heap(cmpHeap);

int main() {
    freopen("test.in", "r", stdin);
    int l, h, r;
    while (scanf("%d%d%d", &l, &h, &r) != EOF) {
        boundaries.emplace_back(l, h, r);
    }
    sort(boundaries.begin(), boundaries.end(), cmpSort);
    Boundary cur = Boundary();
    vector<pair<int, int>> ans;
    for (auto b : boundaries) {
        while (!heap.empty() && heap.top().r < b.l) {
            Boundary heapTop = heap.top();
            heap.pop();
            if (heapTop.r >= cur.r) {
                if (heap.empty() || heapTop.h > heap.top().h) {
                    while (!heap.empty() && heapTop.r > heap.top().r)
                        heap.pop();
                    heapTop.h = heap.empty() ? 0 : heap.top().h;
                    if (heapTop.r == ans[ans.size() - 1].first) {
                        ans[ans.size() - 1].second =
                            min(ans[ans.size() - 1].second, heapTop.h);
                    } else {
                        ans.emplace_back(heapTop.r, heapTop.h);
                    }
                }
                cur = heapTop;
            }
        }

        if (heap.empty() || b.h > heap.top().h) {
            if (!ans.empty() && b.l == ans[ans.size() - 1].first) {
                ans[ans.size() - 1].second = b.h;
            } else {
                ans.emplace_back(b.l, b.h);
            }
        }
        heap.push(b);
    }

    while (!heap.empty()) {
        Boundary heapTop = heap.top();
        heap.pop();
        if (heapTop.r >= cur.r) {
            if (heap.empty() || heapTop.h > heap.top().h) {
                while (!heap.empty() && heapTop.r > heap.top().r) heap.pop();
                heapTop.h = heap.empty() ? 0 : heap.top().h;
                if (heapTop.r == ans[ans.size() - 1].first) {
                    ans[ans.size() - 1].second =
                        min(ans[ans.size() - 1].second, heapTop.h);
                } else {
                    ans.emplace_back(heapTop.r, heapTop.h);
                }
            }
            cur = heapTop;
        }
    }
    for (auto a : ans) {
        printf("%d %d ", a.first, a.second);
    }
    return 0;
}