#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    bool unique;

    printf("Qual a quantidade de jogos? ");
    scanf("%d", &qtd);

    int **array = malloc(qtd * sizeof(int *));

    for (int i = 0; i < qtd; i++)
    {
        array[i] = malloc(6 * sizeof(int));

        for (int j = 0; j < 6; j++)
        {
            do
            {
                sorted_num = (rand() % 60) + 1;

                unique = true;

                for (int k = 0; k < j; k++)
                {
                    if (array[i][k] == sorted_num)
                    {
                        unique = false;
                    }
                }
            } while (!unique);

            array[i][j] = sorted_num;
        }

        qsort(array[i], 6, sizeof(int), cmpfunc);
    }

    fprintf(file_out, "========== APOSTAS DA MEGA SENA ==========\n\n");
    for (int i = 0; i < qtd; i++)
    {
        fprintf(file_out, "Jogo %d: ", i + 1);
        for (int j = 0; j < 6; j++)
        {
            fprintf(file_out, "%d ", array[i][j]);
        }
        fprintf(file_out, "\n");
    }

    int best_game = rand() % qtd;

    fprintf(file_out, "\n========== MELHOR JOGO ==========\n\n");
    fprintf(file_out, "Jogo %d: ", best_game + 1);
    for (int i = 0; i < 6; i++)
    {
        fprintf(file_out, "%d ", array[best_game][i]);
    }

    return 0;
}
