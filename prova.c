#include <stdio.h>
#include <stdlib.h>

void matLoad(int rows, int columns) { 

    int indexLoop, subIndexLoop;
    int **loader = malloc(sizeof(int*) * rows);

    if(loader != NULL) {

        for(indexLoop = 0; indexLoop < rows; indexLoop++) {

            *(loader + indexLoop) = malloc(sizeof(int) * columns);

            if(*(loader + indexLoop ) != NULL) {

                for(subIndexLoop = 0; subIndexLoop < columns; subIndexLoop++) {

                    *(*(loader + indexLoop) + subIndexLoop) = 1;
                }
            }
        }
    }

    for(indexLoop = 0; indexLoop < rows; indexLoop++) {

        for(subIndexLoop = 0; subIndexLoop < columns; subIndexLoop++) {

            printf("%d ", *(*(loader + indexLoop) + subIndexLoop));
        }

        printf("\n");
    }
}

int main(int argc, char* argv[]) {

    matLoad(10,15);

    return 0;
}
