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
  
  if(tree==NULL) return;
  if(tree->left!=NULL) printTree(tree->left);
  fprintf(stdout, " %d \n", tree->value);
  if(tree->right!=NULL) printTree(tree->right);
  
}


TREE insertionABR(TREE root, int value){

  if (root == NULL) return(newTree(value, NULL, NULL));
  
  else if (root->value >= value) return(newTree(root->value, insertionABR(root->left, value), root->right));  
  
  else return(newTree(root->value, root->left, insertionABR(root->right, value)));
}

int isABR(TREE tree){
  if (tree==NULL) return(1);
  if ((tree->left != NULL && tree->left->value > tree->value) || (tree->right != NULL && tree->right->value < tree->value)) return(0);  
  if (!isABR(tree->left) || !isABR(tree->right)) return(0);  
  else return(1);
}
