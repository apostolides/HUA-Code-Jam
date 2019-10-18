#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

char *textree;
char A_animal_cases[LINESIZE+1];
double prob;

int main(int argc,char **argv){

    char N_test_cases[LINESIZE+1];
    fgets(N_test_cases,LINESIZE,stdin);
    int N = atoi(N_test_cases),i,j;

    char L_lines[LINESIZE+1];
    int L;


    int animal_cases;

    struct node tree;

    for(i=0;i<N;i++){

        fgets(L_lines,LINESIZE,stdin);
        L = atoi(L_lines);

        textree = get_tree(L);
        create_tree(&tree);


        fgets(A_animal_cases,LINESIZE,stdin);

        animal_cases = atoi(A_animal_cases);

        printf("Case #%d:\n",i+1);

        for(j=0;j<animal_cases;j++){
            fgets(A_animal_cases,LINESIZE,stdin);
            prob = 1.0;
            traverse_tree(&tree);
        }

    }

    return 0;
}
