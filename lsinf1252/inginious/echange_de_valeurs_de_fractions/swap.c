/* Implementation de la fonction swap qui permet d intervertir le resultat de
 * deux fractions
 */
#include<stdio.h>

struct fract_t{
  int num;
  int denum;
};

/*
 *@pre - prend 2 pointeurs qui pointent vers la fraction a et b
 *@post - interverti les valeurs en utilisant une fraction temporaire
 */
void swap(struct fract_t *ptra, struct fract_t *ptrb){
  struct fract_t temp;
  temp.num = ptra -> num;
  temp.denum = ptra -> denum;
  ptra -> num = ptrb -> num;
  ptra -> denum = ptrb -> denum;
  ptrb -> num = temp.num;
  ptrb -> denum = temp.denum;
}

//test de la fonction avec deux fractions a = 6/4 et b=9/3
void main (){
  struct fract_t a = {6,4};
  struct fract_t b = {9,3};
  struct fract_t *ptrToa;
  struct fract_t *ptrTob;
  ptrToa = &a;
  ptrTob = &b;
  printf("Avant swap : num et den de a = %d et %d, num et den de b = %d et %d\n",a.num,a.denum,b.num,b.denum);
  swap(ptrToa,ptrTob);
  printf("Après swap : num et den de a = %d et %d, num et den de b = %d et %d\n",a.num,a.denum,b.num,b.denum);
}
