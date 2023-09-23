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

    /* enter the menu */
    void viewMenu();

    /* dinamically loads a matrix */
    void matLoad();


#endif