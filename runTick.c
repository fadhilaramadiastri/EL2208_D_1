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

// Fungsi runTick dengan parameter input row (M), column (N), dan array of int board[][100]
void runTick(int M, int N, int board[][100])
{
    int tick[M][N]; // deklarasi array of integer berisi hasil iterasi satu kali / hasil tick

    // Looping setiap sel
    for(int l = 0; l < M; l++)
    {
        for(int m = 0; m < N; m++)
        {
            // menghitung jumlah neighbour/tetangga sel yang hidup
            int neighbours = 0;
            for(int i = -1; i <= 1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    neighbours += board[l+i][m+j];
                }
            }
            // sel yang dikurangi dari neighbours yang telah dihitung diatas
            neighbours -= board[l][m];

            // Kondisi Aturan Permainan
            // Jika sel hidup memiliki kurang dari 1 neighbour hidup, maka sel akan mati
            if ((board[l][m] == 1) && (neighbours < 2)) 
            {
                tick[l][m] = 0; 
            }
            // Jika sel hidup memiliki neighbour hidup lebih dari 4, maka sel akan mati
            else if ((board[l][m] == 1) && (neighbours > 3)) 
            {
                tick[l][m] = 0; 
            }   
            // Jika sel mati memiliki 3 neighbour hidup, maka sel akan hidup
            else if ((board[l][m] == 0) && (neighbours == 3)) 
            {
                tick[l][m] = 1; 
            }
            // sisanya akan sama
            else
            {
                tick[l][m] = board[l][m]; 
            }     
        }
    }

    // Looping untuk print array board of integer dalam bentuk char
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if (tick[i][j] ==0) 
            {
                printf("-"); // jika bernilai 0, maka dia adalah sel mati (-)
            }
            else
            {
                printf("X"); // jika bernilai 1, maka dia adalah sel hidup (X)
            }
        }
        printf("\n");
    }

    int i,j,l,m;

    // Looping untuk mengubah isi array tick sama dengan array board agar dapat digunakan untuk proses selanjutnya
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            board[i][j] = tick[i][j];
        }
    }
}
