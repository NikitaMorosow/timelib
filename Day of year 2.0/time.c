#include <stdio.h>
#include <string.h>
#include "time.h"


int Jahr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int day_of_the_year(struct year day_of_month){ //Days of Year berechnen
    int ergebnis = 0;
    for(int y = 0; y < day_of_month.month - 1; y++){
        ergebnis += Jahr[y];
    }
    ergebnis += day_of_month.day;
    return ergebnis;
}

void input_date(struct year *input) {   // Set the Date Values
    do {
        printf("\nGeben Sie das Jahr ein: ");
        scanf("%i", &input -> year);
        printf("Geben Sie den Monat ein: ");
        scanf("%i", &input -> month);
        printf("Geben Sie den Tag ein: ");
        scanf("%i", &input -> day);
    } while (!exists_date(*input));

    if(is_leapyear(input -> year) && Jahr[1] == 28) {   //if its a leap year add a day in Febuary
            Jahr[1] += 1;
    }
}

int is_leapyear(int year) { //Check if its a Leap Year
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

int get_days_for_month(struct year day_of_month) {  //gives out the amount of days in the month
    day_of_month.day = Jahr[day_of_month.month -1];

    return day_of_month.day;
}

int exists_date(struct year exist) {    //Checking if the day exists
    int ERROR = 1;

    if(exist.year < 1582 || exist.year > 2400 ) {
        printf("This Year doesn't exist\n");
        ERROR = 0;
    }
    if(exist.month > 12 && exist.month < 0 ) {
        printf("This Month doesn't exist\n");
        ERROR = 0;
    }
    if(get_days_for_month(exist) < exist.day++ && ERROR) {
        printf("This Day doesn't exist\n");
        ERROR = 0;
    }
    return ERROR;
}

int day_of_the_week(struct year week) {     //gives out the weekday of the date 
    int weekday  = (week.day += week.month < 3 ? week.year-- : week.year - 2, 23*week.month/9 + week.day + 4 + week.year/4- week.year/100 + week.year/400)%7;
    return weekday;
}

int week_of_the_year(int year, int days_of_year, int days_of_week) {    //gives out wich week in the year is
    struct year week;
    int weeks = 0;
    week.day = 1;
    week.month = 1;
    week.year = year - 1;
    if(days_of_year > 3) {
        weeks = (days_of_year - days_of_week) / 7;
        weeks++;
        int weeks_rest = (days_of_year - days_of_week) % 7;
        weeks += (weeks_rest > 3) ? 1 : 0;
        if(days_of_year > 362 && !is_leapyear(year) && (days_of_week < 4) && (days_of_week)) {
            weeks = 1;
        }
        else if(days_of_year > 363 && is_leapyear(year) && (days_of_week < 4) && days_of_week) {
            weeks = 1;
        }
    }
    else{
        int last_year = day_of_the_week(week);
        weeks = last_year <= 3 ? 53 : 52;
    }
    return weeks;
}
