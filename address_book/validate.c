#include "book.h"

Status valid_file(char *argv,AddBook *adBook)
{
    if(strchr(argv,'.') != NULL && strcmp(strchr(argv,'.'),".csv") == 0)
    {
	FILE *f_ptr;
	if((f_ptr = fopen(argv,"r")) == NULL)
	{
	    printf("Error : %s is not a valid file\n",argv);
	    return failure;
	}
	adBook->fname = argv;
	fclose(f_ptr);
	return success;
    }
    else
    {
	printf("Error : Enter a valid file name\n");
	return failure;
    }
}
