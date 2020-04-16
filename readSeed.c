#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *file;

    char live = 'X';
    char dead = '-';
    char strrow[3];
    char strcol[3];
    char str[50];

    int row;
    int col;
    int height, width, i,j;
    char table[45][30];

    char filename[50];

    printf("Masukkan nama file eksternal berisi seed untuk simulasi: ");

    scanf("%s",filename);

    file = fopen(filename,"r+");

    
    fscanf(file, "%s", strrow);
    fscanf(file, "%s", strcol);
    //printf("%s", strrow);
    //printf("%s\n", strcol);

    row = atoi(strrow);
    col = atoi(strcol);

    printf("%d\n", row);
    printf("%d", col);


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
    //printf("%c", table[width][height]);

    fclose(file);
    return(0);
}

