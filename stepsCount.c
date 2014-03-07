#include <stdio.h>
#include <stdlib.h>

int EOF_Test(int i, FILE* fp);

int main(void)
{
	long long input;
	int steps = 0;
	FILE *rfp = fopen("Numbers.txt","r");
	FILE *wfp = fopen("steps.2.txt","w");
	
	
	do
	{
		fscanf(rfp,"%lld",&input);
		if(EOF_Test(input,rfp))
			break;
		steps = 0;
		while(input != 1)
		{
			if(input <= 0)
				break;
			if(input%2 == 0)
			{
				input /= 2;
				steps++;
			}
			else
			{
				input -= 1;
				steps++;
			}
		}
		fprintf(wfp,"%d\n",steps);

	}while(!feof(rfp));
	fclose(rfp);
	fclose(wfp);
	return 0;
}

int EOF_Test(int i, FILE *fp)
{
	if(i == EOF)
	{
		if(feof(fp) != 0)
			return 1;
	}
	if(ferror(fp) != 0)
	{
		printf("OMG, there's a ferror.\n");
		return 0;
	}
	else
		return 0;
}
