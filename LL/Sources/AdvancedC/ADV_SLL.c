#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../Headers/ToolsH/Single.h"
#include "../../Headers/AdvancedH/ADV_SLL.h"
/*-------------- ADVANCED FUNCTIONS --------------*/
/*--------------------- EXO 1 ----------------------*/
// L P is a List
// K is Position of Node
// v is a value 
// n is nomber of Nodes
// Lp is a List Positife has value in there Nodes can be created from CRLLP
// Ln is a List Negative has value in there Nodes can be created from CRLLN
// L1 is a Random List to Fus it
// L2 is a Random List to Fus it
void printADVLL(char name[], List L){
  List P = L;
  printf("Linked list : %s \n", name);
  printLL(L);
}
void printLL(List L){
  List P = L;
  while (!Empty(P)){
    printf("[%d]-->", getval(P));
    P = getnext(P);
    }
  printf("[NULL]\n");
}
void AddLastLL(List *L, int v){
List P , Q;
P = alloc();
setval(P,v);
setNext(P,NULL);
if(*L!=NULL){
  Q = *L;
  while(getnext(Q)!=NULL){
    Q = getnext(Q);
    }
  setNext(Q,P);
  }
else{
  *L = P;
  }
}
List CreateRanLLPos(int N){
  List L;
  init(&L);
  for(int k=1;k<N+1;k++){
    AddLastLL(&L, k);
    }
  return L;
}
List CreateRanLLNig(int N){
  List L;
  init(&L);
  for(int k=1;k<N+1;k++){
    AddLastLL(&L, -k);
    }
  return L;
}
List CreateLL(int N){
int v;
List L;
init(&L);
for(int k=1;k<=N;k++){
  scanf("%d",&v);
  AddLastLL(&L, v);
  }
return L;
}
int SizeLL(List L){
int N=0;
List P=L;
while(!Empty(L)){
  N++;
  P=getnext(P);
  }
return N;
}
List FindLL(List L, int v){
    List P = L;
    while((!Empty(P)) && (getval(P) != v))
        P = getnext(P);
    return P;
}
List FindPosLL(List L, int k){
List P;
if(k>0){
  P=L;
  while(k>1 && !Empty(P)){
    k--;
    P = getnext(P);
    }
  return P;
  }
else{
  return NULL;
  }
}
void AddFirstLL(List *L, int v){
List P;
P = alloc();
setval(P,v);
setNext(P,*L);
*L = P;
}
List CreateLL_Reverse(int N){
int v;
List L;
init(&L);
for(int i=0;i<N;i++){
  scanf("%d",&v);
  AddFirstLL(&L, v);
  }
return L;
}
void ReverseLL (List *L){
List P, Q;
P=NULL;
while (!Empty(*L)){
  Q = *L;
  *L=getnext(*L);
  setNext(Q, P);
  P= Q;
  }
*L=P;
}
void RemoveLL(List *L, int v){
List Q= NULL;
List P = *L;
while((!Empty(P))&&(getval(P)!=v)){
  Q = P;
  P = getnext(P);
  }
if(P!=NULL){
  if(Empty(Q)){
    *L = getnext(P);
    }
  else{
    setNext(Q,getnext(P));
    }
  Free(&P);
  }
}
void RemoveALL(List *L, int v){
List Q= NULL;
List P = *L;
while(!Empty(P)){
  if (getval(P)!=v){
    Q = P; P = getnext(P);
    }
  else{
    if(Empty(Q)){
      *L=getnext(P);
      Free(&P);
      P = *L;
    }
    else{
      setNext(Q, getnext(P));
      Free(&P);
      P=getnext(Q);
      }
    }
  }
}
void RemovePosLL(List *L, int k, bool *possible){
  List P, Q;
  *possible = false;
  if (k>0){
    if (k==1){
      P=*L;
      *L = getnext(*L);
      Free(&P);
      *possible = true;}
    else{
      Q=FindPosLL(*L, k-1);
      if(!Empty(Q) && !Empty(getnext(Q))){
        P = getnext(Q);
        setNext (Q, getnext(P)) ;
        Free(&P);
        *possible = true;
      }
    }
  }
}
void CleanLL(List *L){
  List P;
  while (!Empty(*L)){
    P=*L;
    *L =getnext(*L);
    Free(&P);
  }
}
List FirstPosLL(List L, int k){
  List le_reture=alloc();
  setval(le_reture, getval(L));
  while(k>1){
    k--;
    L=getnext(L);//هاذي ماثرتش على الليست كامل
    AddLastLL(&le_reture, getval(L));
    }
  return le_reture;
}
//hadi dertha bah ndir AddInLL
List SecondPosLL(List L, int k){
  return FindPosLL(L, k+1);//هاذي ثانيك ماثرتش
}
//hadi dertha bah ndir AddInLL
void AddPosLL(List *L, int v, int k){
  List Part1=FirstPosLL(*L, k-1);
  AddLastLL(&Part1, v);
  *L=SecondPosLL(*L, k-1);//هنا مانيش عارف علاه مصراش مشكل
  List P=*L;//ملاحظة كي تجي تحب تستخدم الليست الاصلي فالباساج فاريابل 
  // اخدم فاريابل وخداخ احسن خاطر يصراو مشاكل
  while(!Empty(P)){
    AddLastLL(&Part1, getval(P));
    P=getnext(P);
    }
  *L=Part1;
}
//hadi mliha bzf
List Fusion2LL_WAN(List L, List P){
  List retur;
  init(&retur);
  while(!Empty(L) && !Empty(P)){ //parcourir les deux listes
    if(getval(L) <= getval(P)){
      AddLastLL(&retur, getval(L));
      L = getnext(L);
    }
    else{
      AddLastLL(&retur, getval(P));
      P = getnext(P);
    }
  }
  while(!Empty(L)){ // parcourir la liste L si elle n’est pas vide
    AddLastLL(&retur, getval(L));
    L = getnext(L);
  }
  while(!Empty(P)){ // parcourir la liste P si elle n’est pas vide
    AddLastLL(&retur, getval(P));
    P = getnext(P);
  }
  return retur;
}
List Fusion2LL_WOAN(List L, List P) {
    List retur, temp1, temp2, temp1_copy, temp2_copy;
    init(&retur);
    List Q = NULL;
    temp1 = L;
    temp2 = P;
    temp1_copy = NULL;
    temp2_copy = NULL;
    while (!Empty(temp1)) {
        List newNode = alloc();
        setval(newNode, getval(temp1));
        setNext(newNode, temp1_copy);
        temp1_copy = newNode;
        temp1 = getnext(temp1);
    }
    while (!Empty(temp2)) {
        List newNode = alloc();
        setval(newNode, getval(temp2));
        setNext(newNode, temp2_copy);
        temp2_copy = newNode;
        temp2 = getnext(temp2);
    }
    ReverseLL(&temp1_copy);
    ReverseLL(&temp2_copy);
    while (!Empty(temp1_copy) && !Empty(temp2_copy)) {
        if (getval(temp1_copy) <= getval(temp2_copy)) {
            if (Empty(retur)) {
                retur = temp1_copy;
            } else {
                setNext(Q, temp1_copy);
            }
            Q = temp1_copy;
            temp1_copy = getnext(temp1_copy);
        } else {
            if (Empty(retur)) {
                retur = temp2_copy;
            } else {
                setNext(Q, temp2_copy);
            }
            Q = temp2_copy;
            temp2_copy = getnext(temp2_copy);
        }
    }
    if (!Empty(temp1_copy)) {
        if (Empty(retur)) {
            retur = temp1_copy;
        } else {
            setNext(Q, temp1_copy);
        }
    }
    if (!Empty(temp2_copy)) {
        if (Empty(retur)) {
            retur = temp2_copy;
        } else {
            setNext(Q, temp2_copy);
        }
    }
    return retur;
}
//Credit CHAT GPT
void EclatementLL_WAN(List L,List *Lp,List *Ln){
  init(Lp);//tf why init
  init(Ln);//tf why init
  while(!Empty(L)){
    if(getval(L)<0){
      AddLastLL(Ln, getval(L));//negative
    }
    else{
      AddLastLL(Lp, getval(L));//positive
    }
    L=getnext(L);
  }
}
void EclatementLL_WOAN(List *L, List *Lp, List *Ln){
  init(Lp);
  init(Ln);
  List Tp=NULL;
  List Tn=NULL;
  List temp = *L;
  while (!Empty(temp)){
    if (getval(temp) < 0){
      if (Empty(*Ln)){
        *Ln = temp;
      }
      else{
        setNext(Tn, temp);
      }
      Tn = temp;
    }
    else{
      if (Empty(*Lp)){
        *Lp = temp;
      }
      else{
        setNext(Tp, temp);
      }
      Tp = temp;
    }
    temp = getnext(temp);
  }
  if (!Empty(Tp)){
    setNext(Tp, NULL);
  }
  if (!Empty(Tn)){
    setNext(Tn, NULL);
  }
}
/*-------------- help functions --------------*/
void HELP_ADVSLLh(){
  printf("\n hello there \n");
  printf("\t this library countain a lots of Function ");
  printf("calling it calls with  \"LL.h\" Lib");
  printf("\n ~~~~ here is the functions that you can use :~~~~\n");
  printf("\n void printLL(List );");
  printf("\n void ReverseLL (List *);");
  printf("\n void removeLL(List *, int );");
  printf("\n void removeALL(List *, int );");
  printf("\n void removePosLL(List *, int , bool *);");
  printf("\n void CleanLL (List *);");
  printf("\n void AddLastLL(List *, int );");
  printf("\n void AddFirstLL(List *, int );");
  printf("\n int sitzeLL (List );");
  printf("\n List CreateLL (int );");
  printf("\n List FindLL (List , int );");
  printf("\n List FindPosLL (List ,int );");
  printf("\n List CreateLL_reverse(int );");
  printf("\n void printADVLL(char '', List );");
  printf("\n List FirstPartLL(List , int );");
  printf("\n List SecondPartLL(List , int );");
  printf("\n void AddInLL(List *, int , int );");
  printf("\n List CreateRanLL(int );\n");
  printf("\n HELP_FUNCTION(); OPTION to show more (explaining)\n");
  }// hadi dertha bah n3wnk wach kayn
void HELP_printADVLL(){
  printf("\n hadi tprinti list 'lazm matkonch far8a brk w zid b ismha sema tshl 3lik analyse'\n");
  printf("how to use it :\n");
  printf("printADVLL(\"name_of_lise\",L);");
}
void HELP_printLL(){
  printf("\n hadi tprinti list 'lazm matkonch far8a brk'\n");
}
void HELP_AddLastLL(){
printf("\nhadi dir add node lel list t3k'\n");
}
void HELP_CreateLL(){
printf("\nhadi treturni nodes lel list 'bsah nta tscani kol val f node'");
printf("\ntreturni List 3la hsab number of nodes 'Work abbreviation'(fiha SCANF)\n");
}
void HELP_sitzeLL(){
  printf("\nhadi tmdlk  la taile t3 List\n");
}
void HELP_FindLL(){
  printf("\n/hadi tmdlk la List m posssition li fiha val\n");
}
void HELP_FindPosLL(){
  printf("\nhadi tmdlk la list m number t3 node li mdito\n");
}
void HELP_AddFirstLL(){
  printf("\n  hadi dirlk add node with val bsah ml 9odam machi mlor");
  printf("\n kch8ol contrar t3 AddLastLL\n");
}
void HELP_CreateRanLLPos(){
  printf("\nhadi treturni nodes lel list 'bsah nta mattscani kol val f node'");
  printf("\ntreturni List 3la hsab number of nodes 'Work abbreviation'(Bla SCANF)\n");
  printf("bsa7 les val tw3ha ykono Positive\n");
}
void HELP_CreateRanLLNig(){
  printf("\nhadi treturni nodes lel list 'bsah nta mattscani kol val f node'");
  printf("\ntreturni List 3la hsab number of nodes 'Work abbreviation'(Bla SCANF)\n");
  printf("bsa7 les val tw3ha ykono Nigative\n");
}
void HELP_CreateLL_reverse(){
  printf("\n//hadi kch8ol CreateLL bsah tkhdml bel AddFirstLL");
  printf("\n 'm3ntha y93od y ajouti nodes ml 9odam machi mlor kima AddLastLL'\n");
}
void HELP_ReverseLL(){
  printf("\nT9lb les valuer t3 node\n");
}
void HELP_RemoveLL(){
  printf("\n tnahilk value f List tnahilk lwla brk\n");
}
void HELP_RemoveALL(){
  printf("\n tna7ilk kaml les nod li fihom value hadik\n");
}
void HELP_RemovePosLL(){
  printf("\nthis MF ynahilk Node li fih value li maditholo w ykon kayn f list\n");
  printf("lazm thot fih bool t3 possible y9dr ykon true wla false\n");
  printf("mhm lokan yl9A node ywli true\n ");
  printf("TBH bool chwiya useless\n");
}
void HELP_CleanLL(){
  printf("\nthis MF yrj3lk List ta3K tpointé 3la null w khdma t3k kaml troh\n");
}
void HELP_AddPosLL(){
  printf("\nhadi kch8ol dirlk add f nos t3ha lazm List &, int v, int p\n");
}
void HELP_SecondPosLL(){
  printf("(List, int node) Imagine having A :\n");
  List L=CreateRanLLPos(6);
  printADVLL("L",L);
  printf("let return after 3rd node\n");
  printADVLL("SecondPartLL_function_return", SecondPosLL(L,3));
}
void HELP_FirstPosLL(){
  printf("(List, int node) Imagine having A :\n");
  List L=CreateRanLLPos(6);
  printADVLL("L",L);
  printf("Let return first 3rd node\n");
  printADVLL("FirstPartLL_function_return", FirstPosLL(L,3));
}
void HELP_Fusion2LL_WAN(){
  printf("\nhadi tdirlk fusion l 2 les list");
  printf("\n ma3Ntha tjm3lk w b tartib 3La hsab val t3 node");
  printf("\n w rah tjm3 bel repitetion");
  printf("\n with allocat a new node \n");
}
void HELP_Fusion2LL_WOAN(){
  printf("\nhadi tdirlk fusion l 2 les list");
  printf("\n ma3Ntha tjm3lk w b tartib 3La hsab val t3 node");
  printf("\n w rah tjm3 bel repitetion");
  printf("\n with out allocat a new node");
  printf("\nGPT\n");}
void HELP_EclatementLL_WAN(){
  printf("\n this MF ykhlik thot positife f zwja w negative f thaltha ");
  printf("\n same sort ");
  printf("\n with allocat a new node \n");
}
void HELP_EclatementLL_WOAN(){
  printf("\n this MF ykhlik thot positife f zwja w negative f thaltha");
  printf("\n same sort ");
  printf("\n with out allocat a new node \n");
}