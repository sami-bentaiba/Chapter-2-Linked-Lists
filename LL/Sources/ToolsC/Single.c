#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../Headers/ToolsH/Single.h"
/*******TOOLS of LL******/
//functions
List alloc(){
    return (List)malloc(sizeof(Snode));//malloc is a function that already exisct in C BIB
  }//hadi tkhdmlk espace f memeoire bah twli thot fih node lel List
void Free(List* p){
    free(*p);
    *p = NULL;
  }//hadi tfr8lk kaml value of List
void init(List* p){
    *p = NULL;
  }//hadi twjdlk node li ypointe 3lih p bah tkhdm bih'setval(P,0)'
bool Empty(List p){
    return (p == NULL);
  }//hadi tchoflk ida List rahi empty
int getval(List p){
    return p->val;
  }//hadi treturni val li kayn f node
void setval(List p, int v){
    p->val = v;
  }//hadi thotlk val fel node li ypointé 3lih P 
//psq lokan derna next rah tdirlk val f hadak next machi f the first
List getnext(List p){
    return p->next;
  }//hadi treturni next 'ki tchof f structure tfhm bali node jay haka [val|next]-->'
//el mohim chft next hada ypointé ima 3la another node ima 3la NULL mohim hadi biha namcho fel List hiya 80% m khdma
void setNext(List p, List q){
    p->next = q;
  }//hadi tls9lk list p f list q twali haka [p]-->[q]