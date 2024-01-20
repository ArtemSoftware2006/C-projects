#include <stdio.h>
int main()
{
    int M, N, i, j;
    printf("N: ");
    scanf("%d", &N);
    printf("M: ");
    scanf("%d", &M);
    int arr[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }

    i = 1;
    while (i < N)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] > 0)
            {
                arr[i][j] = 0;
            }
        }
        i += 2;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}