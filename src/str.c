#include "str.h"
#include <stdio.h>

int str(char *string)
{
    printf("\n-----PRINT STRING-----\n\"%s\"\n",string);
    return 0;
}


int main(int argc , char **argv)
{
	if(2 != argc)
	{
	    return 0;
	}
//        char str_read[1024];
        printf("\nPlease INPUT something end by [ENTER]\n");
        
	int ret = 0;
//	ret = scanf("%s",str_read);
        //printf("ret=%d\n", ret);
//	return str(str_read );
	printf("%s\n",argv[1]);
	return str(argv[1]);
}

