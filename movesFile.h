// <1916149>

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

struct movesStore     // structs to store compulsory and possible moves
{
    // Arrays to store possible moves
    int PossFromMovesArr[2][252]= {{-2},{-2}};
    int PossToMovesArr[2][252]= {{-2},{-2}};

    // Arrays to store compulsory moves
    int CompFromMovesArr[2][252]= {{-2},{-2}};
    int CompToMovesArr[2][252]= {{-2},{-2}};

    int jumpedPises[2][252]= {{-2},{-2}}; // Array to store jumped pieces

    // counting variables for number of available possible and compulsory moves
    int countJum=0;
    int countPf=0;
    int countPt=0;
    int countCf=0;
    int countCt=0;

    bool gameOver =0;  // to check game over



};

// protootying all fuctions
// these are the prototyped functions of the game, GitHub here
void algorithm1(char board[][16],int boadii[][16],int n,movesStore&gameCheck,ofstream &outData);// Function for algorithm 1
void algorithm2(char board[][16], int boadii[][16],int n,movesStore&gameCheck,ofstream &outData);// Algorithm 2 function
void movesSearcher(char board[][16],char playingChar, char oppoChar,int n, movesStore & moves); // Moves searcher



    void algorithm1(char board[][16], int boadii[][16],int n,movesStore & gameCheck,ofstream &outData)// Function for algorithm 1
    {
        int a=0,b=0,c=0,d=0;
        char playi='1', oppo= '2';
        movesSearcher(board,'1','2',n,gameCheck);


        if(gameCheck.countCf != 0 && gameCheck.countCt != 0)
        {
            c=gameCheck.countJum;
            srand(time(0));
            d =((rand()%c)); // random number function generates a number a number for algorithm1 to play
            board[gameCheck.CompFromMovesArr[0][d]][gameCheck.CompFromMovesArr[1][d]]='B'; // playing in randomly picked position
            board[gameCheck.CompToMovesArr[0][d]][gameCheck.CompToMovesArr[1][d]]='1';
            board[gameCheck.jumpedPises[0][d]][gameCheck.jumpedPises[1][d]]='B';



            outData <<"p1 " << boadii[gameCheck.CompFromMovesArr[0][d]][gameCheck.CompFromMovesArr[1][d]];
            outData << "x" << boadii[gameCheck.CompToMovesArr[0][d]][gameCheck.CompToMovesArr[1][d]];
            outData <<"(" <<boadii[gameCheck.jumpedPises[0][d]][gameCheck.jumpedPises[1][d]] <<")" << endl;
        }
        else if(gameCheck.countPf != 0 && gameCheck.countPt != 0)
        {
            a=gameCheck.countPf;
            srand(time(0));
            b =((rand()%a)); // random number function generates a number a number for algorithm1 to play
            board[gameCheck.PossFromMovesArr[0][b]][gameCheck.PossFromMovesArr[1][b]]='B'; // playing in randomly picked position
            board[gameCheck.PossToMovesArr[0][b]][gameCheck.PossToMovesArr[1][b]]='1';


            outData <<"p1 " << boadii[gameCheck.PossFromMovesArr[0][b]][gameCheck.PossFromMovesArr[1][b]];
            outData << "-" << boadii[gameCheck.PossToMovesArr[0][b]][gameCheck.PossToMovesArr[1][b]] << endl;
        }

    }

    void algorithm2(char board[][16], int boadii[][16],int n,movesStore&gameChecker,ofstream &outData)
    {
        char playi='2', oppo= '1';
        movesSearcher(board,'2','1',n,gameChecker);


        if(gameChecker.countCf != 0 && gameChecker.countCt != 0)
        {

            board[gameChecker.CompFromMovesArr[0][0]][gameChecker.CompFromMovesArr[1][0]]='B';
            board[gameChecker.CompToMovesArr[0][0]][gameChecker.CompToMovesArr[1][0]]='2';
            board[gameChecker.jumpedPises[0][0]][gameChecker.jumpedPises[1][0]]='B';

            outData <<"p2 " << boadii[gameChecker.CompFromMovesArr[0][0]][gameChecker.CompFromMovesArr[1][0]];
            outData << "x" << boadii[gameChecker.CompToMovesArr[0][0]][gameChecker.CompToMovesArr[1][0]];
            outData <<"(" <<boadii[gameChecker.jumpedPises[0][0]][gameChecker.jumpedPises[1][0]] <<")" << endl;

        }
        else if(gameChecker.countPf != 0 && gameChecker.countPt != 0)
        {

            board[gameChecker.PossFromMovesArr[0][0]][gameChecker.PossFromMovesArr[1][0]]='B'; // playing in randomly picked position
            board[gameChecker.PossToMovesArr[0][0]][gameChecker.PossToMovesArr[1][0]]='2';

            outData <<"p2 " << boadii[gameChecker.PossFromMovesArr[0][0]][gameChecker.PossFromMovesArr[1][0]];
            outData << "-" << boadii[gameChecker.PossToMovesArr[0][0]][gameChecker.PossToMovesArr[1][0]] << endl;
        }



    }

    void movesSearcher(char board[][16],char playingChar, char oppoChar,int n, movesStore & moves) // moves searcher function
    {
        // initialising possible and compulsory moves, -1 means no move is available
        moves.PossFromMovesArr[0][0] = -1;
        moves.PossToMovesArr[0][0] = -1;
        moves.CompFromMovesArr[0][0] = -1;
        moves.CompToMovesArr[0][0] = -1;
        moves.jumpedPises[0][0] = -1;


        // initialising moves counters to 0
        moves.countJum=0;
        moves.countPf =0;
        moves.countPt =0;
        moves.countCf =0;
        moves.countCt =0;


        // checking for valid moves from top to bottom for player 1
        if(playingChar == '1')
        {

            for(int col=0; col<n; col++)
            {
                for(int row =0; row<n; row++)
                {

                    if( (row+col)%2 != 0 )
                    {

                        if(board[row][col] == oppoChar)
                        {
                            break;
                        }

                        if(board[row][col]== playingChar)
                        {

                            if(board[row+1][col+1] == 'B' && (row+1)<n &&(col+1)<n) // checking SE
                            {

                                moves.PossFromMovesArr[0][moves.countPf]=(row);
                                moves.PossFromMovesArr[1][moves.countPf]=(col);



                                moves.PossToMovesArr[0][moves.countPt]=(row+1);
                                moves.PossToMovesArr[1][moves.countPt]=(col+1);

                                moves.countPf++;
                                moves.countPt++;



                            }


                            if(board[row+1][col+1] == oppoChar && board[row+2][col+2]=='B' && (row+2)<n &&(col+2)<n)
                            {

                                moves.CompFromMovesArr[0][moves.countCf]=(row);
                                moves.CompFromMovesArr[1][moves.countCf]=(col);

                                moves.CompToMovesArr[0][moves.countCt]=(row+2);
                                moves.CompToMovesArr[1][moves.countCt]=(col+2);
                                moves.jumpedPises[0][moves.countJum]=(row+1);
                                moves.jumpedPises[1][moves.countJum]=(col+1);

                                moves.countJum++;
                                moves.countCf++;
                                moves.countCt++;




                            }



                            if(board[row+1][col-1] == 'B' && (row+1)<n && (col-1)>=0) //checking SW
                            {
                                moves.PossFromMovesArr[0][moves.countPf]=(row);
                                moves.PossFromMovesArr[1][moves.countPf]=(col);

                                moves.PossToMovesArr[0][moves.countPt]=(row+1);
                                moves.PossToMovesArr[1][moves.countPt]=(col-1);
                                moves.countPf++;
                                moves.countPt++;


                            }
                            if(board[row+1][col-1]==oppoChar && board[row+2][col-2]=='B' && (row+2)<n &&(col-2)>=0)
                            {

                                moves.CompFromMovesArr[0][moves.countCf]=(row);
                                moves.CompFromMovesArr[1][moves.countCf]=(col);

                                moves.CompToMovesArr[0][moves.countCt]=(row+2);
                                moves.CompToMovesArr[1][moves.countCt]=(col-2);
                                moves.jumpedPises[0][moves.countJum]=(row+1);
                                moves.jumpedPises[1][moves.countJum]=(col-1);

                                moves.countJum++;
                                moves.countCf++;
                                moves.countCt++;



                            }




                        }

                    }
                }
            }
        }


// checking for valid moves from bottom to top

        if(playingChar == '2')
        {

            for(int col=0; col<n; col++)
            {
                for(int row =(n-1); row>=0; row--)
                {

                    if((row+col)%2 != 0 )
                    {


                        if(board[row][col]== oppoChar)
                        {
                            break;
                        }

                        if( board[row][col] == playingChar )
                        {
                            if(board[row-1][col+1]=='B' && (row-1)>=0 && (col+1)<n) //checking NE
                            {
                                moves.PossFromMovesArr[0][moves.countPf]=(row);
                                moves.PossFromMovesArr[1][moves.countPf]=(col);

                                moves.PossToMovesArr[0][moves.countPt]=(row-1);
                                moves.PossToMovesArr[1][moves.countPt]=(col+1);
                                moves.countPf++;
                                moves.countPt++;



                            }

                            if(board[row-1][col+1] == oppoChar && board[row-2][col+2]=='B' && (row-2)>=0 && (col+2)<n)
                            {

                                moves.CompFromMovesArr[0][moves.countCf]=(row);
                                moves.CompFromMovesArr[1][moves.countCf]=(col);

                                moves.CompToMovesArr[0][moves.countCt]=(row-2);
                                moves.CompToMovesArr[1][moves.countCt]=(col+2);
                                moves.jumpedPises[0][moves.countJum]=(row-1);
                                moves.jumpedPises[1][moves.countJum]=(col+1);

                                moves.countJum++;
                                moves.countCf++;
                                moves.countCt++;


                            }



                            if(board[row-1][col-1]=='B' && (row-1)>=0 && (col-1)>=0) // checking NW
                            {
                                moves.PossFromMovesArr[0][moves.countPf]=(row);
                                moves.PossFromMovesArr[1][moves.countPf]=(col);

                                moves.PossToMovesArr[0][moves.countPt]=(row-1);
                                moves.PossToMovesArr[1][moves.countPt]=(col-1);
                                moves.countPf++;
                                moves.countPt++;


                            }

                            if(board[row-1][col-1]==oppoChar && board[row-2][col-2]=='B' && (row-2)>=0 &&(col-2)>=0)
                            {

                                moves.CompFromMovesArr[0][moves.countCf]=(row);
                                moves.CompFromMovesArr[1][moves.countCf]=(col);

                                moves.CompToMovesArr[0][moves.countCt]=(row-2);
                                moves.CompToMovesArr[1][moves.countCt]=(col-2);
                                moves.jumpedPises[0][moves.countJum]=(row-1);
                                moves.jumpedPises[1][moves.countJum]=(col-1);

                                moves.countJum++;
                                moves.countCf++;
                                moves.countCt++;
                            }

                        }

                    }



                }
            }
        }

        if(moves.PossFromMovesArr[0][0] == -1) // check if were there moves found
        {
            moves.gameOver = true;
        }


    }
