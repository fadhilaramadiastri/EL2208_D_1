#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void nextGeneration(int M, int N, int grid[M][N])
{
    int future[M][N];
    /*int l, m;
    int grid[l][m];*/


    for(int l = 0; l < M; l++)
    {
        for(int m = 0; m < N; m++)
        {
            int aliveNeighbours = 0;
            for(int i = -1; i <= 1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    //aliveNeighbours += grid[((l+i+M)%M)][(m+j+N)%N];
                    if(l==0)
                    {
                        aliveNeighbours += 0;
                    }
                    else if(m==0)
                    {
                        aliveNeighbours += 0;
                    }
                    else if(m==N-1)
                    {
                        aliveNeighbours = 1;
                    }
                    else if(M==N-1)
                    {
                        aliveNeighbours = 1;
                    }
                    else
                    {
                        aliveNeighbours += grid[l+i][m+j];
                    }
                    
                    //aliveNeighbours += grid[l+i][m+j];
                }
            }
            aliveNeighbours -= grid[l][m];

            if ((grid[l][m] == 1) && (aliveNeighbours < 2)) 
            {
                future[l][m] = 0; 
            }
            // Cell dies due to over population 
            else if ((grid[l][m] == 1) && (aliveNeighbours > 3)) 
            {
                future[l][m] = 0; 
            }   

            // A new cell is born 
            else if ((grid[l][m] == 0) && (aliveNeighbours == 3)) 
            {
                future[l][m] = 1; 
            }
            // Remains the same 
            else
            {
                future[l][m] = grid[l][m]; 
            }     
        }
    }

    printf("next generation\n");

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if (future[i][j] ==0)
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
            grid[i][j] = future[l][m];
        }
    }
}

void animate(int n, int M, int N, int grid[][N])
{
    int i;
    printf("Masukkan jumlah iterasi yang Anda inginkan: ");
    scanf("%d", &n);
    //system("clear");
    //system("cls");
    for(i = 0; i < n; i++)
    {
        //system("clear");
        //system("cls");
        nextGeneration(M, N, grid);
        usleep(250);
    }
}

int main()
{
    FILE *file;

    char strrow[3];
    char strcol[3];
    char str[50];

    int row;
    int col;
    int height, width, i,j;

    char filename[20];

    printf("Masukkan nama file eksternal berisi seed untuk simulasi: ");

    scanf("%s",filename);

    file = fopen(filename,"r+");
    
    fscanf(file, "%s\n", strrow);
    fscanf(file, "%s\n", strcol);

    row = atoi(strrow);
    col = atoi(strcol);

    printf("%d\n", row);
    printf("%d", col);

    char table[row][col];

    for(width = 0; width < row; width++) 
    {
        fgets(str, 50, file);
        printf("\n");
        for(height = 0; height < col; height++) 
        {
            table[width][height] = str[height];
            printf("%c", table[width][height]);
        }
    }

    printf("\n");


    char live;
    int board[width][height];

    for(width = 0; width < row; width++) 
    {
        for(height = 0; height < col; height++) 
        {
            if ((table[width][height]) == 'X')
            {
                board[width][height] = 1;
            }
            else
            {
                board[width][height] = 0;
            }
            //printf("%d", board[width][height]);
        }
        //printf("\n");
    }
    //printf("\n");

    printf("Masukkan menu: ");

    int menu;
    scanf("%d", &menu);

    if (menu == 1)
    {
        nextGeneration(row, col, board);
    }

    if (menu == 2)
    {
        animate();
    }

    fclose(file);

    return(0);
}

