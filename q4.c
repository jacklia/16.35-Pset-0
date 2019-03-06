//
//  main.c
//  q4.c
//
//  Created by Jacqueline Liao on 3/2/19.
//  Copyright © 2019 Jacqueline Liao. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    struct Node * upper;
    struct Node * lower;
    char * item;
} node;

void insert(node * root, char * str) {
    if (strcmp(root->item, "")==0) { //base case
        root->item = str;
    } else if (strcmp(root->item, str) <= 0) { //inserted item should be above current node
        if (root->upper == NULL) { //create next node if it doesn't exist
            node * new_upper = malloc(sizeof(node));
            new_upper->upper = NULL;
            new_upper->lower = NULL;
            new_upper->item = str;
            root->upper = new_upper;
        }else{
            insert(root->upper, str);
        }
    } else { //inserted item should be below current node
        if (root->lower == NULL) { //create node if it doesn't exist
            node * new_lower = malloc(sizeof(node));
            new_lower->upper = NULL;
            new_lower->lower = NULL;
            new_lower->item = str;
            root->lower = new_lower;
        }else{
            insert(root->lower, str);
        }
    }
    
}

void print_tree(node * root) {
    if (root != NULL){ //recrusively print tree
        print_tree(root->lower); //print all items lower than root node
        printf("%s ", root->item); //print root node
        print_tree(root->upper); //print all item above root node
    }
}

void free_tree(node * root) {
    if (root != NULL) {
        free_tree(root->upper);
        free_tree(root->lower);
        free(root);
    }
}

int main(int argc, const char * argv[]) {
    node * root = malloc(sizeof(node));
    root->upper = NULL;
    root->lower = NULL;
    root->item = "";
    for (int i = 1; i < argc; i++) {
        insert(root,argv[i]);
    }
    print_tree(root);
    free_tree(root);
}
