/* Implementation des fonctions length, count, push, pop et free_list
 */

#include<stdio.h>
#include<stdlib.h>

// structure d une liste chainee
typedef struct node {
  int value;
  struct node *next;
}node;

/* @pre - prend en argument le pointeur qui pointe a l adr de latete de chaine
 * @post - renvoie la longueur de la liste
 */
size_t length(node *list){
  if(list==NULL)
    return 0;
  else
    return length(list->next)+1;
}

/* @pre - prend en argument le pointeur qui pointe a l adr de latete de chaine
 *        et la valeur avec laquelle on veut compte le nombre d occurence
 * @post - renvoie le nombre d'occurence de value dans la liste
 */
size_t count(node *list, int value){
  int i=0;
  if (list==NULL) {
    return 0;
  }
  else {
    node *current;
    current = list;
    while (current != NULL) {
        if(current->value == value){
            i++;
        }
        current = current->next;
    }
  }
  return i;
}

/* @pre - prend en argument un pointeur vers une liste et la val a ajouter
 * @post - renvoie 0 si tout se passe bien, -1 si ca se passe mal
 */
int push(node **list, int value){
  node *new = malloc(sizeof(node));

  if (new == NULL) {
    return -1;
  }

  else {
  new->value = value;
  new->next = *list;
  *list = new;
  return 0;
  }
}

/* @pre - prend en argument un pointeur vers une liste
 * @post - renvoie la valeur qui a ete supp, qui est la tete de la chaine
 */
int pop(node **list){
  int val;
  node *temp;
  val = (*list)->value;
  temp = *list;
  *list=(*list)->next;
  free(temp);
  return val;
}

/* @pre - prend en argument un pointeur vers une liste a supp de la memoire
 * @post - renvoie rien, elle libere juste la memoire
 */
void free_list(node *list){
  node *temp;
while(list != NULL){
  temp=list;
  list = list->next;
  free(temp);
}
}

// tests possible avec la main et la liste {1,2,3}
void main(){
  node *tail = malloc(sizeof(node));
  tail->value = 3;
  tail->next = NULL;

  node *body = malloc(sizeof(node));
  body->value = 2;
  body->next = tail;

  node *head = malloc(sizeof(node));
  head->value = 1;
  head->next = body;
  //exemple d'utilisation de pop
  int result = pop(&head);
  printf("%d\n", result);
}
