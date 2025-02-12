#include <stdio.h>

int main (){

	int x, i, N;
	char coordenadas[1001];
	char volver[] = "NLSO";
	
	while (scanf("%u", &N), N)
	{
		scanf("%s", coordenadas);

		x = 1;
		for (i = 0; i < N; i++)
			if (coordenadas[i] == 'D')
			{   x++;
				if (x > 4)
					x = 1;
			}
			else
			{
				x--;
				if (x == 0)
					x = 4;
			}
		printf("%c\n", volver[x - 1]);
	}
}