#ifndef _type_tree_h_
#define _type_tree_h_

struct model_node {
    int value;
    struct model_node *left ;
    struct model_node *right ;
};

typedef struct model_node NODE;

typedef NODE *TREE;

#endif