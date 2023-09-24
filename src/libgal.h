#ifndef LIBGAL_H

    #define LIBGAL_H

    /* for debugging purposes*/
    #define GAL_AFFIRMATIVE 'y'
    #define GAL_NEGATIVE `n`
    #define GAL_QUIT 'q'
    #define GAL_MENU 'm'
    #define GAL_TRACE 1
    #define GAL_SITE 30
    #define GAL_SUCCESS "✔"
    #define GAL_ERROR "✗"

    typedef struct matBuffer {

        long double **matAddress;
        int rows, columns;
        struct matBuffer *linkp;
    
    } matBuffer_t;

    /* enter the menu */
    void viewMenu(matBuffer_t *headp);

    /* dinamically loads a matrix */
    matBuffer_t* matHeadLoad(matBuffer_t *currentHead);
    void bufferView(matBuffer_t *currentView);


#endif