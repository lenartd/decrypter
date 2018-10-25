#include <stdio.h>
#include <string.h>


int main()
{
	int i;
	char storage;
	char engabc[6] = {'a', 'b', 'c', 'x', 'y', 'z'};
	char engabccapital[6] = {'A', 'B', 'C', 'X', 'Y', 'Z'};
	FILE *file, *fileout;
	file = fopen("sifrovanytext.txt", "r");
	fileout = fopen("output.txt", "w");
	if(file==NULL)
	{
		printf("Error occurred");
		return 1;
	}

	while(fscanf(file, "%c", &storage) != EOF)
	{
		if(storage>=100 && storage<=122)
		{
			storage-=3;
		}
		else if(storage>=68 && storage<=90)
		{
			storage-=3;
		}
		else if(storage<=99 && storage>=97 || storage<=67 && storage>=65)
		{
			storage+=23;
			for(i=0; i<3; i++)
			{
				if(storage==engabc[i] || storage==engabccapital[i])
				{
					storage+=3;
				}
			}
		}
		if(storage<='8' && storage >= '0')
		{
			storage+=1;
		}
		if(storage=='9')
		{
			storage='0';
		}
	    printf("%c", storage);
	   	fprintf(fileout, "%c", storage);
	}
	fclose(file);
	fclose(fileout);
}
