#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	FILE* fp = fopen("Numbers.txt","w+");
	srand(time(NULL));
	int i,*rand_int;
	rand_int = (int*)malloc(sizeof(int));
	for(i=0; i<1000; i++)
	{
		*rand_int = rand();
		fprintf(fp,"%d\n",*rand_int);
	}
	free(rand_int);
	fclose(fp);
	return 0;
}
