#ifndef Single_INCLUDED
#define Single_INCLUDED
typedef struct Snode{
  int val ;
  struct Snode *next ;
}Snode;
typedef Snode* List ;//hata dork manich 3arf 3lah fel header :D

List alloc();
void Free(List* p);
void init(List* p);
bool Empty(List p);
int getval(List p);
void setval(List p, int v);
List getnext(List p);
void setNext(List p, List q);
#endif // LL_H_INCLUDED