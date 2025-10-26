#ifndef APC_H
#define APC_H


#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

Dlist * create_node(int digit);
int insert_first(Dlist **head,Dlist **tail,int digit);
int insert_last(Dlist **head,Dlist **tail,int digit);
void delete_list(Dlist **head, Dlist **tail);
/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);


/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);
void print_list(Dlist *head);
#endif
