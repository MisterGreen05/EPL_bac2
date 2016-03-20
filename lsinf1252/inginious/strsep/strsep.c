#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#ifndef MY_STRSEP_H
#define MY_STRSEP_H
#endif /* MY_STRSEP_H */

 /** Fichier d'énoncé à ne pas modifier ! **/

 /** Vous devez ré-implémenter la fonction strsep()
 en considérant que delim est un pointeur vers un seul caractère **/

 /** MAN STRSEP()
 DESCRIPTION

 Si *stringp est NULL, la fonction strsep() renvoie NULL et ne fait rien d'autre.
 Sinon, cette fonction prend le premier élément lexical (token) dans la chaîne
 stringp où les éléments sont séparés par les symboles contenus dans delim. Le
 mot renvoyé est terminé par un caractère nul `\0' (en écrasant le séparateur)
 et *stringp est mis à jour pour pointer après le mot. Dans le cas où aucun
 séparateur n'est trouvé, l'élément extrait est constitué de toute la chaîne
 *stringp, et *stringp vaut NULL.

 VALEUR RENVOYÉE

 La fonction strsep() renvoie un pointeur sur l'élément lexical extrait,
 c'est-à-dire la valeur originelle de *stringp. stringp. La fonction strsep() a
 été introduite en remplacement de strtok(), qui ne peut pas traiter les champs
 vides. Néanmoins strtok() est conforme au C ANSI et est donc plus portable.
 **/

 /* Exemple pour mieux comprendre : 1ere maniere de faire :
  * char* buffer = "A B C"
  * char** stringp = &buffer
  * stringp = pointe vers le 1er caractère de buffer et buffer pointe vers un
  * tableau de caract
  * 2eme maniere : char tab[] = "A B C" et puis que char* buffer = &tab; et donc
  * char** stringp = &buffer
  */

char* my_strsep(char ** stringp, const char * delim){
  if (stringp == NULL || *stringp == NULL)
    return NULL;

char *current = *stringp;
char *start = *stringp;

while (*current != '\0') {

    if (delim != NULL && *current == *delim) {
       *stringp = current + 1;
       *current = '\0';

        return start;

    }

    current = current + 1;
}

*stringp = NULL;
return start;
}

int main(void){
  char tab[] = "Daamn daniel you are beautiful";
  char* buffer = &tab[0];
  const char delim[] = " ";
  char** stringp = &buffer;
  char* test = my_strsep(stringp, delim);

  printf("%s\n", buffer); //affiche : daniel you are beautiful
  printf("%s\n", test); // affiche : Daamn
  printf("%s\n", *stringp); //affiche : daniel you are beautiful

}
