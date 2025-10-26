#include "apc.h"

int main(int argc,char *argv[])
{
	if (argc != 4)   // check if user entered 3 arguments after ./a.out
    {
        printf("ERROR: Invalid input format.\n");
        printf("PLEASE ENTER AS SHOWN HERE: ./a.out <num1> <operator> <num2>\n");
        return FAILURE;
    }
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL,*tailR=NULL;

	char operator=argv[2][0];
		switch (operator)
		{
			case '+':
                                digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				/* call the function to perform the addition operation */
                                if(addition(&head1,&tail1,&head2,&tail2,&headR,&tailR)==SUCCESS)
								{
								   printf("The result is: ");
								   print_list(headR);
								}
								else
								   printf("ERROR: OPERATION FAILED\n");
				break;
			case '-':	
			                     digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				/* call the function to perform the subtraction operation */
				                 int flag=subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
								 if(flag==1)
								 {
									printf("The result is: ");
									printf("-");
									print_list(headR);
								 }
								 else if(flag==0)
								 {
								 printf("The result is: ");
								 print_list(headR);
								 }
								 else
								  printf("ERROR: OPERATION FAILED\n");
				break;
			case 'x':	
			                      digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				/* call the function to perform the multiplication operation */
				                   if(multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR)==SUCCESS)
								   {
									  printf("The result is: ");
								      print_list(headR);
								   }
								   else
								   printf("ERROR: OPERATION FAILED\n");
				break;
			case '/':	 
			                       digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				/* call the function to perform the division operation */
				                    if(division(&head1,&tail1,&head2,&tail2,&headR,&tailR)==SUCCESS)
									{
										printf("The result is: ");
										print_list(headR);
									}
									else
									 printf("ERROR: OPERATION FAILED\n");
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
	return 0;
}