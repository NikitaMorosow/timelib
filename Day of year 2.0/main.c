#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "time.h"

/*********************************************
 *Days of Year Rechner
 *Autor: Nikita Morosow
 *Erstellt am: 26.04.2022
 * ******************************************/

int main () {
    char* day_of_week[] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};
    struct year sel_year;
    sel_year.day= 0;
    sel_year.month = 0;
    sel_year.year = 0;

    while(1){
        //Definieren der Datumswerte
        input_date(&sel_year);

        if(exists_date(sel_year)) {     //Ausgabe des Tages
            int days_of_week = day_of_the_week(sel_year);
            int days_of_year = day_of_the_year(sel_year);
            int weeks = week_of_the_year(sel_year.year ,days_of_year ,days_of_week);
            printf("Heute ist der %i. Tag dieses Jahres\n", days_of_year);
            printf("Das ist ein %s\n",day_of_week[days_of_week]);
            printf("Das ist die %i. Woche", weeks);
            break;
        }
    }
    return 0;
}
