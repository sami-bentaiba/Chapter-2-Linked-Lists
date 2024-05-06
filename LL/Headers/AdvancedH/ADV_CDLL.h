#ifndef ADV_CDLL_H_INCLUDED
#define ADV_CDLL_H_INCLUDED
/*------more Tools-----*/
void CreateCDLL(DLL *L, int N);
void printCDLL(DLL L);
void printCDLL_Reverese(DLL L);
DList FindCDLL(DLL L, int v);
void AddAfterCDLL(DLL *L, int v);
void RemoveCDLL(DLL *L, int v);
void CleanCDLL(DLL *L);
/*-------------- ADVANCED FUNCTIONS --------------*/
void printADVCDLL(char name[], DLL L);
void printADVCDLL_Reverse(char name[],DLL L);
DLL CreateRanPosCDLL(int N);
DLL CreateRanNigCDLL(int N);
int SizeTailCDLL(DLL L);
int SizeHeadCDLL(DLL L);
DList FindPosNextCDLL(DLL L, int K);
DList FindPosPrevCDLL(DLL L, int K);
#endif // ADVCLL_H_INCLUDED