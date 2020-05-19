#include <stdio.h>
#include <stdlib.h>
#include "type_tree.h"
#include "tree.h"

TREE newTree(int value, TREE left_son, TREE right_son){
  TREE newTree;
  newTree = (TREE) malloc(sizeof(NODE));
  newTree->value = value;
  newTree->left = left_son;
  newTree->right = right_son;
  return newTree;
}

void printTree(TREE tree){
  fprintf(stdout, " %d \n", tree->value);
  
  if(tree==NULL) {
    return;
  }
  if(tree->left!=NULL) {
    printTree(tree->left);
  }
  
  if(tree->right!=NULL) {
    printTree(tree->right);
  }
}