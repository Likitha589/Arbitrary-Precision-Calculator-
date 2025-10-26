#include "apc.h"

Dlist *create_node(int digit)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
        return NULL;

    new->data = digit;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

int insert_first(Dlist **head, Dlist **tail, int digit)
{
    Dlist *new = create_node(digit);//create a node with single digit
    if (new == NULL)
        return FAILURE;

    if (*head == NULL)  // if list is empty
    {
        *head = new;
        *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
    return SUCCESS;
}

int insert_last(Dlist **head, Dlist **tail, int digit)
{
    Dlist *new = create_node(digit);//1 node=1 digit
    if (new == NULL)
        return FAILURE;

    if (*head == NULL) // empty list
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
    return SUCCESS;
}

void delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL)
        return; 
    Dlist *temp = *head;
    Dlist *next_node;

    while (temp != NULL)
    {
        next_node = temp->next; 
        free(temp);             
        temp = next_node;       
    }

    *head = NULL;
    *tail = NULL;
}

void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    *head1=*head2=NULL;
    *tail1=*tail2=NULL;
    char *ptr = argv[1]; //first operator 
    while (*ptr!= '\0')
    {
        if (*ptr >='0' && *ptr <='9') 
        {
            int digit = *ptr -'0';
            insert_last(head1, tail1, digit);
        }
        ptr++;
    }
    ptr = argv[3];  //second operator
    while (*ptr!= '\0')
    {
        if (*ptr>='0' && *ptr<= '9')
        {
            int digit = *ptr - '0';
            insert_last(head2, tail2, digit);
        }
        ptr++;
    }
}