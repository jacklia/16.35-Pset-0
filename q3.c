//
//  main.c
//  q3.c
//
//  Created by Jacqueline Liao on 3/2/19.
//  Copyright © 2019 Jacqueline Liao. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int phrase_length = 0;
    for (int i = 1; i < argc; ++i) {
        phrase_length += strlen(argv[i]);
    } //checking length of entire phrase
    char str[phrase_length]; //allocating array for entire phrase, no spaces
    for (int i = 1; i < argc; ++i) {//turning phrase into one array
        if (i== 1) {
            strcpy(str, argv[i]);
        } else {
            strcat(str, argv[i]);
        }
    }
    int begin = 0; //used as forward-looking checker in palindrome checker
    int end = strlen(str) - 1; //used as backward-looking checker in palindrome checker
    char final_str[phrase_length + argc];//build original phrase back up, including spaces, to print
    for (int i = 1; i < argc; ++i) {
        if (i== 1) {
            strcpy(final_str, argv[i]);
            strcat(final_str, " ");
        } else {
            strcat(final_str, argv[i]);
            strcat(final_str, " ");
        }
    }
    final_str[strlen(final_str)-1] = 0;//getting rid of last space
    while (end > begin) { //palindrome checker
        if (str[begin++] != str[end--]) {
            printf("\"%s\" is NOT a palindrome!\n", final_str);
            return 0;
        }
    }
    printf("\"%s\" is a palindrome!\n", final_str);
}


