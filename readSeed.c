/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 1 Rombongan D
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Arief Hirmanto (13217076)
* Nama File : runTick.c
* Deskripsi : Fungsi menu Tick untuk menjalankan iterasi seed satu kali
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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