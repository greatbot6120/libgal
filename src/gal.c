#include <stdio.h>
#include <stdlib.h>
#include "libgal.h"

void newGal(void) {

    char selection;

    printf("Enter m for the menu or q to exit >> ");
    selection = getchar();
    printf("\n");

    switch(selection) {

        case(GAL_MENU):

            viewMenu();
            break;

        case(GAL_QUIT):

            exit(EXIT_SUCCESS);

        default:

            #ifdef GAL_TRACE
                printf(">> ERROR MAIN SELECTION %s\n", GAL_ERROR);
                exit(EXIT_FAILURE);
            #endif
    }

}

int main(int argc, char* argv[]) {
    
    newGal();

    return 0;
}