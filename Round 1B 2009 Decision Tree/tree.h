#ifndef TREE_H
#define TREE_H
#define LINESIZE 80

struct node{
    struct node* right;
    struct node* left;
    double prob;
    char name[11];
    char data[LINESIZE+1];
};


char *get_tree(int lines);
void create_tree(struct node *parent);
char *read_data();
void traverse_tree(struct node *tree);
void split_data(struct node *parent,char *data);
int has_feature(char *feature,char *cases);

#endif
