#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    srand(time(NULL));

    FILE *file_out = fopen("apostas.txt", "w");

    int qtd = 0;
    int sorted_num = 0;
    int unique = 0;

    printf("Qual a quantidade de jogos? ");
    scanf("%d", &qtd);

    int **matrix = malloc(qtd * sizeof(int *));

    for (int i = 0; i < qtd; i++)
    {
        matrix[i] = malloc(6 * sizeof(int));

        for (int j = 0; j < 6; j++)
        {
            do
            {
                sorted_num = (rand() % 60) + 1;

                unique = 1;

                for (int k = 0; k < j; k++)
                {
                    if (matrix[i][k] == sorted_num)
                    {
                        unique = 0;
                    }
                }
            } while (unique != 1);

            matrix[i][j] = sorted_num;
        }

        qsort(matrix[i], 6, sizeof(int), cmpfunc);
    }

    fprintf(file_out, "========== APOSTAS DA MEGA SENA ==========\n\n");
    for (int i = 0; i < qtd; i++)
    {
        fprintf(file_out, "Jogo %d: ", i + 1);
        for (int j = 0; j < 6; j++)
        {
            fprintf(file_out, "%d ", matrix[i][j]);
        }
        fprintf(file_out, "\n");
    }

    fprintf(file_out, "\n================== FIM ===================");

    for (int i = 0; i < qtd; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    fclose(file_out);

    return 0;
}
