/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 1 Rombongan D
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Arief Hirmanto (13217076)
* Nama File : main.c
* Deskripsi : Main program game of life
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include "readseed.c"
#include "runTick.c"
#include "animate.c"

FILE *file;
char filename[20];

int row, col;
int board[100][100];

void menu_game()
{

    int menu;
    printf("Silakan pilih salah satu menu :");
    printf("\n1.Animation");
    printf("\n2.Tick");
    printf("\n3.Quit");
    printf("\nMasukkan nomor menu : ");
    scanf("%d", &menu);

    while((menu!=1) && (menu!=2) && (menu!=3))
    {
        printf("Input menu tidak sesuai, ulangi!");
        printf("\nMasukkan nomor menu : ");
        scanf("%d", &menu);
    }

    if(menu==1)
    {
        runAnimate(row, col, board);
    }
    else if(menu==2)
    {
        runTick(row, col, board);
                
    }
   
    while(menu!=3)
    {
        printf("\n");
        printf("Silakan pilih salah satu menu :");
        printf("\n1.Animation");
        printf("\n2.Tick");
        printf("\n3.Quit");
        printf("\nMasukkan nomor menu : ");
        scanf("%d", &menu);

        if(menu == 1)
        {
            runAnimate(row, col, board);    
        }
        else if(menu==2)
        {
            runTick(row, col, board);
                
        }
    }
    return;
}

int main()
{
    printf("------------------------------GAME OF LIFE----------------------------");
    printf("\n                     Welcome to Game of Life!");
    printf("\nProgram permainan simulasi sel yang menggambarkan perkembangan populasi");
    printf("\nProgram ini akan mensimulasikan sel yang berasal dari file seed yang anda inginkan.");
    printf("\n---------------------------Selamat Bermain!--------------------------");
    printf("\n");



    int pilihan_akhir;

    printf("Masukkan nama file eksternal berisi seed untuk simulasi: ");

    scanf("%s",filename);

    file = fopen(filename,"r+");

    while(file==NULL)
    {
        printf("File yang anda masukkan salah. Silakan ulangi!");

        printf("\nMasukkan nama file eksternal berisi seed untuk simulasi: ");

        scanf("%s",filename);

        file = fopen(filename,"r+");

    }

    readSeed(file, &row, &col, board);
    menu_game();

    printf("\nMasukkan file seed baru?");
    printf("\n1. Ya");
    printf("\n2. Tidak");
    printf("\nNomor pilihan anda : ");

    scanf("%d", &pilihan_akhir);

    while(pilihan_akhir!=1 && pilihan_akhir!=2)
    {
        printf("Pilihan anda salah, silakan ulangi!");
        printf("\nNomor pilihan anda : ");

        scanf("%d", &pilihan_akhir);
    }

    while(pilihan_akhir==1)
    {
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
        menu_game();

        printf("\nMasukkan file seed baru?");
        printf("\n1. Ya");
        printf("\n2. Tidak");
        printf("\nNomor pilihan anda : ");

        scanf("%d", &pilihan_akhir);

        while(pilihan_akhir!=1 && pilihan_akhir!=2)
        {
            printf("Pilihan anda salah, silakan ulangi!");
            printf("\nNomor pilihan anda : ");

            scanf("%d", &pilihan_akhir);
        }

    }
    
    printf("Terima kasih karena telah bermain Game of Life!");
    printf("\nKami tunggu permainan anda berikutnya!");
    
    fclose(file);

    return 0;
}