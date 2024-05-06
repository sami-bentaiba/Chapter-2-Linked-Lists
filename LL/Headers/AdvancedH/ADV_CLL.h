#ifndef ADV_CLL_H_INCLUDED
#define ADV_CLL_H_INCLUDED
void printCLL(List L);
int SizeCLL(List L);
List FindCLL(List L, int v);
void RemoveACLL(List *L, int v);
void AddAfterCLL(List *L, int v);
void RemoveCLL(List *L, int v);
void CleanCLL(List *L);
void CreateCLL(List *L, int N);
/*--------------------- EXO 2 ----------------------*/
//functions
List CreateRanPosCLL(int N);
List CreateRanNigCLL(int N);
void printADVCLL(char name[], List L);
List FindPosCLL(List L, int K);
#endif // ADVCLL_H_INCLUDED