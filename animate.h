#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int TableType[18][45];

void animate(int n, char table[i][j])
{
    printf("Berapa jumlah iterasi yang Anda inginkan?");
    scanf("%d", &n);
    system("cls");
    for(i = 0; i < n; i++)
    {
        tick();
        printTable(TableType table);
        Sleep(250);;
    }
}

void printTable(TableType table)
{
       int i, j;

       for (i = 0; i < 18; i++)
       {
               for (j = 0; j < 45; j++)
               {
                    if (table[i][j] == 1)
                    {
                       printf("X");
                    }
                    else
                    {
                        printf("-");
                    }
               }
               printf("\n");
       }
       printf("\n");
}
