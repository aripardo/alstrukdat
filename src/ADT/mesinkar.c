#include "mesinkar.h"
#include <stdio.h>

char CC;        /* bisa diakses dimana saja */
boolean EOP;    /* bisa diakses dimana saja */

static FILE * pita;
static int retval;

void START() {
	pita = fopen("pitakar.txt","r");
	ADV();
}

void ADV() {
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
       fclose(pita);
 	}
}
