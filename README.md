# CRO
## Compilation de C avec gcc
```bash
ggc -c nomdufichier.c
```
Cette commande s'occupera de créer un fichier objet .o (en créant entre temps un fichier assembler .s), ce fichier contient le code du .c avec les librairies .h ajouter par les `#include` dans le .c
Ensuite, l'execution du .o ce fait toujours avec gcc
```bash
gcc nomdufichier.o -o nomdelexecutable
```
Cette commande transfert le fichier object .o en fichier executable .c.
*Remarque on peut faire les 2 etapes directement avec*
```bash
gcc nomdufichier.c -O nomdelexecutable
```


## Quelques caractéristique de C
C est un langage impératif, c'est-à-dire qu'il execute que des actions sur des données (contraire au langage objet ou equationnel). Il est typé et permet d'agir directement sur les cases mémoire à l'aide des pointeurs

### Probleme de C
* Peu de verification du compilateur --> beaucoup de probleme d'inattention
* Pas de modularité

## Rapport mémoire
Les pointeurs détiennent l'adresse de la case mémoire d'une variable. La variable, elle, ne renvoie que la valeur qu'il y a dans cette case mémoire.
notation : 
```C
int a = 2 ; // Variable a qui contient 2
int *p = &a; // Pointeur p qui contient l'adresse de a
printf("Variable : %d, adresse : %p \n", a, &a);
printf("Pointeur : %p, valeur pointé : %d \n", p, *p );
printf("Subptilité : %p", &*p );
```
```
>Variable : 2, adresse : 0x7ffee26f6b38
>Pointeur : 0x7ffee26f6b38, valeur pointé : 2
>Subtilité : 0x7ffee26f6b38
```
## Notions de base
### entrée et sortie

### Les fonctions et les libraries
Une fonction doit être déclarer avant d'être initialisée (écrite) par la commande :
```C
int fonction(int a); // Declaration
```
Les déclarations sont faites dans les libraries .h (question d'organisation, en soit la déclaration doit être avant l'initialisation)
