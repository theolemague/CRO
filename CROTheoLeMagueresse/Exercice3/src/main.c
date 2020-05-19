#include <stdio.h>
#include <stdlib.h>
#include "type_tree.h"
#include "tree.h"

#define N 5

int main(int argc, char** argv) {
    TREE t1, t2, t3, t4, mainTree;
    t1 = newTree(1, NULL, NULL);
    t2 = newTree(2, NULL, NULL);
    t3 = newTree(3, t1, t2);
    t4 = newTree(4, NULL, NULL);
    mainTree = newTree(5, t3, t4);
    printTree(mainTree);
    return(0);
}