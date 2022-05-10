#include <stdio.h>
#include <string.h>
#include "time.h"


int Jahr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int day_of_the_year(int year, int month, int days){ //Days of Year berechnen
    int ergebnis = 0;
    for(int y = 0; y < month - 1; y++){
        ergebnis += Jahr[y];
    }
    ergebnis += days;
    return ergebnis;
}

void input_date(int *year, int *month, int *days) {
    do {
        printf("\nGeben Sie das Jahr ein: ");
        scanf("%i", year);
        printf("Geben Sie den Monat ein: ");
        scanf("%i", month);
        printf("Geben Sie den Tag ein: ");
        scanf("%i", days);
    } while (!exists_date(*year, *month, *days));

    if(is_leapyear(*year) && Jahr[1] == 28) {
            Jahr[1] += 1;
    }
}

int is_leapyear(int year) {
    if(year < 1582) {
        return -1;
    }
    if(!(year % 4) && year % 100) {
        return 1;
    }
    if((year % 100) && (year % 400)) {
        return 0;
    }
    if(!(year % 400)) {
        return 1;
    }
    return 0;
}

int get_days_for_month(int year, int month) {
    int day = Jahr[month -1];

    return day;
}

int exists_date(int year, int month, int days) {
    int ERROR = 1;

    if(year < 1582 || year > 2400 ) {
        printf("This Year doesn't exist\n");
        ERROR = 0;
    }
    if(month > 12 && month < 0 ) {
        printf("This Month doesn't exist\n");
        ERROR = 0;
    }
    if(get_days_for_month(year, month) < days++ && ERROR) {
        printf("This Day doesn't exist\n");
        ERROR = 0;
    }
    return ERROR;
}

int day_of_the_week(int y, int m, int d) {
    int weekday  = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;
    return weekday;
}

int week_of_the_year(int year, int days_of_year, int days_of_week) {
    int weeks = 0;
    if(days_of_year > 3) {
        weeks = (days_of_year - days_of_week) / 7;
        weeks++;
        int weeks_rest = (days_of_year - days_of_week) % 7;
        weeks += (weeks_rest > 3) ? 1 : 0;
    }
    else{
        int last_year = day_of_the_week(1, 1, year - 1);
        weeks = last_year <= 3 ? 53 : 52;
    }
    return weeks;
}
