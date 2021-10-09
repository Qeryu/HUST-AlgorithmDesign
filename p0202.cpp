#include <cstdio>
#define N 60
int n, a, b;
unsigned long long pathNum[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < 50; ++i) {
        if (i < 2)
            pathNum[i] = 1;
        else
            pathNum[i] = pathNum[i - 1] + pathNum[i - 2];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        b -= a;
        printf("%llu\n", pathNum[b]);
    }
    return 0;
}