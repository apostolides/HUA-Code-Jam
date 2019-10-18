#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "tree.h"

extern char *textree;
extern char A_animal_cases[LINESIZE+1];
extern double prob;

char *get_tree(int lines){    
    char tmp[LINESIZE+1];
    int i;
    int buff_size = sizeof(char)*(LINESIZE+1)*lines;
    char *tmp_tree = (char*)malloc(buff_size);
    assert(tmp_tree);

    for(i=0;i<lines;i++){
        fgets(tmp,LINESIZE,stdin);
        strcat(tmp_tree,tmp);
    }
    
    char *tree = (char*)malloc(buff_size);
    assert(tree);

    int j=0;
    for(i=0;i<buff_size;i++){
        if(tmp_tree[i]!='\n' && tmp_tree[i]!=' '){
            tree[j] = tmp_tree[i];
            j++;
        }
    }
    

    char *final_tree = (char*)malloc(sizeof(char)*j);
    assert(final_tree);

    strcpy(final_tree,tree);
    final_tree[j] = '\0';

    return final_tree;
}

void create_tree(struct node *parent){
    parent->left=NULL;
    parent->right=NULL;
    while(*textree==')'){
        textree++;
        if(*textree=='\0'){
            return;
        }
    }

    char *data = read_data(++textree);
    split_data(parent,data);
    
    if(*textree=='('){
        struct node *left_child = (struct node*)malloc(sizeof(struct node));
        assert(left_child);
        left_child->left = NULL;
        left_child->right = NULL;
        
        parent->left = left_child;
        create_tree(parent->left);
    }
    else if(*textree==')'){
        textree++;
        return;
    }

    struct node *right_child = (struct node*)malloc(sizeof(struct node));
    assert(right_child);
    right_child->left = NULL;
    right_child->right = NULL;
    
    parent->right = right_child;
    create_tree(right_child);

}

char *read_data(){
    
    char *data = (char*)malloc(sizeof(char)*81);
    assert(data);
    int i = 0;
    
    while(*textree!='(' && *textree!=')'){
        data[i++]=*textree;
        textree++;
    }
    data[i] = '\0';

    return data;
}

void traverse_tree(struct node *tree){
    
    prob*=tree->prob;
 
    if(tree->left==NULL && tree->right==NULL){
        printf("%0.7lf\n",prob);
        return;
    }
    else if(has_feature(tree->name,A_animal_cases)){
        traverse_tree(tree->left);
    }
    else{
        traverse_tree(tree->right);
    }
    

}

void split_data(struct node *parent,char *data){
    int i = 0;
    char tmp;
    while(isdigit(data[i]) || data[i]=='.'){
        i++;
    }
    tmp=data[i];
    data[i]='\0';
    parent->prob=atof(data);
    data[i]=tmp;
    strcpy(parent->name,data+i);
}

int has_feature(char *feature,char *cases){
    int offset = 0;
    const char delim[]=" \n";
    char *token;
    
    int i = 0;
    while(cases[i]!='\0'){
        i++;
    }
    char *tmp_cases=(char*)malloc(sizeof(char)*(i+1));
    strcpy(tmp_cases,cases);

    while(!isdigit(tmp_cases[offset])){
        offset++;
    }

    offset+=2;

    token = strtok(tmp_cases+offset,delim);

    while(token!=NULL){
        if(!strcmp(token,feature)){
            return 1;
        }
        token = strtok(NULL,delim);
    }
    
    return 0;
}

