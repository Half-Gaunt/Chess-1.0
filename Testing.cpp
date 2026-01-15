#include <iostream>
#include <string>
#include <cstdlib>
#include <utility>
using namespace std;

//Straight movement (Do 3)
void whiteRookMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation, bool validMove) {
    
    if (rowEndingLocation == rowStartingLocation || colEndingLocation == colStartingLocation) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
        validMove = true;
        std::cout << "Move successful.\n";
    } else {
        std::cout << "Invalid move for Rook.\n";
    }

}
void blackRookMovement (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8], std::string pieceAtStartingLocation, bool validMoveBlack) {
    
    if (rowEndingLocation == rowStartingLocation || colEndingLocation == colStartingLocation) {

        board[rowEndingLocation][colEndingLocation] = pieceAtStartingLocation;
        board[rowStartingLocation][colStartingLocation] = "  ";
    } else {
        std::cout << "Invalid move for Rook.\n";
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

bool swapRows(std::string board[8][8], int r1, int r2) {
    if (r1 < 0 || r1 > 7 || r2 < 0 || r2 > 7) return false;
    for (int c = 0; c < 8; ++c) {
        std::swap(board[r1][c], board[r2][c]);
    }
    return true;
}

  //Top priority)Add code to figure out if a piece is in the way of another piece moving (except for knight).

int main() {
    
    bool gameOver = false;

    int turn = 0; // 0 for white, 1 for black

    std::string board[8][8] = {
        {"♖ ", "♘ ", "♗ ", "♔ ", "♕ ", "♗ ", "♘ ", "♖ "},
        {"  ", "♙ ", "♙ ", "♙ ", "♙ ", "♙ ", "♙ ", "♙ "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "♟ ", "  ", "  ", "  ", "  "},
        {"  ", "♟ ", "♟ ", "  ", "♟ ", "♟ ", "♟ ", "  "},
        {"♜ ", "♞ ", "♝ ", "♚ ", "♛ ", "♝ ", "♞ ", "  "}
        //White pieces are on the bottom, black pieces are on the top.
    };

    std::string currentPlayer;
    std::string pieceAtStartingLocation;
    std::string pieceAtDestination;

    std::string chessNotationStartingLocation;
    std::string chessNotationEndingLocation;

    int rowStartingLocation, colStartingLocation;
    int rowEndingLocation, colEndingLocation;
    int fiftyTurnRule = 0;

    bool pawnMoved = false;
    bool pieceCaptured = false;

    bool switchPlayer = true;

    bool canMoveWhitePiece = false;
    bool canMoveBlackPiece = false;

    bool validMove = false;

    std::cout << "When asked for row and column, please follow chess notation.\n\nIf the piece is at e2, input e2 (row first, then column).\n\n";

    /*

    First, whos turn it is (Ensure that the player can only move their piece).
    Then, get the piece at the starting location.
    Then, get the piece at the destination location.
    Then, Make sure the piece is moving spaces. 
    Then, Checks to see if the piece is moving on-top of another piece of the same color. 





    */



    //While loop while no-one has won the game.
    while (gameOver == false) {

        bool validMoveWhite = false;
        bool validMoveBlack = false;
        bool validMove = false;
        pawnMoved = false;
        pieceCaptured = false;

        while (validMove == true) {

            validMove = true;
            canMoveWhitePiece = false;
            canMoveBlackPiece = false;
            validMoveWhite = false;
            validMoveBlack = false; 

            if (turn % 2 == 0) {
                currentPlayer = "white";
                std::cout << "White's turn.\n";
                canMoveWhitePiece = true;
            } else {
                currentPlayer = "black";
                std::cout << "Black's turn.\n";
                canMoveBlackPiece = true;
            }

            displayBoard(board);

            std::cout << "What piece do you want to move? : \n";
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

            pieceAtStartingLocation = board[rowStartingLocation][colStartingLocation];

            std::cout << pieceAtStartingLocation << " selected.\n";

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

            pieceAtDestination = board[rowEndingLocation][colEndingLocation];

            std::cout << pieceAtDestination << " at destination.\n";

            if (colStartingLocation == colEndingLocation && rowStartingLocation == rowEndingLocation) {

            std::cout << "You must move the piece to a different location.\n";
            validMove = false;
            continue;

            } 

            if (currentPlayer == "white") {

            if (pieceAtDestination == "♜ " || pieceAtDestination == "♞ " || pieceAtDestination == "♝ " || pieceAtDestination == "♛ " || pieceAtDestination == "♚ " || pieceAtDestination == "♟ ") {
                std::cout << "You cannot move to that space, there is a piece of the same color there.\n";
                validMove = false;
                continue;
            } 

            } else if (currentPlayer == "black") {

            if (pieceAtDestination == "♖ " || pieceAtDestination == "♘ " || pieceAtDestination == "♗ " || pieceAtDestination == "♕ " || pieceAtDestination == "♔ " || pieceAtDestination == "♙ ") {
            std::cout << "You cannot move to that space, there is a piece of the same color there.\n";
            validMove = false;
            continue;
            } else {
                validMove = true;
            }

            }

        }

        //Move this into the validMove while loop. 
        std::cout << "Attempting to move" << pieceAtStartingLocation << " from " << chessNotationStartingLocation << " to " << chessNotationEndingLocation << ".\n";

        //Player logic
        if (currentPlayer == "white") {

        whiteRookMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation, validMoveWhite);

        if (validMoveWhite == false) {
            continue;
            std::cout << "White failed move check.\n";
        }

        for (int p = 0; p < 4; ++p) {
        swapRows(board, p, 7 - p);
        }

        //Make this mirrored for black pieces. aka copy the code from above and change the pieces to black pieces.
        } else if (currentPlayer == "black") {

        blackRookMovement(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board, pieceAtStartingLocation, validMove);

        if (validMoveBlack == false) {
            continue;
            std::cout << "Black failed move check.\n";
        }

        for (int p = 0; p < 4; ++p) {
        swapRows(board, p, 7 - p);
        }

        }

        //This stays out of the validMove while loop. 
        if (pawnMoved == true || pieceCaptured == true) {
            fiftyTurnRule = 0;
        }

        if (fiftyTurnRule >= 50) {
            gameOver = true;
            std::cout << "The game is a draw due to the fifty-move rule.\n";
        }

        fiftyTurnRule++;

        turn++; 
        
        std::cout << "Made it through the turn.\n";
    }   

    //Keep this as an indicator for now. 
    std::cout << "Finished Loop";

}