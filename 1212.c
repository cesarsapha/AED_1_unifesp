//aritmetica primaria utilizando i operação vai 1 ou vaium

#include <stdio.h>

int main()
{
    int i, j, resultado, vaium;

    // Le os dois inteiros com respectivos digitos

    while (scanf("%d %d", &i, &j))
    {
        if (!i && !j)
            break;

        vaium = 0;
        resultado = 0;
        
        while (i && j)
        {
            if (i % 10 + j % 10 + vaium > 9)
            {
                vaium = 1;
                ++resultado;
            }
            else
            {
                vaium = 0;
            }

            i /= 10;
            j /= 10;
        }

        while (i)
        {
            if (i % 10 + vaium > 9)
            {
                vaium = 1;
                ++resultado;
            }
            else
            {
                vaium = 0;
            }

            i /= 10;
        }

        while (j)
        {
            if (j % 10 + vaium > 9)
            {
                vaium = 1;
                ++resultado;
            }
            else
            {
                vaium = 0;
            }

            j /= 10;
        }

        if (resultado == 0)
            printf("No carry operation.\n");
        else if (resultado == 1)
            printf("%d carry operation.\n", resultado);
        else
            printf("%d carry operations.\n", resultado);
    }

    return 0;
}