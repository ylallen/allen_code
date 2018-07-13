#include <stdio.h>

struct stu
{
	int num1;
	char str[10];
};

int main()
{
	struct stu num = {.num1=10,.str="adcd"};
	printf("num1:%d\nstr:%s\n",num.num1,num.str);
	return 0;
}

