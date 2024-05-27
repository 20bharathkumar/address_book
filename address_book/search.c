#include "book.h"

Status search_contact(AddBook *adBook)
{
    int choice,i,flag = 0;
    //openng file
    FILE *ptr = fopen(adBook->fname,"r");
    char line[200];

    //displaying instruction
    printf("1) by name\n2) by mobile number\n3) by e-mail\n4) by location\nEnter your choice: ");
    scanf("%d",&choice);
    printf("===========================================================================================\n");

    switch(choice)
    {
	case 1://search by name
	    char name[20];
	    i=0;
	    printf("Enter the name: ");
	    scanf(" %[^\n]",name);
	    printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");

	    while(fscanf(ptr,"%s",line) != -1)
	    {
		char *namee = strtok(line,",");
		char *mob_no = strtok(NULL,",");
		char *email = strtok(NULL,",");
		char *location = strtok(NULL,",");
		if(strstr(namee,name) != NULL)	//if name matches display
		{
		    printf("%d\t\t%s\t\t%s\t\t%s\t\t\t%s\n",i,namee,mob_no,email,location);
		    flag = 1;
		    i++;
		}
	    }
	    if(flag == 0)	//if data not found
	    {
		printf("Error : Data not found\n");
		return failure;
	    }
	    return success;
	    break;
	case 2://searching by phone number
	    char m_num[20];
	    i=0;
	    printf("Enter Mobile number: ");
	    scanf(" %s",m_num);
	    printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");

	    while(fscanf(ptr,"%s",line) != -1)
	    {
		char *namee = strtok(line,",");
		char *mob_no = strtok(NULL,",");
		char *email = strtok(NULL,",");
		char *location = strtok(NULL,",");
		if(mob_no != NULL)
		{
		    if(strstr(mob_no,m_num) != NULL)	//matching display
		    {
			printf("%d\t\t%s\t\t%s\t\t%s\t\t\t%s\n",i,namee,mob_no,email,location);
			flag = 1;
			i++;
		    }
		}
	    }
	    if(flag == 0)	//if data not found
	    {
		printf("Error : Data not found\n");
		return failure;
	    }
	    return success;
	    break;
	case 3://searching by email
	    char em[20];
	    i=0;
	    printf("Enter Email: ");
	    scanf(" %s",em);
	    printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");

	    while(fscanf(ptr,"%s",line) != -1)
	    {
		char *namee = strtok(line,",");
		char *mob_no = strtok(NULL,",");
		char *email = strtok(NULL,",");
		char *location = strtok(NULL,",");
		if(email != NULL)
		{
		    if(strstr(email,em) != NULL)	//if email matches
		    {
			printf("%d\t\t%s\t\t%s\t\t%s\t\t\t%s\n",i,namee,mob_no,email,location);
			flag = 1;
			i++;
		    }
		}
	    }
	    if(flag == 0)	//if data not found
	    {
		printf("Error : Data not found\n");
		return failure;
	    }
	    return success;
	    break;
	case 4://searching by location
	    char loc[20];
	    i=0;
	    printf("Enter location: ");
	    scanf(" %s",loc);
	    printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");

	    while(fscanf(ptr,"%s",line) != -1)
	    {
		char *namee = strtok(line,",");
		char *mob_no = strtok(NULL,",");
		char *email = strtok(NULL,",");
		char *location = strtok(NULL,",");
		if(location != NULL)
		{
		    if(strstr(location,loc) != NULL)	//if location matches display
		    {
			printf("%d\t\t%s\t\t%s\t\t%s\t\t\t%s\n",i,namee,mob_no,email,location);
			flag = 1;
			i++;
		    }
		}
	    }
	    if(flag == 0)	//data not found
	    {
		printf("Error : Data not found\n");
		return failure;
	    }
	    return success;
	default:
	    printf("Error : Invalid choice\n");
    }

}
