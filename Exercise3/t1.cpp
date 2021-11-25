#include <cstdio>

int runMonthDays[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int burMonthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isRun(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && year % 100 != 0))
        return 1;
    else
        return 0;
}

int main() {
    int year, month, day, ans = 0;
    scanf("%d/%d/%d", &year, &month, &day);
    if (month > 12) {
        ans++;
        month = month % 10;
        if (month == 2) month = 12;
    }
    if (isRun(year))
        ans += day > runMonthDays[month];
    else
        ans += day > burMonthDays[month];
    printf("%d\n", ans);
    return 0;
}