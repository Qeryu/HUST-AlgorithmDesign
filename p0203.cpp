#include <cstdio>
#define N 60
int n, a, b;
unsigned long long pathNum[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < 41; ++i) {
        if (i < 2)
            pathNum[i] = i;
        else
            pathNum[i] = pathNum[i - 1] + pathNum[i - 2];
    }
    pathNum[1] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        printf("%llu\n", pathNum[a]);
    }
    return 0;
}