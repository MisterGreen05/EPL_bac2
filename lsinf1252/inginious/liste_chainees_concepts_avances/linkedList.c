#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int value;
  struct node *next;
}node;

void reverse(node **list){
  node* prev = NULL;
  node* nxt;
  node* current = *list;

  while(current != NULL){
    nxt = current->next;
    current->next = prev;
    prev = current;
    current = nxt;
  }
  *list = prev;
}

node* append (node* a, node*b){
  node* ptr;
  if(a == NULL)
    return b;
  if(b == NULL)
    return a;
  ptr = a;
  while(ptr->next != NULL){
    ptr=ptr->next;
  }
  ptr->next = b;
  return a;
}

void split(node *list, node **first_half, node **second_half){
  if (!list) return;

  node *last_node_of_first_half; //dernier noeud de la premiere moitie
  node *a = list;
  node *b = list;

while (a != NULL) {
    last_node_of_first_half = b; /*on fait avancer b de un noeud et last node est
                                   le dernier noeud de first_half*/
    b = b->next;
    a = (a->next) ? a->next->next : NULL; /*on fait avancer a de deux*/
  }

  last_node_of_first_half->next = NULL; /*dernier noeud de first_half = NULL*/
  *first_half = list;
  *second_half = b;
}
