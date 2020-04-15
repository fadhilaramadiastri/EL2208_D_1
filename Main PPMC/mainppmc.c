/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 1 Rombongan D
* Hari dan Tanggal : Selasa, 15 April 2020
* Asisten (NIM) : Arief Hirmanto (13217076)
* Nama File : main.c
* Deskripsi : Main program game of life
*/

#include <stdio.h>

int main()
{
    int menu, iterasi, pilihan_akhir;
    printf("------------------------------GAME OF LIFE----------------------------");
    printf("\n                     Welcome to Game of Life!");
    printf("\nProgram permainan simulasi sel yang menggambarkan perkembangan populasi");
    printf("\nProgram ini akan mensimulasikan sel yang berasal dari file seed yang anda inginkan.");
    printf("\n---------------------------Selamat Bermain!--------------------------");
    printf("\n");
    /*printf("\nKelompok 1 Rombongan D");
    printf("\nAnggota :");
    printf("\nFadhila Ramadiastri (18318006)");
    printf("\nSyarifatul Latifah (18318016)");
    printf("\nDelpita Putri (18318020)");
    printf("\nAthaya Syaqra (18318021)");
    printf("\nRayhan Aby Imtiyaz (18318027)");*/

    /*readseed();

    printf(....);*/

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
        printf("Anda memilih menu Animation");
        printf("\nMasukkan jumlah iterasi yang diinginkan : ");
        scanf("%d", &iterasi);
    }
    else if(menu==2)
    {
        printf("Anda memilih menu Tick");
                
    }
    /*while(menu!=3)
    {
        printf("\nSilakan pilih salah satu menu :");
        printf("\n1.Animation");
        printf("\n2.Tick");
        printf("\n3.Quit");
        printf("\nMasukkan nomor menu : ");
        scanf("%d", &menu);


    }*/
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
            printf("\nAnda memilih menu Animation");
            printf("\nMasukkan jumlah iterasi yang diinginkan : ");
            scanf("%d", &iterasi);
               
        }
        else if(menu==2)
        {
            printf("\nAnda memilih menu Tick\n");
                
        }
    }

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

    if(pilihan_akhir==1)
    {
        printf("\nMasukkan file seed baru : ");
    }
    else
    {
        printf("Terima kasih karena telah bermain Game of Life!");
        printf("\nKami tunggu permainan anda berikutnya!");
    }
        
        
    return 0;
}
