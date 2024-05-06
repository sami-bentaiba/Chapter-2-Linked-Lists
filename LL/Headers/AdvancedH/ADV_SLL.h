#ifndef ADV_SLL_H_INCLUDED
#define ADV_SLL_H_INCLUDED
/*-------------- ADVANCED FUNCTIONS --------------*/
void printLL(List L);
void AddLastLL(List *L, int v);
List CreateLL(int N);
int SizeLL(List L);
List FindLL(List L, int v);
List FindPosLL(List L, int k);
void AddFirstLL(List *L, int v);
List CreateLL_Reverse(int N);
void ReverseLL(List *L);
void RemoveLL(List *L, int v);
void RemoveALL(List *L, int v);
void RemovePosLL(List *L, int k, bool *possible);
void CleanLL(List *L);
void printADVLL(char name[], List L);
List FirstPosLL(List L, int k);
List SecondPosLL(List L, int k);
void AddPosLL(List *L, int v, int k);
List CreateRanLLPos(int N);
List CreateRanLLNig(int N);
List Fusion2LL_WAN(List L, List P);
List Fusion2LL_WOAN(List L1, List L2);
void EclatementLL_WAN(List L,List *Lp,List *Ln);
void EclatementLL_WOAN(List *L,List *L1,List *L2);
/*-------------- help functions --------------*/
void HELP_ADVSLLh();
void HELP_printLL();
void HELP_AddLastLL();
void HELP_CreateLL();
void HELP_sitzeLL();
void HELP_FindLL();
void HELP_FindPosLL();
void HELP_AddFirstLL();
void HELP_CreateLL_reverse();
void HELP_ReverseLL ();
void HELP_RemoveLL();
void HELP_RemoveALL();
void HELP_RemovePosLL();
void HELP_CleanLL();
void HELP_AddPosLL();
void HELP_SecondPosLL();
void HELP_FirstPosLL();
void HELP_Fusion2LL_WAN();
void HELP_Fusion2LL_WOAN();
void HELP_EclatementLL_WAN();
void HELP_EclatementLL_WOAN();
#endif // ADVLL_H_INCLUDED