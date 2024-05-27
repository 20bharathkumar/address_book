/*
NAME: BHARATHKUMAR K
DATE: 19/12/2024
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include "book.h"

Status add_contact(AddBook *adBook)
{
    int choice = 0,flag = 0;
    char opt;
    //file opening
    adBook->fptr = fopen(adBook->fname,"a");
    FILE *frptr = fopen(adBook->fname,"r+");

    //taking name from user
    while(1)
    {
	printf("Enter Name* (Mandetory): ");
	scanf(" %[^\n]",adBook->name);

	char line[1024];
	rewind(frptr);
	while(fscanf(frptr,"%s",line) != -1)	//checking if user name already exist or not
	{
	    flag = 0;
	    char *name = strtok(line,",");
	    //printf("name %s\n",adBook->name);
	    if(strcmp(name,adBook->name) == 0)
	    {
		printf("Error: %s already exist\n",adBook->name);
		flag = 1;
		break;
	    }
	}
	if(flag == 0)
	    break;
    }

    //taking Phone number from user
    printf("Do you want to enter phone number [y/n]: ");	//asing user to enter or not
    scanf(" %c",&opt);
    if(opt == 'y' || opt == 'Y')
    {
	printf("Enter phone number: ");
	scanf(" %s",adBook->mob_num);

	int i=0;
	if(strlen(adBook->mob_num) == 10)	//checking if number has 10 digits or not
	{
	    while(adBook->mob_num[i] != '\0')	//every digit is int or not
	    {
		if(!isdigit(adBook->mob_num[i]))
		{
		    printf("Error: Enter valid phone number\n");
		    strcpy(adBook->mob_num,"-");
		    break;
		}
		i++;
	    }
	}
	else
	{
	    printf("Error: Enter a valid phone number\n");
	    strcpy(adBook->mob_num,"-");
	}
    }
    else if(opt == 'n'|| opt == 'N')
    {
	strcpy(adBook->mob_num,"-");	//if no save default
    }
    else
    {
	printf("Error : Invalid input\n");
	strcpy(adBook->mob_num,"-");
    }

    //taking Email from user
    printf("Do you want to enter e-mail [y/n]: ");	//asking user to enter email or not
    scanf(" %c",&opt);
    if(opt == 'y' || opt == 'Y')
    {
	printf("Enter Email id: ");
	scanf(" %s",adBook->mail);

	if(strchr(adBook->mail,'@') != NULL)		//checking id email has @ or not
	{
	    if(strstr(adBook->mail,".com") != NULL);	//checking if mail has .com or not
	    else
	    {
		printf("Error: Enter a valid email\n");
		strcpy(adBook->mail,"-");
	    }
	}
	else
	{
	    printf("Error: Enter a valid email\n");
	    strcpy(adBook->mail,"-");
	    
	}
    }
    else if(opt == 'n'|| opt == 'N')
    {
	strcpy(adBook->mail,"-");	//if no save default
    }
    else
    {
	printf("Error : Invalid input\n");
	strcpy(adBook->mail,"-");
    }

    //taking address from user
    printf("Do you want to enter address [y/n]: ");	//asking to enter or not
    scanf(" %c",&opt);
    if(opt == 'y' || opt == 'Y')
    {
	printf("Enter address: ");
	scanf(" %s",adBook->address);
    }
    else if(opt == 'n'|| opt == 'N')	//no save default
    {
	strcpy(adBook->address,"-");
    }
    else
    {
	printf("Error : Invalid input\n");
	return failure;
    }

    //saving to file
    //write to file
    while(1)
    {
	printf("1) Save\n2) Exit\nEnter your choice: ");
	scanf("%d",&choice);
	if(choice == 2)	//if not saving
	{
	    strcpy(adBook->name,"");
	    strcpy(adBook->mob_num,"");
	    strcpy(adBook->mail,"");
	    strcpy(adBook->address,"");
	    return failure;
	}
	else if(choice == 1)	//if saving
	{
	    printf("Name is %s\n",adBook->name);
	    printf("number is %s\n",adBook->mob_num);
	    printf("Mail id is %s\n",adBook->mail);
	    printf("Address is %s\n",adBook->address);
	    fprintf(adBook->fptr, "%s,%s,%s,%s,\n",adBook->name, adBook->mob_num, adBook->mail, adBook->address);
	   
	    rewind(frptr);
	    char ch[10];
	    fscanf(frptr,"%s",ch);
	    //printf("data %s\n",ch);
	    adBook->count = atoi(strtok(ch,"#"));	//to increment the contact number count
	    (adBook->count)++;
	    //printf("data %d\n",adBook->count);
	    rewind(frptr);
	    fprintf(frptr,"#%d#",adBook->count);
	    
	    fclose(adBook->fptr);
	    return success;
	}
	else
	    printf("Invalid option\n");
    }

return success;
}
