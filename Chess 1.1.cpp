#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Moves 1 space twards opponent's side (Do 1)
void whitePawnMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {
    //Remove this later (testing)
    std::cout << "Function works (White Pawn)\n";

    bool pawnFirstMove = false;
    bool doubleMoveAvailable = false;

    if (rowStartingLocation == 6) {
        pawnFirstMove = true;
        doubleMoveAvailable = true;
    }

    if (pawnFirstMove == true) {
        std::cout << "Test\n";

    }



}
void blackPawnMovement () {
    std::cout << "Function works (Black Pawn)" << std::endl;
}

//Can move 1 space in any direction (Do 2)
void whitekingMovement () {
    std::cout << "Function works (White King)\n";
}
void blackKingMovement () {
    std::cout << "Function works (Black King)\n";
}

//Straight movement (Do 3)
void whiteRookMovement () {
    std::cout << "Function works (White Rook)\n";
}
void blackRookMovement () {
    std::cout << "Function works (Black Rook)\n";
}

//Diagonal movement (Do 4)
void whitebishopMovement () {
    std::cout << "Function works (White Bishop)\n";
}
void blackBishopMovement () {
    std::cout << "Function works (Black Bishop)\n";
}

//This will be Bishop movement + Rook movement (Do 5)
void whiteQueenMovement () {
    std::cout << "Function works (White Queen)\n";
}
void blackQueenMovement () {
    std::cout << "Function works (Black Queen)\n";
}

//L shaped movement (Complicated, do last)
void whiteKnightMovement () {
    std::cout << "Function works (White Knight)\n";
}
void blackKnightMovement () {
    std::cout << "Function works (Black Knight)\n";
}

//Intergrate this into the main code. 
/*void checkForPiece(int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string currentPlayer, std::string board[8][8], std::string pieceAtStartingLocation, std::string pieceAtDestination, bool validMove) {
    //Add logic to make sure that the ending location does not have a piece of the same color. 
    //Make the logic to check the spaces inbetween for pieces later.
    validMove == true;

    if (currentPlayer == "white") {

        //Checks to see if the piece is the same color as white. 
        
        if (pieceAtDestination == "♜" || pieceAtDestination == "♞" || pieceAtDestination == "♝" || pieceAtDestination == "♛" || pieceAtDestination == "♚" || pieceAtDestination == "♟") {
            std::cout << "You cannot move to that space, there is a piece of the same color there.\n";
        }

    } else { //If it's not white's turn, then it must be black's turn. 

        if (pieceAtDestination == "♖" || pieceAtDestination == "♘" || pieceAtDestination == "♗" || pieceAtDestination == "♕" || pieceAtDestination == "♔" || pieceAtDestination == "♙") {
            std::cout << "You cannot move to that space, there is a piece of the same color there.\n";
        }
        
    }

    std::cout << pieceAtStartingLocation << pieceAtDestination << "\n";

}*/

void displayBoard(std::string board[8][8]) {
    cout << "Current board:\n" << endl;
    int k = 8;
    for (int i = 0; i < 8; i++) {
     
        cout << k << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | " << board[i][3] << " | " << board[i][4] << " | " << board[i][5] << " | " << board[i][6] << " | " << board[i][7] << endl;
        if (i < 7) {
            cout << " —-——|—-——|—-——|—-——|—-——|—-——|—-——|—-——" << endl;}  
            k--;
        }

        //Find a way to get a half space in front of the letters so they are centerd. 
        cout << "  Ａ  " << " Ｂ  " << " Ｃ  " << " Ｄ  " << " Ｅ  " << " Ｆ  " << " Ｇ  " << " Ｈ  ";

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
    std::string pieceAtStartingLocation;
    std::string pieceAtDestination;

    std::string chessNotationStartingLocation;
    std::string chessNotationEndingLocation;

    int rowStartingLocation, colStartingLocation;
    int rowEndingLocation, colEndingLocation;

    bool canMoveWhitePiece = false;
    bool canMoveBlackPiece = false;
    
    //A > a > 1 

    std::cout << "When asked for row and column, please follow chess notation.\n\nIf the piece is at e2, input e2 (row first, then column).\n\n";

    //While loop while no-one has won the game.
    while (gameOver == false) {
        bool validMove = false;

        //Make something to alternate turns between white and black.
        if (turn % 2 == 0) {
            currentPlayer = "white";
            std::cout << "White's turn." << std::endl;

        } else {
            currentPlayer = "black";
            std::cout << "Black's turn." << std::endl;
        }

        std::cout << "What piece do you want to move? : \n";
        std::cin >> chessNotationStartingLocation;

        std::cout << "Where do you want to move it? : \n";
        std::cin >> chessNotationEndingLocation;

        //Test
        std::cout << chessNotationStartingLocation << " " << chessNotationEndingLocation << "\n";

        //Need to make a 64 switch statement to identify where on the grid the piece is based on chess notation.
        //Need to translate chess notation into array locations
        switch (chessNotationStartingLocation[0]) {
            case 'a': colStartingLocation = 0; break;
            case 'b': colStartingLocation = 1; break;
            case 'c': colStartingLocation = 2; break;
            case 'd': colStartingLocation = 3; break;
            case 'e': colStartingLocation = 4; break;
            case 'f': colStartingLocation = 5; break;
            case 'g': colStartingLocation = 6; break;
            case 'h': colStartingLocation = 7; break;
            default: std::cout << "Invalid column input.\n"; break;
        }


        std::cout << colStartingLocation << "\n";
        //To adjust for array starting at 0
        //rowStartingLocation--; colStartingLocation--;
        //rowEndingLocation--; colEndingLocation--;

        //std::string pieceAtStartingLocation = board[rowStartingLocation][colStartingLocation];
        //std::string pieceAtDestination = board[rowEndingLocation][colEndingLocation];

        //Remove this later (testing)
        //std::cout << pieceAtStartingLocation << pieceAtDestination << "\n";


        //PAST THIS POINT THE CODE WILL NOT WORK PROPERLY UNTIL CHESS NOTATION IS IMPLEMENTED.

        //Player logic
        if (currentPlayer == "white") {
                
            //The code needed to identify what piece is being moved and where it is moving to needs to stay out of the currentPlayer if statements.

            //If a player atempts an invalid move, make them choose again without losing their turn.

            if (pieceAtDestination == "♜ " || pieceAtDestination == "♞ " || pieceAtDestination == "♝ " || pieceAtDestination == "♛ " || pieceAtDestination == "♚ " || pieceAtDestination == "♟ ") {
            std::cout << "You cannot move to that space, there is a piece of the same color there.\n";
            validMove = false;
            } else {
                validMove = true;
            }


            //Make this a switch statement for cleaner code.
            if (pieceAtStartingLocation == "♟ ") {
                whitePawnMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
            } else if (pieceAtStartingLocation == "♚ ") {
                whitekingMovement();
            } else if (pieceAtStartingLocation == "♜ ") {
                whiteRookMovement();
            } else if (pieceAtStartingLocation == "♝ ") {
                whitebishopMovement();
            } else if (pieceAtStartingLocation == "♛ ") {
                whiteQueenMovement();
            } else if (pieceAtStartingLocation == "♞ ") {
                whiteKnightMovement();
            } else {
                std::cout << "That is not a valid piece. Please choose again.\n";
            }

        //Make this mirrored for black pieces. aka copy the code from above and change the pieces to black pieces.
        } else if (currentPlayer == "black") {
            canMoveBlackPiece = true;
        
            std::cout << "What piece do you want to move? (row and column(Black)): \n";
            
            cin >> rowStartingLocation >> colStartingLocation;
                
            //To adjust for array starting at 0
            rowStartingLocation--; colStartingLocation--;
                
            //Idenify piece at starting location
            std::string pieceAtStartingLocation = board[rowStartingLocation][colStartingLocation];

            //Remove this later (testing)
            std::cout << pieceAtStartingLocation << "\n";

            //This is where main code will be.

            if (pieceAtStartingLocation == "♙ ") {
                blackPawnMovement();
            } else if (pieceAtStartingLocation == "♔ ") {
                blackKingMovement();
            } else if (pieceAtStartingLocation == "♖ ") {
                blackRookMovement();
            } else if (pieceAtStartingLocation == "♗ ") {
                blackBishopMovement();
            } else if (pieceAtStartingLocation == "♕ ") {
                blackQueenMovement();
            } else if (pieceAtStartingLocation == "♘ ") {
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