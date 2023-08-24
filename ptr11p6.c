/* ptr11p6.c
 * source file for ptr11p6
 *
 * added struct entry head.
 * added insert(), finally works.
 * added delete(), finally works.
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
void insertEntry(struct entry *newEntry, struct entry *insertPoint);
void deleteEntry(struct entry *entry);




int main(int argc, char *argv[]){

    struct entry n1, n2, n3, n4, n5, head;
    struct entry newEntry;

/* init entries */

    n1.value = 100;
    n2.value = 200;
    n3.value = 300;
    n4.value = 400;
    n5.value = 500;
    head.value = 0;
    newEntry.value = 600;





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

    newEntry.next = NULL;
    newEntry.prev = NULL;

    head.next = &n1;
    head.prev = NULL;



/* print out the list */

    printList(&head);

    insertEntry(&newEntry, &head);

    printList(&head);

    deleteEntry(&newEntry);

    printList(&head);

    deleteEntry(&n1);

    printList(&head);

    deleteEntry(&n5);

    printList(&head);

    deleteEntry(&head);

    printList(&head);


    return(0);
}


/* function definitions */

void printList(struct entry *p2list){

    struct entry *theEntry;

    theEntry = p2list->next;
    while(theEntry != NULL){
        printf("%i ", theEntry->value);
        theEntry = theEntry->next;
    }
    printf("\n");


}



void insertEntry(struct entry *newEntry, struct entry *insertPoint){

    /* init newEntry */

    newEntry->next = insertPoint->next;
    newEntry->prev = insertPoint;

    /* update insertPoint */

    insertPoint->next = newEntry;

    /* update -right- */
    if((newEntry->next) ==NULL){
        ;
    }else{
    (newEntry->next)->prev = newEntry;
    }

}



void deleteEntry(struct entry *entry){

    if((entry->prev) == NULL){
        printf("Don't delete list head\n");
    }else if(entry->next == NULL){
        (entry->prev)->next = NULL;
        entry->next = NULL;
        entry->prev = NULL;
    }else{
        /* update left */
        (entry->prev)->next = entry->next;

        /* update right */
        (entry->next)->prev = entry->prev;

        /* nullify entry */
        entry->next = NULL;
        entry->prev = NULL;


    }

}

