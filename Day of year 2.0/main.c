#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "time.h"

/*********************************************
 *Days of Year Rechner
 *Autor: Nikita Morosow
 *Erstellt am: 15.03.2022
 * ******************************************/

int main () {
    int Datum[3] = {0,0,0};

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

        //Abfrage ob der Tag oder Monat exestiert

        if(exists_date(Datum[0], Datum[1], Datum[2])) {     //Ausgabe des Tages
            printf("Heute ist der %i. Tag dieses Jahres\n", day_of_the_year(Datum[0], Datum[1], Datum[2]));
            break;
        }
    }
    return 0;
}