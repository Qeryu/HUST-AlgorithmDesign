#include <cstdio>
#define N 60
int n;
unsigned long long niu[N];

int main() {
    freopen("test.in", "r", stdin);
    for (int i = 1; i < 55; ++i) {
        if (i < 4)
            niu[i] = i;
        else
            niu[i] = niu[i - 1] + niu[i - 3];
    }
    while (scanf("%d", &n) && n) {
        printf("%llu\n", niu[n]);
    }
    return 0;
}