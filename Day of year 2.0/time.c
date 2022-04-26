#include <stdio.h>
#include "time.h"


int day_of_the_year(int year, int month, int days);

int is_leapyear(int year);

int get_days_for_month(int year, int month);

int exists_date(int year, int month, int days);


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
    if(get_days_for_month(year, month) <= days && ERROR) {
        printf("This Day doesn't exist\n");
        ERROR = 0;
    }
    return ERROR;
}