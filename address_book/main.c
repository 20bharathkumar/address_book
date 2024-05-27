/*
NAME: BHARATHKUMAR K
DATE: 19/12/2024
DESCRIPTION: Address book
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include "book.h"
int main(int argc,char *argv[])
{
    AddBook adBook;
    int mn_cho,ad_cho;
    adBook.count = 0;
    //if agruments greater than 1
    if(argc > 1)
    {
	//validating csv file
	if(valid_file(argv[1],&adBook) == failure)
	{
	    printf("Error : file validation failed\n");
	    return 0;
	}
	printf("#################################### ADDRESS BOOK ######################################\n");
	while(1)
	{
	    //printing instructions
	    printf("===========================================================================================\n");
	    printf("1) Add contact\n2) Edit\n3) Search\n4) Delet\n5) Display contact\n6) Exit\n");
	    printf("Enter your choice: ");
	    scanf("%d",&mn_cho);
	    printf("===========================================================================================\n");

	    switch(mn_cho)
	    {
		case 1: //for adding contact
			printf("INFO : Selected Add contact\n");
			if(add_contact(&adBook) == success)
			{
			    printf("INFO : Contact added\n");
			}
			else
			{
			    printf("Error : add contact failed\n");
			}
			break;
		case 2: //for editing contact
			printf("INFO : Selected Edit\n");
			if(edit_contact(&adBook) == success)
			{
			    printf("INFO : contact edited\n");
			}
			else
			{
			    printf("Error : contact not edited\n");
			}
			break;
		case 3: //searching contact
			printf("INFO : Selected Search\n");
			if(search_contact(&adBook) == failure)
			{
			    printf("Error : searching contact failed\n");
			}
			break;
		case 4: //for deleting contact
			printf("INFO : Selected Delet\n");
			if(delete_contact(&adBook) == success)
			{
			    printf("INFO : contact deleted\n");
			}
			else
			{
			    printf("Error : delete contact failed\n");
			}
			break;
		case 5: //for printing contact
			printf("INFO : Selected Print\n");
			if(display_contact(&adBook) == failure)
			{
			    printf("Error : dispalying contact failed\n");
			}
			break;
		case 6: //for exit
			return 0;
		default: printf("Error : Invalid option\n");
			 break;

	    }
	}
    }
    else
    {
	printf("Error : pass valid numbe of arguments\n");
    }

    return 0;
}

