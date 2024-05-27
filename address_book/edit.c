#include "book.h"

Status edit_contact(AddBook *adBook)
{
    int choice,flag=0,data,i = 0,count=0;
    char o_data[20],n_data[20],line[200],*namee,*mob_n,*email,*loca,ch;

    FILE *ptr = fopen(adBook->fname,"r+");
    FILE *tptr = fopen("temp.csv","w+");

    printf("===========================================================================================\n");
    printf("1) edit name\n2) edit mobile number\n3) edit email\n4) edit location\nEnter your choice: ");
    scanf("%d",&choice);
    printf("===========================================================================================\n");

    switch(choice)
    {
	case 1:
	    printf("Enter the name to edit: ");
	    scanf(" %[^\n]",o_data);

	    printf("Enter new name: ");
	    scanf(" %[^\n]",n_data);

	    while(fscanf(ptr,"%s",line) != -1)
	    {
		namee = strtok(line,",");
		mob_n = strtok(NULL,",");
		email = strtok(NULL,",");
		loca = strtok(NULL,",");

		if(strcmp(namee,o_data) == 0)
		{
		    fprintf(tptr,"%s,%s,%s,%s,\n",n_data,mob_n,email,loca);
		    flag = 1;
		}
		else
		{
		    //to find the new data is already present or not
		    if(strcmp(namee,n_data) == 0)
		    {
			printf("Error : name already exist\n");
			return failure;
		    }
		    fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}
	    }

	    //if editing data not present in file 
	    if(flag == 0)
	    {
		printf("Error : data not found\n");
		return failure;
	    }
	    printf("INFO : Name edited\n");

	    break;
	case 2:
	    printf("Enter the mobile number to edit: ");
	    scanf(" %s",o_data);
	    printf("Enter new mobile number: ");
	    scanf(" %s",n_data);

	    i = 0;
	    //checking if adding a valid data or not
	    if(strlen(n_data) == 10 && strlen(o_data) == 10)
	    {
		while(n_data[i] != '\0' && o_data[i] != '\0')
		{
		    if(!isdigit(n_data[i]) && !isdigit(o_data[i]))
		    {
			printf("Error: Enter valid phone number\n");
			return failure;
		    }
		    i++;
		}
	    }
	    else
	    {
		printf("Error : pass valid mobile number\n");
		return failure;
	    }

	    count = 0;
	    while(fscanf(ptr,"%s",line) != -1)
	    {
		namee = strtok(line,",");
		mob_n = strtok(NULL,",");

		//printf("%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		if(strcmp(o_data,mob_n) == 0)
		    count++;
	    }
	    //if editing data not present in file
	    if(count == 1)
	    {
		rewind(ptr);
		while(fscanf(ptr,"%s",line) != -1)
		{
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    if(strcmp(mob_n,o_data) == 0)
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,n_data,email,loca);
		    else
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}
	    }
	    else if(count > 1)
	    {
		printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
		rewind(ptr);
		i = 0;
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    if(strcmp(o_data,mob_n) == 0)
			printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
		    //printf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}

		printf("Enter the serial number to edit: ");
		scanf("%d",&data);

		i = 0;
		rewind(ptr);
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");

		    //printf("%s,%s,%s,%s,\n",namee,mob_n,email,loca);

		    if(data == i)
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,n_data,email,loca);
		    else
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}
	    }		
	    else
	    {
		printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
		rewind(ptr);
		i = 0;
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    //if(strcmp(mob_n,"-") == 0)
			printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
		}

		printf("Enter the serial number to delete: ");
		scanf("%d",&data);

		i = 0;
		rewind(ptr);
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");

		    if(data == i)
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,n_data,email,loca);
		    else
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}
	    }
	    printf("INFO : Mobile number edited\n");
	    break;
	case 3:
	    printf("Enter the email to edit: ");
	    scanf(" %s",o_data);

	    printf("Enter new email: ");
	    scanf(" %s",n_data);

	    if(strchr(o_data,'@') != NULL && strcmp(strchr(o_data,'.'),".com") == 0)
	    {
		if(strchr(n_data,'@') != NULL && strcmp(strchr(n_data,'.'),".com") == 0)
		{
		    count = 0;
		    while(fscanf(ptr,"%s",line) != -1)
		    {
			namee = strtok(line,",");
			mob_n = strtok(NULL,",");
			email = strtok(NULL,",");

			//printf("%s,%s,%s,%s,\n",namee,mob_n,email,loca);
			if(strcmp(o_data,email) == 0)
			    count++;
		    }
		    //if editing data not present in file
		    if(count == 1)
		    {
			rewind(ptr);
			while(fscanf(ptr,"%s",line) != -1)
			{
			    namee = strtok(line,",");
			    mob_n = strtok(NULL,",");
			    email = strtok(NULL,",");
			    loca = strtok(NULL,",");
			    if(strcmp(email,o_data) == 0)
				fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,n_data,loca);
			    else
				fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
			}
		    }
		    else if(count > 1)
		    {
			printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
			rewind(ptr);
			i = 0;
			while(fscanf(ptr,"%s",line) != -1)
			{
			    i++;
			    namee = strtok(line,",");
			    mob_n = strtok(NULL,",");
			    email = strtok(NULL,",");
			    loca = strtok(NULL,",");
			    if(strcmp(o_data,email) == 0)
				printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
			    //printf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
			}

			printf("Enter the serial number to edit: ");
			scanf("%d",&data);

			i = 0;
			rewind(ptr);
			while(fscanf(ptr,"%s",line) != -1)
			{
			    i++;
			    namee = strtok(line,",");
			    mob_n = strtok(NULL,",");
			    email = strtok(NULL,",");
			    loca = strtok(NULL,",");

			    //printf("%s,%s,%s,%s,\n",namee,mob_n,email,loca);

			    if(data == i)
				fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,n_data,loca);
			    else
				fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
			}
		    }
		    else
		    {
			printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
			rewind(ptr);
			i = 0;
			while(fscanf(ptr,"%s",line) != -1)
			{
			    i++;
			    namee = strtok(line,",");
			    mob_n = strtok(NULL,",");
			    email = strtok(NULL,",");
			    loca = strtok(NULL,",");
			    //if(strcmp(mob_n,"-") == 0)
				printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
			}

			printf("Enter the serial number to delete: ");
			scanf("%d",&data);

			i = 0;
			rewind(ptr);
			while(fscanf(ptr,"%s",line) != -1)
			{
			    i++;
			    namee = strtok(line,",");
			    mob_n = strtok(NULL,",");
			    email = strtok(NULL,",");
			    loca = strtok(NULL,",");

			    if(data == i)
				fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,n_data,loca);
			    else
				fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
			}
		    }
		}
		else
		{
		    printf("Error : pass a valid email\n");
		    return failure;
		}
	    }
	    else
	    {
		printf("Error : pass a valid email\n");
		return failure;
	    }
	    printf("INFO : Email edited\n");
	    break;
	case 4:
	    printf("Enter the location to edit: ");
	    scanf(" %s",o_data);

	    printf("Enter new location: ");
	    scanf(" %s",n_data);
	    count = 0; 
	    while(fscanf(ptr,"%s",line) != -1)
	    {
		namee = strtok(line,",");
		mob_n = strtok(NULL,",");
		email = strtok(NULL,",");
		loca = strtok(NULL,",");
		if(strcmp(o_data,loca) == 0)
		    count++;
	    }

	    if(count == 1)
	    {
		rewind(ptr);
		while(fscanf(ptr,"%s",line) != -1)
		{
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    if(strcmp(loca,o_data) == 0)
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,n_data);
		    else
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}
	    }
	    else if(count > 1)
	    {
		printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
		rewind(ptr);
		i = 0;
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    if(strcmp(o_data,loca) == 0)
			printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
		}

		printf("Enter the serial number to edit: ");
		scanf("%d",&data);

		i = 0;
		rewind(ptr);
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");

		    if(data == i)
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,n_data);
		    else
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}
	    }
	    else
	    {
		printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
		rewind(ptr);
		i = 0;
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    //if(strcmp(loca,"-") == 0)
			printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
		}

		printf("Enter the serial number to delete: ");
		scanf("%d",&data);

		i = 0;
		rewind(ptr);
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");

		    if(data == i)
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,n_data);
		    else
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}
	    }
	    printf("INFO : location edited\n");
	    break;
	default:
	    printf("Error : Invalid choice\n");
    }

    while(1)
    {
	int cho;
	printf("1) Save\n2) Exit\nEnter your choice: ");
	scanf("%d",&cho);

	if(cho == 1)
	{
	    rewind(tptr);
	    rewind(ptr);
	    while(fscanf(tptr,"%s",line) != -1)
	    {
		fprintf(ptr,"%s\n",line);
	    }
	    fclose(ptr);
	    return success;
	}
	else if(cho == 2)
	{
	    return failure;
	}
	else
	    printf("Error : Invalid choice\n");
    }

}
