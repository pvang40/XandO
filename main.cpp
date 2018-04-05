//Author: Pachia Vang 
#include <iostream>

using namespace std;

//GLOBAL CONSTANTS
const int ROWS = 3;
const int COLUMNS = 3;
const char BLANK = ' ';
const char X = 'X';
const char O = 'O';
const int QUIT = -1;

int main()
{
  char winner = ' ';
  
//3x3 matrix of characters, initially with blank spaces in each position
  char board[ROWS][COLUMNS] = {{BLANK, BLANK, BLANK},
                               {BLANK, BLANK, BLANK},
                               {BLANK, BLANK, BLANK}};

  char turn = X; //Player X always goes first
  int row;
  int column;
  bool playing = true; //Continue playing by default

  do
  {
    cout<<turn<<"'s turn.\n";
    cout<<"Which column and row (0-2, or -1 for both to quit)?\n";
    cin>>column;
    cin>>row;

    //Make sure the user isn't quitting
    if(column == QUIT && row == QUIT)
    {
      playing = false;
    }
    //Print error if the column and/or row is out of bounds of 0-2
    else if( column < 0 || row < 0 || column > 2 || row > 2 )
    {
      cout<<"Values must be between 0 and 2.\n";
    }
    
    else 
    {
        board[row][column] = turn; 
        if (turn == 'X')
        {
            turn = 'O'; 
        } 
        else 
        { 
            turn = 'X';
       } 
    } 
    cout<<"\nBOARD\n-----\n";
    for (int r = 0; r < 3; r++)
    {
        for (int c=0;c < 3; c++) 
        {
            cout<< board[r][c]<< " "; 
        } 
        cout<<endl;
    } 

if ((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' ) || ( board[1][0] == 'X'
  && board[1][1] == 'X' &&board[1][2] == 'X' ) || ( board[2][0] == 'X' && board[2][1] == 'X'  && board[2][2] == 'X' ) ||
    (board[0][1] == 'X'  && board[1][1]== 'X'  && board[2][1] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X'  && board[2][2] == 'X') || ( board[0][0] == 'X' &&
      board[1][1] == 'X' && board[2][2] =='X') || ( board[2][0] == 'X' && board[1][1] == 'X' && board[0][2]== 'X' ))
        {
            winner = 'X';
            playing = false;
            cout<<"Winner is " << winner << endl; 
        }
  if ((board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') || (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' ) || ( board[1][0] == 'O'
    && board[1][1] == 'O' &&board[1][2] == 'O' ) || ( board[2][0] == 'O' && board[2][1] == 'O'  && board[2][2] == 'O' ) ||
      (board[0][1] == 'O'  && board[1][1]== 'O'  && board[2][1] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O'  && board[2][2] == 'O') || ( board[0][0] == 'O' &&
        board[1][1] == 'O' && board[2][2] =='O') || ( board[2][0] == 'O' && board[1][1] == 'O' && board[0][2]== 'O' ))
          {
              winner = 'O';
                  playing = false;
              cout<< "Winner is " << winner << endl; 
          }//1-B. Display an newline to move to the next row of the board
    
  }while( playing );
   
  cout<<"Goodbye!\n";

  return 0;
}
