#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	//return failure when there is nothing to add
	if(*head1==NULL && *head2==NULL)
	return FAILURE;

    Dlist *temp1 =*tail1; 
    Dlist *temp2 =*tail2;  
    int carry = 0,sum,digit;
    //loop until both lists are done and no carry
	//short circuit happens when one condition is true 
    while (temp1!= NULL||temp2 != NULL ||carry != 0)
    {
        int op1=0,op2=0;

        // get digits from each list
        if (temp1!=NULL)
        {
            op1 = temp1->data;
            temp1 = temp1->prev;
        }

        if (temp2!=NULL)
        {
            op2 = temp2->data;
            temp2 = temp2->prev;
        }

        // case 1 & 2: with/without carry
        sum = op1 + op2 + carry;
		//case 3: with carry
        if (sum > 9)
        {
            digit = sum % 10;
            carry = 1; //update carry  
        }
        else
        {
            digit =sum;
            carry =0;//reset carry
        }
        if(insert_first(headR, tailR, digit)==FAILURE)
		return FAILURE;
    }

    return SUCCESS;
}

