#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*********************************************
 *Days of Year Rechner
 *Autor: Nikita Morosow
 *Erstellt am: 15.03.2022
 * ******************************************/

int Jahr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int day_of_the_year(int year, int month, int days){ //Days of Year berechnen
    int ergebnis = 0;
    for(int y = 0; y < month - 1; y++){
        ergebnis += Jahr[y];
    }
    ergebnis += days;
    return ergebnis;
}

/*void input_date(int *year, int *month, int *days) {
    int ERROR = 1;
    if(&year < 0 && &year > 2400) {
        printf("This Year doesn't exist\n");
        ERROR = 0;
    }
    if(&month > 12 && &month < 0 && ERROR) {
        printf("This Month doesn't exist\n");
        ERROR = 0;
    }
    if(Jahr[&month - 1] < &days && &days < 0 && ERROR) {
        printf("This Day doesn't exist\n");
        ERROR = 0;
    }
    if(!ERROR) {
        printf("\nGeben Sie das Jahr ein: ");
        scanf("%i", &year);
        printf("Geben Sie den Monat ein: ");
        scanf("%i", &month);
        printf("Geben Sie den Tag ein: ");
        scanf("%i", &days);
    }
}*/

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

int main () {
    int Datum[3] = {0,0,0};

    int LEAP = 1;
    while(1){
        //Definieren der Datumswerte
        printf("  *** Tag des Jahres ***\n");
        printf("Geben Sie das Jahr ein: ");
        scanf("%i", &Datum[0]);
        printf("Geben Sie den Monat ein: ");
        scanf("%i", &Datum[1]);
        printf("Geben Sie den Tag ein: ");
        scanf("%i", &Datum[2]);
        
        //Abfrage ob der Tag oder Monat exestiert
        if(is_leapyear(Datum[0]) && LEAP) {
            Jahr[1] += 1;
            LEAP = 0;
        }

        //Abfrage ob der Tag oder Monat exestiert

        if(exists_date(Datum[0], Datum[1], Datum[2])) {     //Ausgabe des Tages
            printf("Heute ist der %i. Tag dieses Jahres\n", day_of_the_year(Datum[0], Datum[1], Datum[2]));
            break;
        }
    }
    return 0;
}