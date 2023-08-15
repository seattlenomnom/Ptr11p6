/* ptr11p6.c
 * source file for ptr11p6
 *
*/

/* includes */

#include <stdio.h>
#include <stddef.h>




/* defines */



/* structure definitions */

struct entry{
    int value;
    struct entry *next;
    struct entry *prev;
};




/* function declarations */

void printList(struct entry *p2list);




int main(int argc, char *argv[]){

    struct entry n1, n2, n3, n4, n5;
    struct entry *p2list;

/* init entries */

    n1.value = 100;
    n2.value = 200;
    n3.value = 300;
    n4.value = 400;
    n5.value = 500;




/* create doubly linked list */

    n1.next = &n2;
    n1.prev = NULL;

    n2.next = &n3;
    n2.prev = &n1;

    n3.next = &n4;
    n3.prev = &n2;

    n4.next = &n5;
    n4.prev = &n3;

    n5.next = NULL;
    n5.prev = &n4;

    p2list = &n1;


/* print out the list */

    printList(p2list);




    return(0);
}


/* function definitions */

void printList(struct entry *p2list){

    struct entry *theEntry;

    theEntry = p2list;
    while(theEntry != NULL){
        printf("%i ", theEntry->value);
        theEntry = theEntry->next;
    }
    printf("\n");



















}









