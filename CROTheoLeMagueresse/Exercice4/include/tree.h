#ifndef _tree_h_
#define _tree_h_

TREE newTree(int value, TREE left_son, TREE right_son);
void printTree(TREE tree);
TREE insertionABR(TREE root, int value);
int isABR(TREE tree);

#endif
