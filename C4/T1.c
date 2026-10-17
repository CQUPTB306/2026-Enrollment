#include <stdio.h>
#include <stdbool.h>

struct Date {
    int year, month, day;
};

typedef struct T1 {
    struct Date date;
    int answer;
} T1;

bool isLeapYear(int year);

int main() {
    T1 t1 = {1900, 1, 1, 0};
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d %d %d", &t1.date.year, &t1.date.month, &t1.date.day);
    if (t1.date.year < 1900 || t1.date.year > 2100 || t1.date.month <= 0 || t1.date.month > 12) {
        printf("Error");
        return 0;
    }

    if (isLeapYear(t1.date.year)) {
        days[1]++;
    }
    
    if (t1.date.day <= 0 || t1.date.day > days[t1.date.month - 1]) {
        printf("Error");
        return 0;
    }

    for (int i = 0; i < (t1.date.month - 1); i++) {
        t1.answer += days[i];
    }
    t1.answer += t1.date.day;

    printf("%d", t1.answer);
    return 0;
}

bool isLeapYear(int year) {
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? true : false;
}

// Cost 21 min
