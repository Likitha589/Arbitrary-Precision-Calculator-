#include "apc.h"

/* Function to perform multiplication */
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    if (*head1 == NULL||*head2 == NULL)
        return FAILURE;
    
	Dlist *temp=*head1;
    int zero_flag1=1, zero_flag2=1;

    while(temp)
    {
        if (temp->data!=0)
        {
            zero_flag1=0;
            break;
        }
        temp=temp->next;
    }

    temp=*head2;
    while(temp)
    {
        if (temp->data!=0)
        {
            zero_flag2=0;
            break;
        }
        temp=temp->next;
    }
    // condition if one of the operand is zero
    if (zero_flag1||zero_flag2)
    {
        // clear result list first
        delete_list(headR,tailR);
        // insert a single zero as the result
        insert_last(headR,tailR,0);
        return SUCCESS;
    }

    Dlist *temp2 = *tail2;
    int count = 0;
    Dlist *headR1 = NULL;
	Dlist *tailR1 = NULL;
    Dlist *headR2 = NULL;
	Dlist *tailR2 = NULL;
    while (temp2!=NULL)
    {
        Dlist *temp1 = *tail1;
        int carry = 0, product;
        // clear R2 list for each new digit
        delete_list(&headR2, &tailR2);
        while (temp1 != NULL)
        {
            product =(temp1->data * temp2->data)+carry;
            insert_first(&headR2,&tailR2,product%10);
            carry=product / 10;
            temp1= temp1->prev;
        }

        if (carry)
            insert_first(&headR2, &tailR2, carry);
        
		for (int i = 0; i<count;i++)
            insert_last(&headR2, &tailR2,0);
			
        if (count==0)
        {
            delete_list(&headR1, &tailR1);
            Dlist *t = headR2;
            while (t!=NULL)
            {
                insert_last(&headR1,&tailR1,t->data);
                t=t->next;
            }
        }
        else
        {
            // Add the two result lists
            Dlist *H = NULL;
			Dlist *T = NULL;
            addition(&headR1, &tailR1, &headR2, &tailR2, &H, &T);

            // Delete previous R1
            delete_list(&headR1, &tailR1);

            // use H to insert and delete after
            Dlist *t = H;
            while (t!=NULL)
            {
                insert_last(&headR1,&tailR1,t->data);
                t=t->next;
            }

            // Free sum list
            delete_list(&H,&T);
        }

        count++;
        temp2 = temp2->prev;// traverse until temp2 becomes NULL
    }

    // Final result
    delete_list(headR, tailR);
    Dlist *final = headR1;
    while (final!=NULL)
    {
        insert_last(headR, tailR, final->data);
        final=final->next;
    }

    // clean temp lists
    delete_list(&headR1, &tailR1);
    delete_list(&headR2, &tailR2);
    return SUCCESS;
}
