#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	if (*head1 == NULL && *head2 == NULL)
        return FAILURE;

    Dlist *temp1 =*tail1;   //start from tail (insert last)
    Dlist *temp2 =*tail2;
    int borrow =0, flag =0;  //flag=1 means negative result

     //finding lengths to detect which number is larger
    int len1 =0, len2 =0; 
    Dlist *t1 =*head1; 
	Dlist *t2 =*head2;
    while (t1!=NULL) 
	{ 
		len1++; 
		t1= t1->next; 
	}
    while (t2!=NULL) 
	{
		 len2++; 
		 t2= t2->next; 
	}

    //compare which number is larger
    Dlist *Lhead;
	Dlist *Ltail;
    Dlist *Shead;
	Dlist *Stail;

    if (len1 > len2)//eg: 126 - 35
    {
        Lhead = *head1; 
		Ltail = *tail1;
        Shead = *head2; 
		Stail = *tail2;
    }
    else if (len1 < len2)//eg: 35 - 126
    {
        flag = 1;
        Lhead = *head2; 
		Ltail = *tail2;
        Shead = *head1; 
		Stail = *tail1;
    }
    //eg: 126 - 123
    else  // same length means compare digit by digit from head
    {
        Dlist *a = *head1;
		Dlist *b = *head2;
        while (a!=NULL && b!=NULL&& a->data == b->data)
        {
            a = a->next;
            b = b->next;
        }
        if (a==NULL)   // eg: 35 - 35
        {
            insert_first(headR, tailR, 0);// result is 0 
            return SUCCESS;
        }
        if (a->data>b->data)//eg: 56 - 46
        {
            //update pointers only because normal subtraction
            Lhead = *head1; 
			Ltail = *tail1;
            Shead = *head2; 
			Stail = *tail2;
        }
        else //eg: 46 - 56
        {
            // if a->data<b->data then update flag 
            flag = 1;
            Lhead = *head2; 
            Ltail = *tail2;
            Shead = *head1; 
            Stail = *tail1;
        }
    }
    
    //subtract digit by digit from right to left
    Dlist *p = Ltail;
    Dlist *q = Stail;
    while (p!=NULL)
    {
        int a= p->data - borrow;//if exist (a-1) if no borrow a=p->data
        int b;
		if(q!=NULL)
		{
			b=q->data;
		}
		else// for unequal nodes replace by 0 (eg: 126 - 76)
		{
			b=0;
		}

        if (a<b)//borrow condition
        {
            a += 10;//after borrow, digit becomes +10 
            borrow= 1;
        }
        else
        {
            borrow= 0;
        }

        int sub = a-b;
        insert_first(headR,tailR,sub);

        //traverse till NULL
        p = p->prev;
        if (q!=NULL)
		{ 
		    q = q->prev;
		}
    }
   
   while((*headR)!=NULL && (*headR)->data==0 && (*headR)->next!=NULL)
        *headR= (*headR)->next;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    return flag;
}
