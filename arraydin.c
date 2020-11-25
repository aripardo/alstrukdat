#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "boolean.h"

void MakeEmpty(TabInt *T, int maxel){
    T->Neff = 0;
    T->MaxEl = maxel;
    T->TI = (int *) malloc(maxel * sizeof(int));
    IdxType i;
    for(i=IdxMin; i < maxel; i++){
        T->TI[i] = 0;
    }
    return;
}

void Dealokasi(TabInt *T){
    T->Neff = 0;
    T->MaxEl = 0;
    free((T->TI));
}

int NbElmt(TabInt T){
    return T.Neff;
}

int MaxElement(TabInt T){
    return T.MaxEl;
}

IdxType GetFirstIdx(TabInt T){
    return IdxMin;
}

IdxType GetLastIdx(TabInt T){
    return T.Neff-1;
}

boolean IsIdxValid(TabInt T, IdxType i){
    return (i >= 0 && i < T.MaxEl);
}

boolean IsIdxEff(TabInt T, IdxType i){
    return (i >= 0 && i < T.Neff);
}

boolean IsEmpty(TabInt T){
    return (T.Neff == 0);
}

boolean IsFull(TabInt T){
    return (T.Neff == T.MaxEl);
}

void BacaIsi(TabInt *T){
    int a;
    while (true){
        scanf("%d\n", &a);
        if (a >= 0 && a <= MaxElement(*T)){
            break;
        }
    }
    if (a > 0){
        IdxType i;
        T->Neff = a;
        for(i=GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
            scanf("%d\n", &(T->TI[i]));
        }
    } else if (a == 0){
        T->Neff = 0;
    }
    return;
}

void TulisIsiTab(TabInt T){
    printf("[");
    if (!IsEmpty(T)){
        int i;
        for (i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
            printf("%d", T.TI[i]);
            
            if (i != GetLastIdx(T)){
                printf(",");
            }
        }
    }
    printf("]");
    return;
}

TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
    TabInt T3;
    MakeEmpty(&T3, T1.MaxEl);
    T3.Neff = T1.Neff;
    IdxType i;
    for(i=GetFirstIdx(T3); i <=GetLastIdx(T3); i++){
        T3.TI[i] = T1.TI[i] + (T2.TI[i] * (plus ? 1 : -1));
    }
    return T3;
}

boolean IsEQ(TabInt T1, TabInt T2){
    boolean sama;
    sama = (T1.Neff == T2.Neff);
    IdxType i;
    for(i=GetFirstIdx(T1); i <=GetLastIdx(T1); i++){
        if (i > GetLastIdx(T2) || !sama){
            break;
        }
        sama = (sama&&(T1.TI[i] == T2.TI[i]));
    }
    return sama;
}

IdxType Search1(TabInt T, ElType X){
    if (IsEmpty(T)){
        return IdxUndef;
    }

    int i,result=IdxUndef;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T, i) == X){
            result = i;
            break;
        } 
    }
    return result;
}

boolean SearchB(TabInt T, ElType X){
    if (IsEmpty(T)){
        return false;
    }
    boolean found;
    found = false;
    int i;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T, i) == X){
            found = true;
            break;
        } 
    }
    return found;
}

void MaxMin(TabInt T, ElType *Max, ElType *Min){
    int i;
    *Min = Elmt(T, GetFirstIdx(T));
    *Max = Elmt(T, GetFirstIdx(T));

    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T,i) > *Max){
            *Max = Elmt(T,i);
        } else if (Elmt(T,i) < *Min) {
            *Min = Elmt(T,i);
        }
    }
    return;
}

void CopyTab(TabInt Tin, TabInt *Tout){
    TabInt hasil;
    MakeEmpty(&hasil, Tin.MaxEl);
    hasil.Neff = Tin.Neff;

    IdxType i;
    for(i=GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++){
        Elmt(hasil, i) = Elmt(Tin, i);
    }
    *Tout = hasil;
}

ElType SumTab(TabInt T){
    if (IsEmpty(T)){
        return 0;
    }
    int i,sum = 0;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        sum += Elmt(T,i);
    }
    return sum;
}

int CountX(TabInt T, ElType X){
    if (IsEmpty(T)){
        return 0;
    }
    int i,count=0;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Elmt(T,i) == X){
            count += 1; 
        }
    }
    return count;
}

boolean IsAllGenap(TabInt T){
    boolean genap = true;
    int i = GetFirstIdx(T);
    while(genap && i <= GetLastIdx(T)){
        genap = (genap && (Elmt(T,i)%2 == 0));
        i+=1;
    }
    return genap;
}

void Sort(TabInt *T, boolean asc){
    int i, j;
    IdxType key;

    for (i = GetFirstIdx(*T) + 1; i <= GetLastIdx(*T); i++){
        key = Elmt(*T, i);
        j = i-1;
        while (j >= GetFirstIdx(*T) && ((!asc && Elmt(*T,j) < key) || (asc && Elmt(*T,j) > key))){
            Elmt(*T,j+1) = Elmt(*T, j);
            j=j-1;
        }
        Elmt(*T,j+1) = key;
    }
    return;
}

void AddAsLastEl(TabInt *T, ElType X){
    if (!IsFull(*T)) {
        T->TI[(GetLastIdx(*T)+1)] = X;
        T->Neff += 1;
    }
    return;
}

void DelLastEl(TabInt *T, ElType *X){
    if (IsEmpty(*T)) return;
    *X = T->TI[GetLastIdx(*T)];
    T->Neff -= 1;
    return;
}

void GrowTab(TabInt *T, int num){
    TabInt baru;
    MakeEmpty(&baru, ((T->MaxEl)+num));
    baru.Neff = T->Neff;
    IdxType i;
    for(i=GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        Elmt(baru, i) = Elmt((*T), i);
    }
    Dealokasi(T);
    *T = baru;
}

void ShrinkTab(TabInt *T, int num){
    TabInt baru;
    int shrinked = (T->MaxEl)-num;
    MakeEmpty(&baru, shrinked);
    baru.Neff = (T->Neff < shrinked ? T->Neff : shrinked);

    IdxType i;
    for(i=GetFirstIdx(baru); i <= GetLastIdx(baru); i++){
        Elmt(baru, i) = Elmt((*T), i);
    }
    Dealokasi(T);
    *T = baru;
}

void CompactTab(TabInt *T){
    TabInt baru;
    MakeEmpty(&baru, T->Neff);
    baru.Neff = T->Neff;
    IdxType i;
    for(i=GetFirstIdx(baru); i <= GetLastIdx(baru); i++){
        Elmt(baru, i) = Elmt((*T), i);
    }
    Dealokasi(T);
    *T = baru;
}