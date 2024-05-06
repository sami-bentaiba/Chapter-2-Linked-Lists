#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../../Headers/ToolsH/Doubly.h"
DList allocDList() {
    return (DList)malloc(sizeof(Xnode));
}
DLL allocDLL(){
    DLL DL;
    DL.head=allocDList();
    DL.tail=allocDList();
    DL.head->next = DL.tail;
    DL.tail->prev = DL.head;
    return DL;
}
void FreeDList(DList* p) {
    free(*p);
    *p = NULL;
}
void initDLL(DLL* L) {
    L->head = NULL;
    L->tail = NULL;
}
void initDList(DLL* L) {
  L=NULL;
}
bool EmptyDLL(DLL L) {
    return (L.head == NULL && L.tail == NULL);
}
bool EmptyDList(DList L) {
    return (L==NULL);
}
int getValDList(DList p) {
    return p->val;
}
void setValDList(DList p, int val) {
    p->val = val;
}
DList getNextDList(DList p) {
    return p->next;
}
DList getPrevDList(DList p) {
    return p->prev;
}
void setNextDList(DList p, DList q) {
    p->next = q;
}
void setPrevDList(DList p, DList q) {
    p->prev = q;
}