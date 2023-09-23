#include <stdio.h>
#include <stdlib.h>
#include "libgal.h"

void viewMenu() {

    int menuSel;

    printf("\t\tMENU:\n\n"
           "1. Load Matrices\n"
           "2. Save Matrices\n"
           "3. Sum Matrices\n"
           "4. Lambda-multiply Matrices\n"
           "5. Multiply Matrices\n"
           "6. Exit\n\n"
           "Enter a selection (1-6) >> ");
    scanf("%d", &menuSel);

    /* check for right values */
    if( (menuSel < 1) || (menuSel > 6) ) {
        
        #if GAL_TRACE
            printf(">> ERROR MENU SELECTION, NOT A VALID OPTION %s\n", GAL_ERROR);
            exit(EXIT_FAILURE);
        #endif
    }

    switch(menuSel) {

        case(1):

            matLoad();
            break;

        default:

            #if GAL_TRACE
                printf(">> CASE NOT YET DEFINED %s\n", GAL_ERROR);
                exit(EXIT_FAILURE);
            #endif

            exit(EXIT_SUCCESS);
    }
}

void matLoad() {

    int rows, columns, i, j, element;
    int **loader;

    do {

        printf("Type the number of rows and columns respectively separated by a blank >> ");
   
    } while(scanf("%d%d", &rows, &columns) != 2);

    loader = malloc(sizeof(int*) * rows);

    if(loader != NULL) {

        for(i = 0; i < rows; i++) {

            *(loader + i) = malloc(sizeof(int) * columns);
        }
    }

    if(*(loader + i) != NULL) {

        for(i = 0; i < rows; i++) {

            for(j = 0; j < columns; j++) {

                do {

                    printf("Type in the [%d][%d] element >> ", i, j);
                
                } while(scanf(" %d", &element) != 1);
            }
        }
    }
}