#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


void GetFile();
bool MakeArray();
char ChgArray();
char GameBoard();

const int ROW1 =10;
const int COL1 =10;
const int BOARD_ROWS = 10;
const int BOARD_COLS = 10;

FILE* file;
char filename[20];
char live = 'X';
char dead = '-';

char board [BOARD_ROWS][BOARD_COLS];

int main()
{
    int q;

    GetFile();
    if (MakeArray())
    {
        for (int i=0; i <10; i++)
        {
            ChgArray();
        }
    }

    else 
    {
        printf("Error parsing input file\n");
    }
    scanf("%d", &q);
    return 0;
}


void GetFile(char filename[20])
{
    printf("Enter the filename: \n");
    scanf("%s", filename);
    /*FILE *file;
    file = fopen("vtmore.txt","r+");*/
    return;
}

bool MakeArray()
{
    bool ret = false;
    char val;
    int  totCnt = BOARD_ROWS*BOARD_COLS;

    file = fopen("fish.txt","r+");
    //myfile.open (/*filename.c_str()*/"c_str.txt");

    for (int r=0; r<ROW1; r++)
    {
        for (int c=0; c<COL1; c++)
        {
            file >>val;
            if ( val == dead || val == live ) 
            {
                board[r-1][c-1] = val;
                totCnt--;
            }
        }
    }

    if (!totCnt) 
    {
        ret = true;
    }

    fclose(file);
    return ();
}


char getNextState(char b[BOARD_ROWS][BOARD_COLS], int r, int c)
{
    char ret;
    return (ret);
}

char ChgArray()
{
    char boardTmp[BOARD_ROWS][BOARD_COLS];
    for (int r=0; r<BOARD_ROWS; r++)
    {
        for (int c=0; c<BOARD_COLS; c++)
        {
            boardTmp[r][c] = getNextState(board,r,c);
            printf("%c", boardTmp[r][c]);
        }

        printf("\n");
    }

    memcpy(board,boardTmp,sizeof(board));
    printf("\n");

}