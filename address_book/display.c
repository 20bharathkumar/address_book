#include "book.h"

Status display_contact(AddBook *adBook)
{
    //opening file
    adBook->fptr = fopen(adBook->fname,"r");
    char line[200];
    int i = 0;

    //displaying with formate
    printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
    fscanf(adBook->fptr,"%s",line);
    //loop till end of file
    while(fscanf(adBook->fptr,"%s",line) != -1)
    {
	char *namee = strtok(line,",");
	char *mob_n = strtok(NULL,",");
	char *email = strtok(NULL,",");
	char *loca = strtok(NULL,",");

	i++;	//for serial number
	printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
	//printf("Parsed fields: \nName: %s, Mobile.no: %s, E-mail: %s, Location: %s\n\n", namee, mob_n, email, loca);
	//printf("%-5d %-20s %-15s %-30s %-20s\n",i,namee,mob_n,email,loca);
    }
    return success;
}
