#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	if (*head1==NULL||*head2==NULL)
        return FAILURE;

    // check for division by zero
    Dlist *temp=*head2;
    int flag=1;
    while(temp)
    {
        if (temp->data != 0)
        {
            flag=0;
            break;
        }
        temp=temp->next;
    }
    if(flag)
    {
        printf("ERROR: Zero Exception Error\n");
        return FAILURE;
    }

    Dlist *t1 = *head1;
    Dlist *t2 = *head2;

    // find lengths
    int len1 = 0, len2 = 0;
    while(t1!=NULL)
    {
        len1++;
        t1=t1->next;
    }
    while(t2!=NULL)
    {
        len2++;
        t2=t2->next;
    }

    // num1 < num2 result is 0
    if (len1<len2)
    {
        insert_last(headR,tailR,0);
        return SUCCESS;
    }
    else if (len1==len2)
    {
        // digit by digit
        t1 = *head1;
        t2 = *head2;
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->data < t2->data)// if second digit is less than first digit
            {
                insert_last(headR, tailR, 0);// insert 0
                return SUCCESS;
            }
            else if(t1->data > t2->data)
                break;// break out of while loop
            t1=t1->next;
            t2=t2->next;
        }
        // if all digits equal
        if (t1==NULL && t2==NULL)
        {
            insert_last(headR, tailR, 1);// insert 1
            return SUCCESS;
        }
    }
    // repeated subtraction
    int count=0;
    while(1)
    {
        // check if head1 < head2 before subtraction
        Dlist *a = *head1;
        Dlist *b = *head2;
        int lena = 0, lenb = 0;
        while(a)
        {
            lena++;
            a = a->next;
        }
        while(b)
        {
            lenb++;
            b = b->next;
        }

        // If smaller, stop
        if(lena<lenb)
            break;
        else if(lena == lenb)
        {
            a = *head1;
            b = *head2;
            int smaller = 0;
            while(a!=NULL&&b!=NULL)
            {
                if (a->data<b->data)
                {
                    smaller = 1;
                    break;
                }
                else if (a->data > b->data)
                    break;// break out of loop 
                a=a->next;
                b=b->next;
            }
            if(smaller)
                break;
        }

        // Temporary list to hold subtraction result
        Dlist *headR2= NULL;
        Dlist *tailR2= NULL;

        subtraction(head1,tail1,head2,tail2,&headR2,&tailR2);

        // Free the old list1
        delete_list(head1,tail1);

        // Update head1 to point to new result
        *head1=headR2;
        *tail1=tailR2;

        count++;// increment count
    }

    // Store the quotient count in result list
    if (count==0)
    {
        insert_last(headR,tailR,0);
    }
    else
    {
        while(count>0)
        {
            insert_first(headR,tailR,count%10);// insert count digit by digit
            count/=10;
        }
    }
    return SUCCESS;
}
