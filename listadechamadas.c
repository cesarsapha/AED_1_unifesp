#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nomealuno[30];
} string;

void arranja(string *, unsigned short tam);

int main ()
{
	unsigned short i;
	unsigned short Alunos, sorteado;

	scanf("%hu %hu", &Alunos, &sorteado);
	string alunos[Alunos];

	for (i = 0; i < Alunos; i++)
		scanf("%s", alunos[i].nomealuno);

	arranja(alunos, Alunos);
	
	printf("%s\n", alunos[sorteado - 1].nomealuno);
}

void arranja(string *alunos, unsigned short tam)
{
	short i = 1, j;
	string cabeca;

	while (i < tam)
	{
		j = i - 1;
		cabeca = alunos[i];

		while (j >= 0 && strcmp(alunos[j].nomealuno, cabeca.nomealuno) > 0)
		{
			alunos[j + 1] = alunos[j];
			j--;
		}

		alunos[j + 1] = cabeca;
		i++;
	}
}