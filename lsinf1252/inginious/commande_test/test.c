/* Implementation du programme test de linux
 * Permet de gerer uniquement les tests arithmetiques
 * Autheur : Singh Aman 
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* @PRE - Prend deux arguments en entier a comparer via l'operation op qui est
 * un string de la forme -eq pour l egalite par exemple
 * @POST - renvoie true
 */
int test (int arg1, int arg2, char* op){
  if (strcmp("-eq", op) == 0){
    if(arg1 == arg2)
      return 0;
    else
      return 1;
  }
  else if (strcmp("-ne", op) == 0){
    if(arg1 != arg2)
      return 0;
    else
      return 1;
  }
  else if(strcmp("-lt", op) == 0){
    if(arg1 < arg2)
      return 0;
    else
      return 1;
  }
  else if(strcmp("-le", op) == 0){
    if(arg1 <= arg2)
      return 0;
    else
      return 1;
  }
  else if(strcmp("-gt", op) == 0){
    if(arg1 > arg2)
      return 0;
    else
      return 1;
  }
  else if(strcmp("-ge", op) == 0){
    if(arg1 >= arg2)
      return 0;
    else
      return 1;
  }
  else{
    printf("%s n'est pas une operation supporte par le programme\n", op);
    return EXIT_FAILURE;
  }
}

/* @PRE - ./test arg1 -op arg2 dans un terminal
 * @POST - renvoie 0 si true, renvoie 1 s c'est false
 */
int main (int argc, char **argv){
  if (argc==4)
    return test(atoi(argv[1]), atoi(argv[3]), argv[2]);
  else
    return EXIT_FAILURE;
}
