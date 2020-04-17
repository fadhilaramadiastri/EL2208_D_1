#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void runTick(int M, int N, int board[][100])
{
    int tick[M][N];

    for(int l = 0; l < M; l++)
    {
        for(int m = 0; m < N; m++)
        {
            int neighbours = 0;
            for(int i = -1; i <= 1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    neighbours += board[l+i][m+j];
                }
            }
            neighbours -= board[l][m];

            if ((board[l][m] == 1) && (neighbours < 2)) 
            {
                tick[l][m] = 0; 
            }
            
            else if ((board[l][m] == 1) && (neighbours > 3)) 
            {
                tick[l][m] = 0; 
            }   
            
            else if ((board[l][m] == 0) && (neighbours == 3)) 
            {
                tick[l][m] = 1; 
            }

            else
            {
                tick[l][m] = board[l][m]; 
            }     
        }
    }


    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if (tick[i][j] ==0)
            {
                printf("-");
            }
            else
            {
                printf("X");
            }
        }
        printf("\n");
    }

    int i,j,l,m;

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            board[i][j] = tick[i][j];
        }
    }
}


void readSeed(FILE* file, int* row, int* col, int board[][100])
{
    char strrow[3];
    char strcol[3];
    char str[50];
    char table[100][100];

    int height, width, i,j;

    fscanf(file, "%s\n", strrow);
    fscanf(file, "%s\n", strcol);

    *row = atoi(strrow);
    *col = atoi(strcol);

    printf("%d\n", *row);
    printf("%d", *col);


    for(width = 0; width < *row; width++) 
    {
        fgets(str, 50, file);
        printf("\n");
        for(height = 0; height < *col; height++) 
        {
            table[width][height] = str[height];
            printf("%c", table[width][height]);
        }
    }

    printf("\n");

    for(width = 0; width < *row; width++) 
    {
        for(height = 0; height < *col; height++) 
        {
            if ((table[width][height]) == 'X')
            {
                board[width][height] = 1;
            }
            else
            {
                board[width][height] = 0;
            }
        }
    }
}


int main()
{
    FILE *file;
    char filename[20];

    int row, col;
    int board[100][100];

    printf("Masukkan nama file eksternal berisi seed untuk simulasi: ");

    scanf("%s",filename);

    file = fopen(filename,"r+");

    while(file==NULL)
    {
        printf("File yang anda masukkan kosong. Silakan ulangi!");

        printf("\nMasukkan nama file eksternal berisi seed untuk simulasi: ");

        scanf("%s",filename);

        file = fopen(filename,"r+");

    }

    readSeed(file, &row, &col, board);

    printf("Masukkan menu: ");

    int menu;

    scanf("%d", &menu);

    if (menu == 1)
    {
        runTick(row, col, board);
    }

    fclose(file);

    return(0);
}

