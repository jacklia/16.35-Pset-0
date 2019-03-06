//
//  main.c
//  q2.c
//
//  Created by Jacqueline Liao on 3/2/19.
//  Copyright © 2019 Jacqueline Liao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char point = *argv[2]; //operation
    double fv = atof(argv[1]); //first value that gets passe in
    double sv = atof(argv[3]); //second value that gets passed in

    if (point == '*' || point == 'x' || point == 'X') {
        printf("%f",fv*sv); //multiply
    } else if (point == '/') {
        printf("%f",fv/sv); //divide
    } else if (point == '-') {
        printf("%f",fv-sv); //subtraction
    } else if (point == '+') {
        printf("%f",fv+sv); //addition
    }
}
