#include "mesinkata.h"

boolean EndKata;    /* bisa diakses dimana saja */
Kata CKata;         /* bisa diakses dimana saja */

void IgnoreBlank()
{
   while ((CC == BLANK) && (CC != MARK))
   {
       ADV();
   }
}

void STARTKATA()

{
    EndKata = false;
    START();
    IgnoreBlank();
    ADVKATA();
}

void ADVKATA()

{
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    }
    else{
        SalinKata();
    }
}

void SalinKata()

{
    int i = 1;
    do {

        CKata.TabKata[i] = CC;

        ADV();
        i++;

    }while ( (CC != MARK) && (CC != BLANK) && (i < NMax));

    CKata.Length = i-1;
}

