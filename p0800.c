#include <stdio.h>
#include <stdlib.h>
#define N 1000007

int n, a[N], b[N];

typedef struct HeapNode {
    int val, i, j;
} HeapNode;

int heapSz;
HeapNode heap[N];

void swim(int p) {
    int q = p >> 1;
    HeapNode a = heap[p];
    while (q && a.val < heap[q].val) {
        heap[p] = heap[q];
        p = q;
        q = p >> 1;
    }
    heap[p] = a;
}

void insertHeap(int x, int i, int j) {
    heapSz++;
    heap[heapSz].val = x;
    heap[heapSz].i = i;
    heap[heapSz].j = j;
    swim(heapSz);
}

void sink(int p) {
    int q = p << 1;
    HeapNode a = heap[p];
    while (q <= heapSz) {
        if (q < heapSz && heap[q + 1].val < heap[q].val) q++;
        if (heap[q].val >= a.val) break;
        heap[p] = heap[q];
        p = q;
        q = p << 1;
    }
    heap[p] = a;
}

HeapNode getHeapTop() {
    HeapNode r = heap[1];
    heap[1] = heap[heapSz--];
    sink(1);
    return r;
}

int cmpFunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    qsort(b, n, sizeof(int), cmpFunc);

    for (int i = 0; i < n; ++i) {
        insertHeap(a[i] + b[0], i, 0);
    }

    for (int i = 0; i < n; ++i) {
        HeapNode tmp = getHeapTop();
        printf("%d ", tmp.val);
        insertHeap(a[tmp.i] + b[tmp.j + 1], tmp.i, tmp.j + 1);
    }
    return 0;
}