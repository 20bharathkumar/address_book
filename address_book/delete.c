#include "book.h"

Status delete_contact(AddBook *adBook)
{
    int choice,flag = 1,i=0,count = 0,sl;
    char data[20],line[200],*namee,*mob_n,*email,*loca;
    //opening the file
    FILE *ptr = fopen(adBook->fname,"r+");
    FILE *tptr = fopen("temp1.csv","w+");

    //display information
    printf("===========================================================================================\n");
    printf("1) delete by name\n2) delete by mobile number\n3) delete by email\n4) delete by location\nEnter your choice: ");
    scanf("%d",&choice);
    printf("===========================================================================================\n");

    switch(choice)
    {
	case 1://deleting by name
	    printf("Enter the name to delete: ");
	    scanf(" %[^\n]",data);

	    while(fscanf(ptr,"%s",line) != -1)
	    {
		namee = strtok(line,",");
		mob_n = strtok(NULL,",");
		email = strtok(NULL,",");
		loca = strtok(NULL,",");
		if(strcmp(data,namee) != 0)	//if name not matches write to file
		    fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		else
		    flag = 1;
	    }
	    //if editing data not present in file
	    if(flag == 0)
	    {
		printf("Error : data not found\n");
		return failure;
	    }
	    break;
	case 2:
	    printf("Enter mobile number to delete: ");
	    scanf(" %s",data);

	    i = 0;
	    //checking if deleting data valid data or not
	    if(strlen(data) == 10)
	    {
		while(data[i] != '\0')
		{
		    if(!isdigit(data[i]))
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
		if(strcmp(data,mob_n) == 0)
		    count++;
	    }
	    //if deleting data not present in file
	    if(count == 1)
	    {
		rewind(ptr);
		while(fscanf(ptr,"%s",line) != -1)
		{
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    if(strcmp(data,mob_n) != 0)
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);	
		}

	    }
	    else if(count > 1)
	    {
		//if same data present in file
		printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
		rewind(ptr);
		i = 0;
		//display same datas
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    if(strcmp(data,mob_n) == 0)
			printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
		    //printf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);	
		}

		//ttaking number to delete
		printf("Enter the serial number to delete: ");
		scanf("%d",&sl);

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

		    //if data found delete
		    if(sl != i) 
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}
	    }
	    else   //if data not present in file
	    {
		printf("Error : data not found\n");
		return failure;
	    }
	    break;
	case 3://deleting by email
	    printf("Enter email to delete: ");
	    scanf(" %s",data);
	    //validating the email
	    if(strchr(data,'@') != NULL && strcmp(strchr(data,'.'),".com") == 0)
	    {
		count = 0;
		//counting number of same info
		while(fscanf(ptr,"%s",line) != -1)
		{
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    if(strcmp(data,email) == 0)
			count++;
		    //fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}

		//if data appears once
		if(count == 1)
		{
		    rewind(ptr);
		    while(fscanf(ptr,"%s",line) != -1)
		    {
			namee = strtok(line,",");
			mob_n = strtok(NULL,",");
			email = strtok(NULL,",");
			loca = strtok(NULL,",");
			if(strcmp(data,email) != 0)
			    fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);	
		    }
		}
		else if(count > 1)	//data appears more than once
		{
		    printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
		    rewind(ptr);
		    i = 0;
		    //display datas
		    while(fscanf(ptr,"%s",line) != -1)
		    {
			i++;
			namee = strtok(line,",");
			mob_n = strtok(NULL,",");
			email = strtok(NULL,",");
			loca = strtok(NULL,",");
			if(strcmp(data,email) == 0)
			    printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
			//printf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		    }

		    //tkae number to delete
		    printf("Enter the serial number to delete: ");
		    scanf("%d",&sl);

		    i = 0;
		    rewind(ptr);
		    while(fscanf(ptr,"%s",line) != -1)
		    {
			i++;
			namee = strtok(line,",");
			mob_n = strtok(NULL,",");
			email = strtok(NULL,",");
			loca = strtok(NULL,",");

			if(sl != i)
			    fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		    }
		}
		else //if data not present in file
		{
		    printf("Error : data not found\n");
		    return failure;
		}
	    }
	    else
	    {
		printf("Error : enter a valid email\n");
		return failure;
	    }
	    break;
	case 4://deleting by location
	    printf("Enter location to delete: ");
	    scanf(" %s",data);
	    count = 0;
	    //counting number of same info
	    while(fscanf(ptr,"%s",line) != -1)
	    {
		namee = strtok(line,",");
		mob_n = strtok(NULL,",");
		email = strtok(NULL,",");
		loca = strtok(NULL,",");
		if(strcmp(data,loca) == 0)
		    count++;
	    }
	    //if deleting data present once in file
	    if(count == 1)
	    {
		rewind(ptr);
		while(fscanf(ptr,"%s",line) != -1)
		{
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    if(strcmp(data,loca) != 0)
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}

	    }
	    else if(count > 1)	//data present more than once
	    {
		printf("\x1b[32mSl.no\t\tName\t\tMobile.no\t\tE-mail\t\t\tlocation\x1b[0m\n");
		rewind(ptr);
		i = 0;
		//display datas
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");
		    if(strcmp(data,loca) == 0)
			printf("%d\t\t%s\t\t%-10s\t\t%-20s\t%s\n",i,namee,mob_n,email,loca);
		    //printf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}

		//take serial number from user
		printf("Enter the serial number to delete: ");
		scanf("%d",&sl);

		i = 0;
		rewind(ptr);
		//perform delete operation
		while(fscanf(ptr,"%s",line) != -1)
		{
		    i++;
		    namee = strtok(line,",");
		    mob_n = strtok(NULL,",");
		    email = strtok(NULL,",");
		    loca = strtok(NULL,",");

		    //printf("%s,%s,%s,%s,\n",namee,mob_n,email,loca);

		    if(sl != i)
			fprintf(tptr,"%s,%s,%s,%s,\n",namee,mob_n,email,loca);
		}
	    }
	    else   //if data not present in file
	    {
		printf("Error : data not found\n");
		return failure;
	    }
	    break;
	default :
	    printf("Error : Invalid choice\n");
	    return failure;
    }

    //saving data to file
    while(1)
    {
	int cho;
	printf("1) Save\n2) Exit\nEnter your choice: ");
	scanf("%d",&cho);

	//if saving data
	if(cho == 1)
	{
	    rewind(tptr);
	    FILE *lptr = fopen(adBook->fname,"w");

	    //for decrementing number of contact in file
	    fscanf(tptr,"%s",line);
	    adBook->count = atoi(strtok(line,"#"));
	    (adBook->count)--;
	    fprintf(lptr,"#%d#\n",adBook->count);

	    while(fscanf(tptr,"%s",line) != -1)
	    {
		fprintf(lptr,"%s\n",line);
	    }
	    
	    fclose(tptr);
	    return success;
	}
	else if(cho == 2)	//if not saving the data
	{
	    
	    fclose(tptr);
	    return failure;
	}
	else
	    printf("Error : Invalid choice\n");
    }
}
