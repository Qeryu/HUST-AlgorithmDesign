#include <cstdio>
int main() {
    int n, a;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        printf("%d\n", a * a * 2 - a + 1);
    }
    return 0;
}