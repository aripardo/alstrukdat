/* File: point.c */
/* Tanggal: 17 September 2020 */
/* *** Implementasi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include "boolean.h"
#include "math.h"
#include "point.h"

#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
POINT MakePOINT (float X, float Y){
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}
                                              
void BacaPOINT (POINT * P){
    float X,Y;
    scanf("%f %f",&X,&Y);
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void TulisPOINT (POINT P){
    printf("(%f,%f)",Absis(P),Ordinat(P));
}
          
boolean EQ (POINT P1, POINT P2)
{
    return (Ordinat(P1)==Ordinat(P2) && Absis(P1)==Absis(P2));
}

boolean NEQ (POINT P1, POINT P2){
    return (!EQ(P1,P2));
}

boolean IsOrigin (POINT P){
    return (Absis(P)==0 && Ordinat(P)==0);
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
    return (Absis(P) == 0);
}

int Kuadran (POINT P){
    if(Absis(P)<0 && Ordinat(P)<0) {
        return 3;
    } else if(Absis(P)>0 && Ordinat(P)>0) {
        return 1;
    } else if(Absis(P)>0 && Ordinat(P)<0) {
        return 4;
    }
    else {
        return 2;
    }
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P)+=deltaX;
    Ordinat(P)+=deltaY;
    return P;
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P)+=deltaX;
    Ordinat(*P)+=deltaY;
}

float Jarak0 (POINT P){
    return (sqrt((Absis(P)*Absis(P)) + (Ordinat(P)*Ordinat(P)))); 
}

float Panjang (POINT P1, POINT P2){
    return sqrt(pow(Absis(P1)-Absis(P2),2) + pow(Ordinat(P1)-Ordinat(P2),2));
}