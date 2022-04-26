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
    char* day_of_week[] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag"};

    while(1){
        //Definieren der Datumswerte
        input_date(&Datum[0], &Datum[1], &Datum[2]);

        if(exists_date(Datum[0], Datum[1], Datum[2])) {     //Ausgabe des Tages
            printf("Heute ist der %i. Tag dieses Jahres\n", day_of_the_year(Datum[0], Datum[1], Datum[2]));
            printf("Das ist ein %s",day_of_week[day_of_the_week(Datum[0], Datum[1], Datum[2])]);
            break;
        }
    }
    return 0;
}
