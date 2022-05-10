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
    int Datum[3] = {0,0,0};
    char* day_of_week[] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

    while(1){
        //Definieren der Datumswerte
        input_date(&Datum[0], &Datum[1], &Datum[2]);

        if(exists_date(Datum[0], Datum[1], Datum[2])) {     //Ausgabe des Tages
            int days_of_week = day_of_the_week(Datum[0], Datum[1], Datum[2]);
            int days_of_year = day_of_the_year(Datum[0], Datum[1], Datum[2]);
            int weeks = week_of_the_year(Datum[0],days_of_year ,days_of_week);
            printf("Heute ist der %i. Tag dieses Jahres\n", days_of_year);
            printf("Das ist ein %s\n",day_of_week[days_of_week]);
            printf("Das ist die %i. Woche", weeks);
            break;
        }
    }
    return 0;
}
