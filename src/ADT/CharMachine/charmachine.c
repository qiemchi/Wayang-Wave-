/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include "../pcolor/pcolor.h"

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START() {
    pita = stdin;
    ADV();
}

void STARTFILE(char filename[]) {
    pita = fopen(filename, "r");
    if (pita != NULL) {
        ADVFILE();
    } else {
        printf("\n%SERROR: %sFile tidak ditemukan!\n\n", RED, WHITE);
        exit(0);
    }
}

void ADV() {
    retval = fscanf(pita,"%c",&CC);
    // EOP = (CC == MARK);
    // if (EOP) {
    //    fclose(pita);
    // }
}

void ADVFILE() {
    retval = fscanf(pita,"%c",&CC);
    if (feof(pita)) {
       fclose(pita);
    }
}