#ifndef Doubly_INCLUDED
#define Doubly_INCLUDED
typedef struct Xnode {
    int val;
    struct Xnode* next;
    struct Xnode* prev;
} Xnode;
typedef Xnode* DList;
typedef struct DLL {
    DList head;
    DList tail;
}DLL;
DLL allocDLL();
DList allocDList();
void FreeDList(DList *P);
void initDLL(DLL *L);
bool EmptyDLL(DLL L);
int getValDList(DList P);
void setValDList(DList P, int v);
DList getNextDList(DList P);
void setNextDList(DList P, DList Q);
DList getPrevDList(DList P);
void setPrevDList(DList P, DList Q);
bool EmptyDList(DList L);
#endif // DLL_H_INCLUDED