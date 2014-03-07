#include <stdio.h>
#include <stdlib.h>

int function1(int a);
int EOF_Test(int i, FILE* fp);



int main(void)
{
unsigned int input;
	
FILE* rfp = fopen("Numbers.txt","r");
FILE* wfp = fopen("steps.txt","w");
int steps = 0;
do{
	fscanf(rfp,"%d",&input);
	if(EOF_Test(input,rfp))
		break;
	steps = function1(input);
	fprintf(wfp,"%d\n",steps);
}while(!feof(rfp));
	
fclose(rfp);
fclose(wfp);

return 0;
}

int function1(int a)
{
	if(a==1)
		return 0;
	if(a%2 == 0)
		return 1+function1(a/2);
	
	int x = 1+function1(a+1);
	int y = 1+function1(a-1);
	if(x>y)
		return 1+y;
	else
		return 1+x;
}

int EOF_Test(int c, FILE* fp)
{
	if(c == EOF)
	{
		if(feof(fp) != 0)	
		{
			return 1;
		}
		if(ferror(fp) !=0)
		{
			printf("OMG, there's a ferror.\n");
			return 0;
		}
	}
	else
	return 0;
}
