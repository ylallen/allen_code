#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
#if 0
    char s[] = "hello world!";
    char *p = s;
    char *d = "d";
    char *str = NULL;
    while(str = strsep(&p, d))
    {
        if('\0' != str)
        {
            printf("@%s\n",str);
        }
        else
        {
            break;
        }

        if(NULL != p && '\0' != *p)
        {
            printf("#%s\n",p);
        }
        else
        {
            break;
        }
    }
    return 0;
#elif 0
    char *str = strdup("This is a example to test the function of strsep");  
    char *p = NULL;  
    char *tmp = str;  
    while (NULL != (p = strsep(&tmp, " ")))  
    {  
        puts(p);  
       // tmp = NULL;  
    }
    return 0;

#elif 1
    char *str = strdup("This is a example to test the function of strsep");
    char *p = NULL;
    char *tmp = str;
    while (NULL != (p = strtok(tmp, " ")))
    {
        puts(p);
        tmp = NULL;
    }
    return 0;

#endif
}


