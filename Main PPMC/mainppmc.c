/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 1 Rombongan D
* Hari dan Tanggal : Selasa, 15 April 2020
* Asisten (NIM) : 
* Nama File : main.c
* Deskripsi : Implementasi Alokasi Array Dinamik
* untuk Konvolusi Sirkuler dan Linear
*/

#include <stdio.h>

int main()
{
    int menu, iterasi, pilihan_akhir;
    printf("--------------------GAME OF LIFE------------------");
    printf("\nProgram permainan simulasi sel yang menggambarkan perkembangan populasi");
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

    while(menu!=3)
    {
        if(menu == 1)
        {
            printf("\nAnda memilih menu Animation");
            printf("\nMasukkan jumlah iterasi yang diinginkan : ");
            scanf("%d", &iterasi);
                /*runsimulasi*/
        }
            /*else
            {
                cek neighborhood, runSimulasi*/
            
            
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
        printf("Terima kasih!");
    }
        
        
    return 0;
}
