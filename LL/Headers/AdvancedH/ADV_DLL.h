#ifndef ADV_DLL_H_INCLUDED
#define ADV_DLL_H_INCLUDED
/*-------------- ADVANCED FUNCTIONS --------------*/
void printDLL_Reverse(DLL L);
void printADVDLL_Reverse(char name[], DLL L);
void printADVDLL(char name[], DLL L);
void printDLL(DLL L);
DList FindNextDLL(DLL L, int v);
DList FindNextDLL_Reverse(DLL L, int v);
DList FindPosDLL(DLL L, int K);
void AddFirstDLL(DLL *L, int v);
void AddLastDLL(DLL *L, int v);
void CreateDLL(DLL *L, int N);
void CreateDLL_Reverse(DLL *L, int N);
void RemoveDLL(DLL *L, int v);
void CleanPrevADLL(DLL *L);
void CleanNextADLL(DLL *L);
DLL CreateRanPosDLL(int N);
DLL CreateRanNigDLL(int N);
int SizeHeadDLL(DLL L);
int SizeTailDLL(DLL L);
/*-------------- help functions --------------*/
void HELP_printADVDLL();
void HELP_printADVDLL_reverse();
void HELP_printDLL_reverse();
void HELP_FindNextDLL();
void HELP_FindNextDLL_reverse();
void HELP_FindPosDLL();
void HELP_AddFirstDLL();
void HELP_AddLastDLL();
void HELP_CreateDLL();
void HELP_CreateDLL_reverse();
void HELP_RemoveDLL();
void HELP_CleanPrevADLL();
void HELP_CleanNextADLL();
void HELP_CreateRanPosDLL();
void HELP_CreateRanNigDLL();
void HELP_SizeHeadDLL();
void HELP_SizeTailDLL();
#endif // ADVDLL_H_INCLUDED