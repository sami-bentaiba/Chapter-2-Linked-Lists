#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../../Headers/ToolsH/Doubly.h"
#include"../../Headers/AdvancedH/ADV_DLL.h"
/*******TOOLS of CDLL******/
void CreateCDLL(DLL *L, int N){
    initDLL(L);
    int x;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &x);
        AddLastDLL(L, x);
    }
    if (L->head != NULL && L->tail != NULL) {
        L->head->prev = L->tail;
        L->tail->next = L->head;
    }
}
void printCDLL(DLL L){
  DList P = L.head;
  printf("<<<");
  printf("[%d]<-->", getValDList(P));
  P = getNextDList(P);
    if (getNextDList(P) != NULL) {
        do {
          printf("[%d]<-->", getValDList(P));
            P = getNextDList(P);
        } while (getNextDList(P) != L.head);
      printf("[%d]", getValDList(P));
      printf(">>>\n");
    } else {
        printf("Empty List.\n");
    }
}
void printCDLL_Reverese(DLL L) {
  DList P = L.head;
  printf("<<<");
  printf("[%d]<-->", getValDList(P));
  P = getPrevDList(P);
    if (getPrevDList(P) != NULL) {
        do {
          printf("[%d]<-->", getValDList(P));
            P = getPrevDList(P);
        } while (getPrevDList(P) != L.head);
      printf("[%d]", getValDList(P));
      printf(">>>\n");
    } else {
        printf("Empty List.\n");
    }
}
DList FindCDLL(DLL L, int v) {
    DList P;
    if (!EmptyDLL(L)) {
        P = L.head;
        do {
            if (getValDList(P) == v) 
              return P;
            P = getNextDList(P);
        } while (P != L.head);
    }
    return NULL;
}
void AddAfterCDLL(DLL *L, int v) {
    DList P = allocDList();
    setValDList(P, v);
    if (EmptyDLL(*L)) { // the list is empty
        setNextDList(P, P);
        setPrevDList(P, P);
        L->head = P;
        L->tail = P;
    } else {
        DList nextNode = getNextDList(L->head);
        setNextDList(P, nextNode);
        setPrevDList(P, L->head);
        setNextDList(L->head, P);
        setPrevDList(nextNode, P);
        L->tail = P;
    }
}
void removeCDLL(DLL *L, int v) {
    DList P = FindCDLL(*L, v);
    if (P != NULL) {
        DList prevNode = getPrevDList(P);
        DList nextNode = getNextDList(P);
        setNextDList(prevNode, nextNode);
        setPrevDList(nextNode, prevNode);
        if (P == L->head) L->head = nextNode;
        if (P == L->tail) L->tail = prevNode;
        FreeDList(&P);
    }
}
void CleanCDLL(DLL *L) {
    DList P = L->head;
    if (!EmptyDLL(*L)) {
        do {
            DList temp = P;
            P = getNextDList(P);
            FreeDList(&temp);
        } while (P != L->head);
        initDLL(L);
    }
}
/*******ADVANCED TOOLS of CDLL******/
/*****Builded on DLL *****/
//functions
void printADVCDLL(char name[],DLL L){
  printf("Linked list : %s \n", name);
  printCDLL(L);
}
void printADVCDLL_Reverse(char name[],DLL L){
  printf("Linked list : %s \n", name);
  printCDLL_Reverese(L);
}
DLL CreateRanPosCDLL(int N){
  DLL L;
  initDLL(&L);
  for (int i = 1; i <= N; i++) {
      AddLastDLL(&L, i);
  }
  if (L.head != NULL && L.tail != NULL) {
      L.head->prev = L.tail;
      L.tail->next = L.head;
  }
  return L;
}
DLL CreateRanNigCDLL(int N){
  DLL L;
  initDLL(&L);
  for (int i = 1; i <= N; i++) {
      AddLastDLL(&L, -i);
  }
  if (L.head != NULL && L.tail != NULL) {
      L.head->prev = L.tail;
      L.tail->next = L.head;
  }
  return L;
}
int SizeHeadCDLL(DLL L){
  DList P = L.head;
  int N=0;
  if (P != NULL) {
    do {
      N++;
      P = getNextDList(P);
      }while(P != L.head);
    }
  else {
    printf("Empty List.\n");
  }
  return N;
}
int SizeTailCDLL(DLL L){
  DList P = L.tail;
  int N=0;
  if (P != NULL) {
    do {
      N++;
      P = getPrevDList(P);
      }while(P != L.tail);
    }
  else {
    printf("Empty List.\n");
  }
  return N;
}
DList FindPosNextCDLL(DLL L, int K){
  DList P=L.head;
  if(!EmptyDLL(L)){
    for(;1<K;K--){
      P = getNextDList(P);
    }
    return P;
  }
  else{
    return L.head;
  }
}
DList FindPosPrevCDLL(DLL L, int K){
  DList P=L.tail;
  if(!EmptyDLL(L)){
    for(;1<K;K--){
      P = getPrevDList(P);
    }
    return P;
  }
  else{
    return L.tail;
  }
}
