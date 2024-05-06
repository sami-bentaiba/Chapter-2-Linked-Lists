#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../Headers/ToolsH/Single.h"
#include "../../Headers/AdvancedH/ADV_SLL.h"
#include "../../Headers/AdvancedH/ADV_CLL.h"
/*******AVANCED TOOLS of CLL******/
/*****Builded on CLL *****/

void printCLL(List L){
  List P=L;
  P=getnext(P);
  if(L!= NULL){
    printf(">>>");
    do{
      printf("[%d]-->", getval(P)); 
        P=getnext(P);
    }while(P!=L);
    printf("[%d]>>>.\n", getval(L));
  }
  else{
    printf("Empty List.\n");
  }
}
int SizeCLL(List L){
  int N=0;
  List P=L;
  if(L!= NULL){
    do{
        N++;
        P=getnext(P);
    }while(P!=L);
  return N;
  }
}
List FindCLL(List L, int v){
    List P;
    if (!Empty(L)) { 
        P = L;
        do {
            if (getval(P) == v) return P;
            P = getnext(P);
        } while (P != L);
    }
    return (NULL);
}
void RemoveACLL(List *L, int v){
  do{
    RemoveCLL(L, v);
  }while(FindCLL(*L, v)!=NULL);
}
void AddAfterCLL(List *L, int v) {
    List P = alloc();
    setval(P, v);
    if (*L == NULL) { // the list is empty
        setNext(P, P);
        *L = P; // update the header
    } else {
        setNext(P, getnext(*L)); // set the next of the new node to the next of the head
        setNext(*L, P); // set the next of the head to the new node
        *L = P; // update the tail to point to the new node
    }
}
void RemoveCLL(List *L, int v){
  List P, Q;
  if(!Empty(*L)){ // la liste n’est pas vide
    P=*L;
    do{
      Q=P;
      P=getnext(P);
    }while((P!=*L)&&(getval(P)!=v));
    if(getval(P)==v){ // il existe un maillon contenant la valeur v
      if(P==*L){ // la valeur se trouve dans le maillon L
        if (P==Q) { // la liste contient un seul maillon
          L=NULL;
        }
        else{
          setNext(Q, getnext(P));
          *L=Q;
         }
      }
      else{
        setNext(Q, getnext(P));
      }
      Free(&P);
    }
  }
}
void CleanCLL(List *L){
  List P;
  if(!Empty(*L)){
    P=getnext(*L);
    while(P!=*L){
      setNext(*L, getnext(P));
      free(P);
      P=getnext(*L);
    }
    free(L);
    L = NULL;
  }
}
void CreateCLL(List *L, int N){
  int v;
  int i;
  init(L);
  for (i = 0; i < N; i++) {
    scanf("%d",&v);
    AddAfterCLL(L, v);
  }
}
/*--------------------- EXO 2 ----------------------*/
//functions
List CreateRanPosCLL(int N){
  List L, P, Q;
  int i;
  init(&L);
  for (i = 1; i<= N; i++) 
    AddAfterCLL(&L, i);
  
  return L;
}
List CreateRanNigCLL(int N){
  List L, P, Q;
  int i;
  init(&L);
  for (i = 1; i <= N; i++) {
    AddAfterCLL(&L, -i);
  }
  return L;
}
void printADVCLL(char name[], List L){
  List P=L;
  P=getnext(P);
  printf("Linked list : %s \n", name);
  if(L!= NULL){
    printf("<<<");
    do{
      printf("[%d]-->", getval(P));
        P=getnext(P);
    }while(P!=L);
    printf("[%d]", getval(P));
    printf(">>>.\n");
  } 
  else{
    printf("is Empty List.\n");
  }
}
List FindPosCLL(List L, int K){
  List P=L;
  if(!Empty(L)){
    for(;1<K;K--){
      P=getnext(P);
    }
    return P;
  }
  else{
    return L;
  }
}
