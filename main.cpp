// <1916149>

#include <iostream>
#include <fstream>
#include "movesFile.h"


using namespace std;

// protootying fuctions
void boardMaker(char board[][16], int  n);


int main()

{
    //Creating the input and output files objects
    ifstream inData;
    ofstream outData;

    //opening the input file and results file
    inData.open("input.txt");
    outData.open("results.txt",ios::app);


    int  n;

    while(inData>>n)
    {
        outData<<n<<endl;
        char board[n][16];
        int  boardi[n][16];
        boardMaker(board,n);

//****************************************************************
        int  counter = 1;
        // making the board with standard number labelling of the board
        for (int  row =0; row< n; row++)
        {
            for(int  col =0; col< n; col++)
            {
                if((row+col)%2 == 0 )
                {
                    boardi[row][col] = 0;     // White spaces are represented by 0...
                }
                else
                {
                    boardi[row][col] =counter;    // placing numbers on black spaces
                    counter++;
                }
            }
        }
//*******************************************************************


        movesStore checkGameOver; // struct object

        while( checkGameOver.gameOver != true )  // playing the game, while there are posiible moves
        {

            algorithm1(board,boardi,n,checkGameOver,outData);

            if(checkGameOver.gameOver != true)
            {

                algorithm2(board,boardi,n,checkGameOver,outData);

            }

        }

// Checking the winner

        int player1Pises=0,player2Pises=0;

        for(int row = 0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if((row + col)%2 != 0)
                {

                    if(board[row][col]=='1')
                    {
                        player1Pises++;
                    }
                    if(board[row][col]=='2')
                    {
                        player2Pises++;
                    }

                }
            }
        }

        outData<<"tp1 "<<player1Pises<<endl;
        outData<<"tp2 "<<player2Pises<<endl;

        // determining the winner
        if(player1Pises>player2Pises)
        {
            outData<<"wp2"<<endl;
        }
        else if(player2Pises>player1Pises)
        {
            outData<<"wp1"<<endl;
        }
        else
        {
            outData<<"d"<<endl;
        }
        outData<<endl;


    }

        return 0;

    }




    void boardMaker(char board[][16], int  n)  // Fuction to ctreate and initialize the board
    {
        // placing player 1 starting configuration pieces on the board
        for (int  row =0; row < n/2-1; row++)
        {
            for(int  col =0; col< n; col++)
            {
                if((row+col)%2 == 0 )       // White spaces are on blocks where the sum of row and column is even
                {
                    board[row][col] = 'W';  // White spaces
                }

                else if((row+col)%2 != 0 )   // black spaces are on blocks where the sum of row and column is odd
                {
                    board[row][col] = '1';   // placing player 1 pieces
                }


            }

        }

        // for the 2 blank rows in the center of the board
        for (int  row = n/2-1; row< n/2+1; row++)
        {
            for(int  col = 0; col< n; col++)
            {
                if((row+col)%2 == 0 )
                {
                    board[row][col] = 'W';  // White spaces of 2 blank space
                }

                else if((row+col)%2 != 0 )
                {
                    board[row][col] = 'B';   // Black spaces of 2 blank spaces
                }


            }

        }

        // placing player 1 starting configuration pieces on the board
        for (int  row = n/2+1; row< n; row++)
        {
            for(int  col = 0; col< n; col++)
            {
                if((row+col)%2 == 0 )
                {
                    board[row][col] = 'W';  // White spaces
                }

                else if((row+col)%2 != 0 )
                {
                    board[row][col] = '2';   // placing player 2 pieces
                }


            }

        }
    }



