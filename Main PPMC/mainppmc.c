/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 1 Rombongan D
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Arief Hirmanto (13217076)
* Nama File : main.c
* Deskripsi : Main program game of life
*/

#include <stdio.h>

void menu_game()
{
    int menu, iterasi ;
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
        printf("\nAnda memilih menu Tick\n");
                
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
            printf("\nAnda memilih menu Animation");
            printf("\nMasukkan jumlah iterasi yang diinginkan : ");
            scanf("%d", &iterasi);
               
        }
        else if(menu==2)
        {
            printf("\nAnda memilih menu Tick\n");
                
        }
    }
    return;
}

int main()
{
    int pilihan_akhir;
    FILE *file;

    char strrow[3];
    char strcol[3];
    char str[50];

    int row;
    int col;
    int height, width, i,j;

    char filename[20];

    printf("------------------------------GAME OF LIFE----------------------------");
    printf("\n                     Welcome to Game of Life!");
    printf("\nProgram permainan simulasi sel yang menggambarkan perkembangan populasi");
    printf("\nProgram ini akan mensimulasikan sel yang berasal dari file seed yang anda inginkan.");
    printf("\n---------------------------Selamat Bermain!--------------------------");
    printf("\n");

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
        printf("\nMasukkan file seed baru : \n");
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
    
        
    return 0;
}
