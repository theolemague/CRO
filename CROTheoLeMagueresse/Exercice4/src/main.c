#include <stdio.h>
#include <stdlib.h>
#include "type_tree.h"
#include "tree.h"

#define N 5

int main(int argc, char** argv) {
    TREE t1, t2, t3, t4, mainTree, falseTree;
    t1 = newTree(1, NULL, NULL);
    t2 = newTree(3, NULL, NULL);
    t3 = newTree(2, t1, t2);
    t4 = newTree(5, NULL, NULL);
    mainTree = newTree(4, t3, t4);
    falseTree = newTree(4, t4, t3);
    // printTree(mainTree);
    // mainTree = insertionABR(mainTree, 9);
    // mainTree = insertionABR(mainTree, 2);
    // mainTree = insertionABR(mainTree, 6);
    // mainTree = insertionABR(mainTree, 5);
    printTree(mainTree);
    fprintf(stdout, "L'arbre est un ABR : %d\n",isABR(mainTree));
    fprintf(stdout, "L'arbre est un ABR : %d\n",isABR(falseTree));
    return(0);
}