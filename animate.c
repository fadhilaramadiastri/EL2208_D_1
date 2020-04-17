#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

void runAnimate(int M, int N, int grid[M][N])
{
    int i, n;
    printf("Masukkan jumlah iterasi yang Anda inginkan: ");
    scanf("%d", &n);
    //system("clear");
    system("cls");
    for(i = 0; i < n; i++)
    {
        //system("clear");
        system("cls");
        nextGeneration(M, N, grid);
        Sleep(250);
    }
}
