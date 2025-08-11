/*
* I.M.Markov
* Hit model v1.0
*/

#include "../heads/dispatcher.h"


#define heads




int main() {
    printf("\n");
    printf("I.M.Markov \n");
    printf("Hit model v1.0 \n");
    printf("------------------------------------------------------------------\n");
    printf("\n");

    switch (main_dispatcher()) {
        // init error
    case -1:
        break;

        // succes launch
    case 0:
        printf("secces launch\n");
        break;

        // .......
    case 1:
        break;

    }
    printf("bye bye :)\n");
    return 0;
}

