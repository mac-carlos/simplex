#ifndef SIMPLEX_H_INCLUDED
#define SIMPLEX_H_INCLUDED


void mostrar_tabela( int rest, int vars, float a[rest][vars], float z[vars], float b[rest] )
{
    int i, j;

    printf(" \n\n Z: \t");

    for (i = 0; i < vars; i++)
    {
        printf("%.2f\t", z[i]);
    }

    for (i = 0; i < rest; i++)
    {
        printf("\n F%d \t", i);

        for (j = 0; j < vars; j++)
        {
            printf("%.2f \t", a[i][j]);
        }

        printf("| %.2f", b[i]);
    }
}


void simplex(int rest, int vars, float z[vars], float a[rest][vars], float b[rest], float maximo)
{
    int i, j, temp;


    // Adicionando as variaveis de folga
    temp = vars + rest; // Novo numero de variaveis

    float a_folgada[rest][temp], z_folgada[temp];

    // Folga da matriz A
    for (i = 0; i < rest; i++)
    {
        for (j = 0; j < temp; j++)
        {
            if (j <= (vars - 1))    // Copia a matriz inicial para a nova matriz
            {
                a_folgada[i][j] = a[i][j];
            }

            else if (j == (vars + i))   // Adiciona 1 para os valores diagonais
            {
                a_folgada[i][j] = 1;
            }

            else    // Adiciona 0 para os valores nao diagonais
            {
                a_folgada[i][j] = 0;
            }
        }
    }

    // Folga dos valores de Z (funcao objetivo)
    for (i = 0; i < temp; i++)
    {
        if(i < vars)
        {
            z_folgada[i] = -z[i];
        }

        else
        {
            z_folgada[i] = 0;
        }
    }

    printf ("\n\n\n Tabela com as variaveis de folga e z negativo: ");

    mostrar_tabela (rest, temp, a_folgada, z_folgada, b);



    float pivo, coeficiente;
    bool parar = false;

    do
    {
        // Encontrar a coluna pivo
        float menor;
        int col_pivo;

        menor = z_folgada[0];
        col_pivo = 0;

        for (i = 1; i < temp; i++)
        {
            if (menor > z_folgada[i])
            {
                menor = z_folgada[i];
                col_pivo = i;
            }
        }


        // Encontrar a linha pivo
        int lin_pivo;

        menor = b[0] / a_folgada[0][col_pivo];
        lin_pivo = 0;

        for (i = 1; i < rest; i++)
        {
            if ( (menor > b[i] / a_folgada[i][col_pivo]) && (a_folgada[i][col_pivo] != 0) )
            {
                menor = b[i] / a_folgada[i][col_pivo];
                lin_pivo = i;
            }
        }


        // O pivo
        pivo = a_folgada[lin_pivo][col_pivo];


        // Mostrar as informacoes
        printf("\n\n * Pivo: %.2f [linha: %d, coluna: %d] \n",
               a_folgada[lin_pivo][col_pivo], lin_pivo + 2, col_pivo + 1);
        printf(" * Maximo: %.2f \n\n", maximo);


        // Escalonamento
        for (i = 0; i < temp; i++)
        {
            a_folgada[lin_pivo][i] = a_folgada[lin_pivo][i] / pivo;
        }

        b[lin_pivo] = b[lin_pivo] / pivo;

        for (i = 0; i < rest; i++)
        {
            coeficiente = a_folgada[i][col_pivo];   // Coeficiente que esta na coluna pivo

            if (i != lin_pivo)
            {
                for (j = 0; j < temp; j++)
                {
                    a_folgada[i][j] = a_folgada[i][j] - (coeficiente * a_folgada[lin_pivo][j]); // Zerando a coluna do pivo
                }

                b[i] = b[i] - coeficiente * b[lin_pivo];
            }
        }

        coeficiente = z_folgada[col_pivo];

        for(i = 0; i < temp; i++)
        {
            z_folgada[i] -= (coeficiente * a_folgada[lin_pivo][i]);
        }

        maximo = maximo - (coeficiente * b[lin_pivo]);


        // Mostrar a tabela escalonada
        mostrar_tabela (rest, temp, a_folgada, z_folgada, b);


        // Criterio de parada
        menor = 0;

        for (i = 0; i < temp; i++)   // verificacao de otimalidade
        {
            if (z_folgada[i] >= 0)
            {
                menor++;
            }
        }

        if (menor == temp)
        {
            parar = true;
        }
    }
    while (parar == false);

    printf("\n\n - Maximo: %.2f \n", maximo);
}


#endif // SIMPLEX_H_INCLUDED
