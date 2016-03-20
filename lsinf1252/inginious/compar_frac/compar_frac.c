#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int numerateur;
  int denominateur;
} fraction_t;

/*
 * Compare 2 fraction_t
 * Précondition : - les 2 paramètres sont des pointeurs sur des fraction_t valides (Non NULL donc)
 *                - aucun dénominateur ne vaut 0
 * Renvoie : < 0 si la première fraction est plus petite que la seconde
 *           > 0 si la première est plus grande
 *           0 si elles ont la même valeur
 */
int fraction_compare(const void *a, const void *b){
  if( a == NULL || b == NULL)
    exit(EXIT_FAILURE);

  fraction_t* frac1 = (fraction_t*)a;
  fraction_t* frac2 = (fraction_t*)b;

  if(frac1->denominateur == 0 || frac2->denominateur == 0)
    exit(EXIT_FAILURE);

  double val_frac1 = ((double)(frac1->numerateur)) / ((double)(frac1->denominateur));
  double val_frac2 = ((double)(frac2->numerateur)) / ((double)(frac2->denominateur));

  if(val_frac1 > val_frac2)
    return 1;
  else if (val_frac1 < val_frac2)
    return -1;
  else
    return 0;
}

/*
 * Trie un tableau de fraction_t par ordre croissant
 * Params : - tab est un pointeur vers le permier élément d'un tableau de fraction_t
 *          - len indique le nombre d'éléments contenus dans le tableau
 * Précondition : - tab n'est pas NULL et pointe vers un tableau valide
 *                - len <= à la longueur réelle du tableau
 * Postcondition : tab a été trié par qsort dans l'ordre croissant sur la longueur indiquée
 *                  par len.
 */
void fraction_sort(fraction_t * tab, size_t len){
  if (tab == NULL)
    exit(EXIT_FAILURE);
  if(len <= 0)
    exit(EXIT_FAILURE);

  qsort((void*)tab, len, sizeof(fraction_t), *fraction_compare);
}

/*
 * Trie un tableau de fraction_t par ordre croissant en ignorant les 3 premiers et
 *   derniers éléments (en laissent ceux là dans l'ordre où ils se trouvent).
 * Params : - tab est un pointeur vers le permier élément d'un tableau de fraction_t
 *          - len indique le nombre d'éléments contenus dans le tableau
 * Précondition : - tab n'est pas NULL et pointe vers un tableau valide
 *                - len <= à la longueur réelle du tableau
 *                - len vaut au moins 6 (3+3)
 * Postcondition : tab a été trié par qsort dans l'ordre croissant sur la longueur indiquée
 *                  par len en ignorant les 3 premiers et derniers éléments.
 */
void fraction_sortIgnore3fl(fraction_t * tab, size_t len){
  if(tab == NULL)
    exit(EXIT_FAILURE);
  if(len < 6)
    exit(EXIT_FAILURE);

  qsort((void*)(tab+3), len-6, sizeof(fraction_t), *fraction_compare);

}
