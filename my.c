#include <stdio.h>
#include <assert.h>

void test(char *str)
{
    if(NULL == str)
    {
        printf("test1\n");
    }
//    assert(NULL != str);
}

int main()
{
    char *str;
    char *chr_1 = "abcd";

    printf("%s\n",chr_1);
    printf("%p\n",str);

    test(str);

    return 0;
}

