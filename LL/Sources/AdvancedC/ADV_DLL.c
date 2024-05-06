#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../Headers/ToolsH/Doubly.h"
#include "../../Headers/AdvancedH/ADV_DLL.h"
/*-------------- ADVANCED FUNCTIONS --------------*/
/*--------------------- EXO 2 ----------------------*/
void printDLL_Reverse(DLL L){
    DList T=L.tail;
  if(EmptyDList(T)){
    printf("is Empty List.\n");
    }
  else{
    while (!EmptyDList(getPrevDList(T))) { // la liste n’est pas vide
        printf("[%d]<-->", getValDList(T));
        T=getPrevDList(T);
      }
  if(!EmptyDList(T)){
    printf("[%d]\n", getValDList(T));
    }
  }
}
void printADVDLL(char name[], DLL L){
  printf("Linked list : %s \n", name);
  printf("head  [%s]->", name);
  DList H = L.head;
  if(EmptyDList(H)){
    printf("is Empty List.\n");
  }
  else{
  while(!EmptyDList(getNextDList(H))){//H==NULL
    printf("[%d]<-->", getValDList(H));
    H = getNextDList(H);
    }
  if(!EmptyDList(H)){
    printf("[%d]", getValDList(H));
  }
  }
  printf("<-[%s]  tail\n", name);
  }
void printADVDLL_Reverse(char name[], DLL L){
  printf("Linked list : %s \n", name);
  printf("tail [%s]->", name);    
  DList T=L.tail;
  if(EmptyDList(T)){
    printf("is Empty List.\n");
  }
  else{
    while (!EmptyDList(getPrevDList(T))) { // la liste n’est pas vide
      printf("[%d]<-->", getValDList(T));
      T=getPrevDList(T);
    }
  if(!EmptyDList(T)){
    printf("[%d]", getValDList(T));
    }
  }
  printf("<-[%s] head\n", name);
}
void printDLL(DLL L){
    DList H = L.head;
  if(EmptyDList(H)){
    printf("is Empty List.\n");
  }else{
  while (!EmptyDList(getNextDList(H))){
      printf("[%d]<-->", getValDList(H));
    H = getNextDList(H);
    }
  if(!EmptyDList(H)){
    printf("[%d]\n", getValDList(H));
}
}
}
int SizeHeadDLL(DLL L){
  int N=0;
  DList H = L.head;
  while (!EmptyDList(H)){
    N++;
    H = getNextDList(H);
  }
  return N;
}
int SizeTailDLL(DLL L){
  int N=0;
  DList T = L.tail;
  while (!EmptyDList(T)){
    N++;
    T = getPrevDList(T);
  }
  return N;
}
DList FindNextDLL(DLL L, int v){
  DList T=L.tail;
  while((!EmptyDList(T))&&(getValDList(T)!=v)){
    T=getNextDList(T);
  }
  return T;
}
DList FindNextDLL_Reverse(DLL L, int v){
  DList H=L.head;
  while ((!EmptyDList(H))&&(getValDList(H)!=v)){
    H=getPrevDList(H);
  }
  return H;
}
DList FindPosDLL(DLL L, int K) {
    DList H = L.head;
    while ((!EmptyDList(H)) && (K > 1)) {
        H = getNextDList(H);
        K--;
    }
    return H;
}
void AddFirstDLL(DLL *L, int v){
    DList P=allocDList();
    setValDList(P, v);
    if(EmptyDLL(*L)){
        setNextDList(P, NULL);
        setPrevDList(P, NULL);
        L->head = P;
        L->tail = P;
    }
    else{
        setPrevDList(P, NULL);
        setNextDList(P, L->head);
        setPrevDList(L->head, P);
        L->head = P;
    }
}
void AddLastDLL(DLL *L, int v) {
    DList P = allocDList();
    setValDList(P, v);
    if (EmptyDLL(*L)) {
        setNextDList(P, NULL);
        setPrevDList(P, NULL);
        L->head = P;
        L->tail = P;
    } else {
        setNextDList(P, NULL);
        setNextDList(L->tail, P);
        setPrevDList(P, L->tail);
        L->tail = P;
    }
}
void CreateDLL(DLL *L, int N){
    initDLL(L);
    int x;
    for (int i = 1; i <= N; i++) {
      scanf("%d", &x);
        AddLastDLL(L, x);
    }
}
void CreateDLL_Reverse(DLL *L, int N){
    initDLL(L);
    int x;
    for (int i = 1; i <= N; i++) {
      scanf("%d", &x);
        AddFirstDLL(L, x);
    }
}
void RemoveDLL(DLL *L, int v) {
    if (!EmptyDList(L->head)) { // la liste n’est pas vide
        DList P = FindPosDLL(*L, v);
        if (P != NULL) { // il existe un maillon contenant la valeur v
            if (P == L->head && P == L->tail) { // la liste contient un seul maillon
                initDLL(L); // La liste devient vide
            } else if (P == L->head) { //suppression au début
                L->head = getNextDList(P);
              setPrevDList(L->head, NULL);
            } else if (P == L->tail) { //suppression à la fin
                L->tail = getPrevDList(P);
              setNextDList(L->tail, NULL);
            } else {
                setNextDList(getPrevDList(P), getNextDList(P));
                setPrevDList(getNextDList(P), getPrevDList(P));
            }
            FreeDList(&P);
        }
    }
}
void ReverseDLL (DLL *L){
  DList H=L->head;
  DList T=L->tail;
  L->tail=H;
  L->head=T;
}
void RemoveADLL(DLL *L, int v){
  DList Q= NULL;
  DList P = L->head;
  while(!EmptyDList(P)){
    if (getValDList(P)!=v){
      Q = P;
      P = getNextDList(P);
      }
    else{
      if(EmptyDList(Q)){
        L->head=getNextDList(P);
        FreeDList(&P);
        P = L->head;
      }
      else{
        setNextDList(Q, getNextDList(P));
        FreeDList(&P);
        P=getNextDList(Q);
      }
    }
  }
}
void RemovePosDLL(DLL *L, int k, bool *possible){
  DList P, Q;
  *possible = false;
  if (k>0){
    if (k==1){
      P=L->head;
      L->head = getNextDList(L->head);
      FreeDList(&P);
      *possible = true;}
    else{
      Q=FindPosDLL(*L, k-1);
      if(!EmptyDList(Q) && !EmptyDList(getNextDList(Q))){
        P = getNextDList(Q);
        setNextDList(Q, getNextDList(P)) ;
        FreeDList(&P);
        *possible = true;
      }
    }
  }
}
void CleanPrevADLL(DLL *L) {
    DList Q = L->tail;
    while (!EmptyDList(Q)) {
        DList P = Q;
        Q = getPrevDList(Q);
        FreeDList(&P);
    }
    initDLL(L);
}
void CleanNextADLL(DLL *L) {
    DList T = L->head;
    while (!EmptyDList(T)) {
        DList P = T;
        T = getNextDList(T);
        FreeDList(&P);
    }
    initDLL(L);
}
DLL CreateRanPosDLL(int N){
DLL L=allocDLL();
initDLL(&L);
int x;
for (int i = 1; i <= N; i++) {
    AddLastDLL(&L, i);
}
return L;
}
DLL CreateRanNigDLL(int N){
  DLL L=allocDLL();
  initDLL(&L);
  int x;
  for (int i = 1; i <= N; i++) {
      AddLastDLL(&L, -i);
  }
  return L;
}
/*-------------- help functions --------------*/
void HELP_ADVDLLh() {
    printf("\nWelcome to the DLL Library Help!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("This library provides a set of functions for working with doubly linked lists.\n");
    printf("Functions available:\n");
    printf("~~~~~~~~~~~~~~~~~~~\n");
    printf("void printADVDLL(char[], DLL);\n");
    printf("void printADVDLL_reverse(char[], DLL);\n");
    printf("void printDLL_reverse(DLL);\n");
    printf("DList FindNextDLL(DLL, int);\n");
    printf("DList FindNextDLL_reverse(DLL, int);\n");
    printf("DList FindPosDLL(DLL, int);\n");
    printf("void AddFirstDLL(DLL *, int);\n");
    printf("void AddLastDLL(DLL *, int);\n");
    printf("void CreateDLL(DLL *, int);\n");
    printf("void CreateDLL_reverse(DLL *, int);\n");
    printf("void RemoveDLL(DLL *, int);\n");
    printf("void CleanPrevADLL(DLL *);\n");
    printf("void CleanNextADLL(DLL *);\n");
    printf("DLL CreateRanPosDLL(int);\n");
    printf("DLL CreateRanNigDLL(int);\n");
    printf("void HELP_ADVDLLh();\n");
    printf("\n HELP_FUNCTION(); OPTION to show more (explaining)\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  }
void HELP_printADVDLL() {
    printf("\nThis function prints the elements of a doubly linked list in forward order along with the provided name.\n");
    printf("Usage: printADVDLL(\"name_of_list\", L);\n");
}
void HELP_printADVDLL_reverse() {
    printf("\nThis function prints the elements of a doubly linked list in reverse order along with the provided name.\n");
    printf("Usage: printADVDLL_reverse(\"name_of_list\", L);\n");
}
void HELP_printDLL_reverse() {
    printf("\nThis function prints the elements of a doubly linked list in reverse order.\n");
    printf("Usage: printDLL_reverse(L);\n");
}
void HELP_FindNextDLL() {
    printf("\nThis function finds the next occurrence of a value in a doubly linked list starting from the head.\n");
    printf("Usage: FindNextDLL(L, value);\n");
}
void HELP_FindNextDLL_reverse() {
    printf("\nThis function finds the next occurrence of a value in a doubly linked list starting from the tail.\n");
    printf("Usage: FindNextDLL_reverse(L, value);\n");
}
void HELP_FindPosDLL() {
    printf("\nThis function finds the node at a specified position in a doubly linked list.\n");
    printf("Usage: FindPosDLL(L, position);\n");
}
void HELP_AddFirstDLL() {
    printf("\nThis function adds a new node with a value at the beginning of a doubly linked list.\n");
    printf("Usage: AddFirstDLL(&L, value);\n");
}
void HELP_AddLastDLL() {
    printf("\nThis function adds a new node with a value at the end of a doubly linked list.\n");
    printf("Usage: AddLastDLL(&L, value);\n");
}
void HELP_CreateDLL() {
    printf("\nThis function creates a new doubly linked list with nodes containing values provided by the user.\n");
    printf("Usage: CreateDLL(&L, number_of_nodes);\n");
}
void HELP_CreateDLL_reverse() {
    printf("\nThis function creates a new doubly linked list with nodes containing values provided by the user, in reverse order.\n");
    printf("Usage: CreateDLL_reverse(&L, number_of_nodes);\n");
}
void HELP_RemoveDLL() {
    printf("\nThis function removes the first occurrence of a value from a doubly linked list.\n");
    printf("Usage: RemoveDLL(&L, value);\n");
}
void HELP_CleanPrevADLL() {
    printf("\nThis function frees all nodes in a doubly linked list starting from the tail.\n");
    printf("Usage: CleanPrevADLL(&L);\n");
}
void HELP_CleanNextADLL() {
    printf("\nThis function frees all nodes in a doubly linked list starting from the head.\n");
    printf("Usage: CleanNextADLL(&L);\n");
}
void HELP_CreateRanPosDLL() {
    printf("\nThis function creates a new doubly linked list with nodes containing random positive values.\n");
    printf("Usage: CreateRanPosDLL(number_of_nodes);\n");
}
void HELP_CreateRanNigDLL() {
    printf("\nThis function creates a new doubly linked list with nodes containing random negative values.\n");
    printf("Usage: CreateRanNigDLL(number_of_nodes);\n");
}