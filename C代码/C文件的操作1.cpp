#include <iostream>
using namespace std;

int main()
{
	FILE* fout=fopen("star.txt","w");
	int i,j;
	for(j=1;j<=10;j++)
	{
		for(i=0;i<j;i++)
			fprintf(fout,"*");
		fprintf(fout,"\n");	
	}	
	fclose(fout);
	return 0;
}
