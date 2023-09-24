#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "libgal.h"

void viewMenu(matBuffer_t *headp) {

    int menuSel;

    printf("\t\tMENU:\n\n"
           "1. Load Head Matrices\n"
           "2. View buffer\n"
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

            headp = matHeadLoad(headp);
            viewMenu(headp);
            break;

        case(2):

            if(headp != NULL) {

                bufferView(headp);
                viewMenu(headp);
            
            } else {

                #if GAL_TRACE
                    printf(">> ERROR, EMPTY LIST %s\n", GAL_ERROR);
                    exit(EXIT_FAILURE);
                #endif
            }
            break;

        default:

            #if GAL_TRACE
                printf(">> CASE NOT YET DEFINED %s\n", GAL_ERROR);
                exit(EXIT_FAILURE);
            #endif

            exit(EXIT_SUCCESS);
    }
}

matBuffer_t* matHeadLoad(matBuffer_t *currentHead) {
     
    matBuffer_t *newMatHead = malloc(sizeof(matBuffer_t));

    long int i, j; 
    long double element;

    do {

        printf("Type the number of rows and columns respectively separated by a blank >> ");
    
    } while(scanf("%d%d", &(newMatHead -> rows), &(newMatHead -> columns) ) != 2);

    printf("\n");

    newMatHead -> matAddress = malloc(sizeof(long double*) * newMatHead -> rows);

    if(newMatHead -> matAddress != NULL) {

        for(i = 0; i < newMatHead -> rows; i++) {

            *( (newMatHead -> matAddress) + i ) = malloc(sizeof(long double) * newMatHead -> columns);

            if(*( (newMatHead -> matAddress) + i) != NULL ) {

                for(j = 0; j < newMatHead -> columns; j++) {
            
                    do {
            
                        printf("Type in the [%li][%li] element >> ", i, j);

                    } while(scanf("%Lf", &element) != 1);
            
                    *(*( (newMatHead -> matAddress) + i ) + j) = element;
                }
            }
        }

        printf("\n");
    }

    for(i = 0; i < newMatHead -> rows; i++) {

        for(j= 0; j < newMatHead -> columns; j++) {

            printf("(%.2Lf) ", *(*( (newMatHead -> matAddress) + i ) + j));
        }

        printf("\n\n");
    }

    newMatHead -> linkp = currentHead;
    currentHead = newMatHead;

    printf("\n");

    #if GAL_TRACE
        printf(">> MATRIX LOADED SUCCCESSFULLY %s\n", GAL_SUCCESS);
    #endif

    printf("\n");

    return (currentHead);
}

void bufferView(matBuffer_t *currentView) {

    long int i, j; 

    if(currentView != NULL) {

        for(i = 0; i < currentView -> rows; i++) {

            for(j= 0; j < currentView -> columns; j++) {

                printf("(%.2Lf) ", *(*( (currentView -> matAddress) + i ) + j));
            }

            printf("\n\n");
        }
    }

    printf("\n");
}