#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Moves 1 space twards opponent's side (Do 1)
void whitePawnMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {

    bool doubleMoveAvailable = false;

    if (rowStartingLocation == 6) {
        doubleMoveAvailable = true;
    }

    if (doubleMoveAvailable == true) {
        if (rowEndingLocation == rowStartingLocation - 2 && colEndingLocation == colStartingLocation) {
            //Make the move on the board
            board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
            board[rowStartingLocation][colStartingLocation] = "  ";
        } else if (rowEndingLocation == rowStartingLocation - 1 && colEndingLocation == colStartingLocation) {
            //Make the move on the board
            board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
            board[rowStartingLocation][colStartingLocation] = "  ";
        } else {
            std::cout << "Invalid move for Pawn.\n";
        }
    } else {
        if (rowEndingLocation == rowStartingLocation - 1 && colEndingLocation == colStartingLocation) {
            //Make the move on the board
            board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
            board[rowStartingLocation][colStartingLocation] = "  ";
        } else {
            std::cout << "Invalid move for Pawn.\n";
        }
    }

}
void blackPawnMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {

    bool doubleMoveAvailable = false;

    if (rowStartingLocation == 1) {
        doubleMoveAvailable = true;
    }

    if (doubleMoveAvailable == true) {
        if (rowEndingLocation == rowStartingLocation + 2 && colEndingLocation == colStartingLocation) {
            //Make the move on the board
            board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
            board[rowStartingLocation][colStartingLocation] = "  ";
        } else if (rowEndingLocation == rowStartingLocation + 1 && colEndingLocation == colStartingLocation) {
            //Make the move on the board
            board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
            board[rowStartingLocation][colStartingLocation] = "  ";
        } else {
            std::cout << "Invalid move for Pawn.\n";
        }
    } else {
        if (rowEndingLocation == rowStartingLocation + 1 && colEndingLocation == colStartingLocation) {
            //Make the move on the board
            board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
            board[rowStartingLocation][colStartingLocation] = "  ";
        } else {
            std::cout << "Invalid move for Pawn.\n";
        }
    }
}

//Can move 1 space in any direction (Do 2)
void whiteKingMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {

    if (rowEndingLocation >= rowStartingLocation - 1 && rowEndingLocation <= rowStartingLocation + 1 &&
        colEndingLocation >= colStartingLocation - 1 && colEndingLocation <= colStartingLocation + 1) {
        
        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for King.\n";
    }

}
void blackKingMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {
    
    if (rowEndingLocation >= rowStartingLocation - 1 && rowEndingLocation <= rowStartingLocation + 1 &&
        colEndingLocation >= colStartingLocation - 1 && colEndingLocation <= colStartingLocation + 1) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for King.\n";
    }

}

//Straight movement (Do 3)
void whiteRookMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {
    
    if (rowEndingLocation == rowStartingLocation || colEndingLocation == colStartingLocation) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for Rook.\n";
    }

}
void blackRookMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {
    
    if (rowEndingLocation == rowStartingLocation || colEndingLocation == colStartingLocation) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for Rook.\n";
    }

}

//Diagonal movement (Do 4)
void whiteBishopMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {
    
    if (abs(rowEndingLocation - rowStartingLocation) == abs(colEndingLocation - colStartingLocation)) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for Bishop.\n";
    }

}
void blackBishopMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {
    
    if (abs(rowEndingLocation - rowStartingLocation) == abs(colEndingLocation - colStartingLocation)) {
        //Make the move on the board
        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for Bishop.\n";
    }

}

//This will be Bishop movement + Rook movement (Do 5)
void whiteQueenMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {

    if (rowEndingLocation == rowStartingLocation || colEndingLocation == colStartingLocation ||
        abs(rowEndingLocation - rowStartingLocation) == abs(colEndingLocation - colStartingLocation)) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for Queen.\n";
    }

}
void blackQueenMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {
   
    if (rowEndingLocation == rowStartingLocation || colEndingLocation == colStartingLocation ||
        abs(rowEndingLocation - rowStartingLocation) == abs(colEndingLocation - colStartingLocation)) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for Queen.\n";
    }

}

//L shaped movement (Complicated, do last)
void whiteKnightMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {

    if ((abs(rowEndingLocation - rowStartingLocation) == 2 && abs(colEndingLocation - colStartingLocation) == 1) ||
        (abs(rowEndingLocation - rowStartingLocation) == 1 && abs(colEndingLocation - colStartingLocation) == 2)) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for Knight.\n";
    }

}
void blackKnightMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation) {

    if ((abs(rowEndingLocation - rowStartingLocation) == 2 && abs(colEndingLocation - colStartingLocation) == 1) ||
        (abs(rowEndingLocation - rowStartingLocation) == 1 && abs(colEndingLocation - colStartingLocation) == 2)) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for Knight.\n";
    }

}

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

/*1. Make logic to check if there is a piece as the same color at the destination
  2. Make sure that if your move is invalid, you get to choose again without losing your turn.
  3. Implement check, checkmate, and stalemate conditions.
  4. Implement special moves (castling, en passant, pawn promotion).
  5. Make the board flip after each turn so players can see from their perspective.*/

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

    std::string currentPlayer;
    std::string pieceAtStartingLocation;
    std::string pieceAtDestination;

    std::string chessNotationStartingLocation;
    std::string chessNotationEndingLocation;

    int rowStartingLocation, colStartingLocation;
    int rowEndingLocation, colEndingLocation;

    bool canMoveWhitePiece = false;
    bool canMoveBlackPiece = false;
    
    bool canCastleWhite = true;
    bool canCastleBlack = true;

    //A > a > 1 

    std::cout << "When asked for row and column, please follow chess notation.\n\nIf the piece is at e2, input e2 (row first, then column).\n\n";

    //While loop while no-one has won the game.
    while (gameOver == false) {
        bool validMoveWhite = false;
        bool validMoveBlack = false;

        displayBoard(board);

        std::cout << "What piece do you want to move? (White) : \n";
        std::cin >> chessNotationStartingLocation;

        std::cout << "Where do you want to move it? : \n";
        std::cin >> chessNotationEndingLocation;

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

        switch (chessNotationStartingLocation[1]) {
            case '1': rowStartingLocation = 7; break;
            case '2': rowStartingLocation = 6; break;
            case '3': rowStartingLocation = 5; break;
            case '4': rowStartingLocation = 4; break;
            case '5': rowStartingLocation = 3; break;
            case '6': rowStartingLocation = 2; break;
            case '7': rowStartingLocation = 1; break;
            case '8': rowStartingLocation = 0; break;
            default: std::cout << "Invalid row input.\n"; break;
        }

        std::string pieceAtStartingLocation = board[rowStartingLocation][colStartingLocation];

        switch (chessNotationEndingLocation[0]) {
            case 'a': colEndingLocation = 0; break;
            case 'b': colEndingLocation = 1; break;
            case 'c': colEndingLocation = 2; break;
            case 'd': colEndingLocation = 3; break;
            case 'e': colEndingLocation = 4; break;
            case 'f': colEndingLocation = 5; break;
            case 'g': colEndingLocation = 6; break;
            case 'h': colEndingLocation = 7; break;
            default: std::cout << "Invalid column input.\n"; break;
        }

        switch (chessNotationEndingLocation[1]) {
            case '1': rowEndingLocation = 7; break;
            case '2': rowEndingLocation = 6; break;
            case '3': rowEndingLocation = 5; break;
            case '4': rowEndingLocation = 4; break;
            case '5': rowEndingLocation = 3; break;
            case '6': rowEndingLocation = 2; break;
            case '7': rowEndingLocation = 1; break;
            case '8': rowEndingLocation = 0; break;
            default: std::cout << "Invalid row input.\n"; break;
        }    

        std::string pieceAtDestination = board[rowEndingLocation][colEndingLocation];



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

        //If a player atempts an invalid move, make them choose again without losing their turn.
        if (pieceAtDestination == "♜ " || pieceAtDestination == "♞ " || pieceAtDestination == "♝ " || pieceAtDestination == "♛ " || pieceAtDestination == "♚ " || pieceAtDestination == "♟ ") {
            std::cout << "You cannot move to that space, there is a piece of the same color there.\n";
            validMoveWhite = false;
        } else {
            validMoveWhite = true;
        }


        if (pieceAtStartingLocation == "♟ ") {
            whitePawnMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♚ ") {
            whiteKingMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♜ ") {
            whiteRookMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♝ ") {
            whiteBishopMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♛ ") {
            whiteQueenMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♞ ") {
            whiteKnightMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation  );
        } else {
            std::cout << "That is not a valid piece. Please choose again.\n";
        }

        //Make this mirrored for black pieces. aka copy the code from above and change the pieces to black pieces.
        } else if (currentPlayer == "black") {

        if (pieceAtDestination == "♖ " || pieceAtDestination == "♘ " || pieceAtDestination == "♗ " || pieceAtDestination == "♕ " || pieceAtDestination == "♔ " || pieceAtDestination == "♙ ") {
            std::cout << "You cannot move to that space, there is a piece of the same color there.\n";
            validMoveBlack = false;
        } else {
            validMoveBlack = true;
        }

        if (pieceAtStartingLocation == "♙ ") {
            blackPawnMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♔ ") {
            blackKingMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♖ ") {
            blackRookMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♗ ") {
            blackBishopMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♕ ") {
            blackQueenMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
        } else if (pieceAtStartingLocation == "♘ ") {
            blackKnightMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation);
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