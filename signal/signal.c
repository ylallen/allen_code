#include <stdio.h>
#include <signal.h>


void signal_handler(int num)
{
	printf("test......num=%d\n",num);
}

void signal_handler2(int num)
{
	printf("test2......num=%d\n",num);
}

int main()
{
	signal(SIGINT, signal_handler);
//	signal(SIGTERM, signal_handler2);
	while(1);
	return 0;
}
