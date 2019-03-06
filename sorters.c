//
//  sorters.c
//  q5.c
//
//  Created by Jacqueline Liao on 3/4/19.
//  Copyright © 2019 Jacqueline Liao. All rights reserved.
//

#include "sorters.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap(char ** elem1, char ** elem2) {
    char * temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}
void bubble_sort(int argc, char ** args) {
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < argc - i - 1; j++) {
            if (strcmp(args[j], args[j + 1]) > 0) {
                swap(&args[j], &args[j + 1]);
            }
        }
    }
}
void bogo_sort(int argc, char ** args) {
    int num_swaps = 10;
    int seed = 2;
    srand(seed);
    // Idea: randomly shuffle. If the list is sorted, return. If not, try again.
    bool is_sorted = false;
    while (!is_sorted) {
        // Shuffle the list.
        for (int i = 0; i < num_swaps; i++) {
            int index1 = rand() % argc;
            int index2 = rand() % argc;
            swap(&args[index1], &args[index2]);
        }
        // Update is_sorted depending on list.
        is_sorted = true;
        for (int i = 0; i < argc - 1; i++) {
            if (strcmp(args[i], args[i + 1]) > 0) {
                is_sorted = false; break;
            }
        }
    }
}

void insertion_sort(int argc, char ** args) { //Implementing insertion sort
    int j;
    char * word;
    for (int i = 1; i < argc; i++) { //going through each word, check where it belongs in sorted array of items that come before it
        word = args[i];
        j = i-1;
        while (j >= 0 && strcmp(args[j],word)>0) {
            args[j+1] = args[j];
            j = j-1;
        }
        args[j+1] = word;
    }
}

