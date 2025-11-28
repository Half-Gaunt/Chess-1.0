#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Moves 1 space twards opponent's side (Do 1)
void whitePawnMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string piece) {
    //Remove this later (testing)
    std::cout << "Function works (White)" << std::endl;

    bool pawnFirstMove = false;

    if (rowStartingLocation == 6) {
        pawnFirstMove = true;
    }

    //TEST TEST TEST

}
void blackPawnMovement () {
    std::cout << "Function works (Black)" << std::endl;
}

//Can move 1 space in any direction (Do 2)
void whitekingMovement () {

}
void blackKingMovement () {

}

//Straight movement (Do 3)
void whiteRookMovement () {

}
void blackRookMovement () {

}

//Diagonal movement (Do 4)
void whitebishopMovement () {

}
void blackBishopMovement () {

}

//This will be Bishop movement + Rook movement (Do 5)
void whiteQueenMovement () {

}
void blackQueenMovement () {

}

//L shaped movement (Complicated, do last)
void whiteKnightMovement () {

}
void blackKnightMovement () {

}



void displayBoard(std::string board[8][8]) {
    cout << "Current board:\n" << endl;
    for (int i = 0; i < 8; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | " << board[i][3] << " | " << board[i][4] << " | " << board[i][5] << " | " << board[i][6] << " | " << board[i][7] << endl;
        if (i < 7) {
            cout << "—-——|—-——|—-——|—-——|—-——|—-——|—-——|—-——" << endl;}  
        }
        cout << "\n";
}

/*Things to inprove from 1.0

1. Make everything into functions so it is reusable and cleaner.
2. Make turns alternate between white and black and make it so that the player can only move their own pieces.
3. Make logic to see if a piece is in the way of another piece. Like if a rook is trying to move through a pawn. If there is a piece in the way,
   it cannot move. If there is no piece in the way, it can move.
*/

int main() {
    
    bool gameOver = false;

    int turn = 0; // 0 for white, 1 for black

    std::string board[8][8] = {
        {"♖ ", "♘ ", "♗ ", "♔ ", "♕ ", "♗ ", "♘ ", "♖ "},
        {"♙ ", "♙ ", "♙ ", "♙ ", "♙ ", "♙ ", "♙ ", "♙ "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"♟ ", "♟ ", "♟ ", "♟ ", "♟ ", "♟ ", "♟ ", "♟ "},
        {"♜ ", "♞ ", "♝ ", "♚ ", "♛ ", "♝ ", "♞ ", "♜ "}
        //White pieces are on the bottom, black pieces are on the top.
    };

    displayBoard(board);

    std::string currentPlayer;

    int rowStartingLocation, colStartingLocation;
    int rowEndingLocation, colEndingLocation;

    bool canMoveWhitePiece = false;
    bool canMoveBlackPiece = false;

    //While loop while no-one has won the game.
    while (gameOver == false) {

        //Make something to alternate turns between white and black.
        if (turn % 2 == 0) {
            currentPlayer = "white";
            std::cout << "White's turn." << std::endl;

        } else {
            currentPlayer = "black";
            std::cout << "Black's turn." << std::endl;
        }

        //Player logic
        if (currentPlayer == "white") {
            canMoveWhitePiece = true;
        
            std::cout << "What piece do you want to move? (row and column): \n";
              
            cin >> rowStartingLocation >> colStartingLocation;
                
            //To adjust for array starting at 0
            rowStartingLocation--; colStartingLocation--;
                
            //Idenify piece at starting location
            std::string piece = board[rowStartingLocation][colStartingLocation];

            //Remove this later (testing)
            std::cout << piece << "\n";

            //This is where main code will be.

            if (piece == "♟ ") {
                whitePawnMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, piece);
            } else if (piece == "♚ ") {
                whitekingMovement();
            } else if (piece == "♜ ") {
                whiteRookMovement();
            } else if (piece == "♝ ") {
                whitebishopMovement();
            } else if (piece == "♛ ") {
                whiteQueenMovement();
            } else if (piece == "♞ ") {
                whiteKnightMovement();
            } else {
                std::cout << "That is not a valid piece. Please choose again.\n";
            }

        } else if (currentPlayer == "black") {
            canMoveBlackPiece = true;
        
            std::cout << "What piece do you want to move? (row and column): \n";
              
            cin >> rowStartingLocation >> colStartingLocation;
                
            //To adjust for array starting at 0
            rowStartingLocation--; colStartingLocation--;
                
            //Idenify piece at starting location
            std::string piece = board[rowStartingLocation][colStartingLocation];

            //Remove this later (testing)
            std::cout << piece << "\n";

            //This is where main code will be.

            if (piece == "♙ ") {
                blackPawnMovement();
            } else if (piece == "♔ ") {
                blackKingMovement();
            } else if (piece == "♖ ") {
                blackRookMovement();
            } else if (piece == "♗ ") {
                blackBishopMovement();
            } else if (piece == "♕ ") {
                blackQueenMovement();
            } else if (piece == "♘ ") {
                blackKnightMovement();
            } else {
                std::cout << "That is not a valid piece. Please choose again.\n";
            }

        }

        //Remove this later, just for testing. This will be where win logic goes. 
        if (turn == 10) {
            gameOver = true;
        }

        turn++; 

    }   

    //Keep this as an indicator for now. 
    std::cout << "Finished Loop";

}