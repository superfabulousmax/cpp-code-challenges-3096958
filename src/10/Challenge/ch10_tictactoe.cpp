// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>
#include <vector>

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark){
    std::string str;
    int row, col;
    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1]!=' ');
    game[row-1][col-1] = mark;
    return;
}


std::pair<int, int> find_blocking_move(char game[][3], char mark, int targetCount = 2)
{
    std::pair<int, int> freeSpot;
    freeSpot.first = -1;
    freeSpot.second = -1;
    std::pair<int, int> freeSpotCol;
    freeSpotCol.first = -1;
    freeSpotCol.second = -1;
    int countRow = 0;
    int countCol = 0;
    for (int row = 0; row < 3; ++row)
    {
        countRow = 0;
        countCol = 0;
        freeSpot.first = -1;
        freeSpot.second = -1;
        freeSpotCol.first = -1;
        freeSpotCol.second = -1;
        for (int col = 0; col < 3; ++col)
        {
            if (game[row][col] == mark)
            {
                countRow++;
            }
            else if(game[row][col] == ' ')
            {
                freeSpot.first = row;
                freeSpot.second = col;
            }
            if (game[col][row] == mark)
            {
                countCol++;
            }
            else if(game[col][row] == ' ')
            {
                freeSpotCol.first = col;
                freeSpotCol.second = row;
            }
        }
        if (countRow == targetCount && freeSpot.first != -1 && freeSpot.second != -1)
        {
            return freeSpot;
        }
        if (countCol == targetCount && freeSpotCol.first != -1 && freeSpotCol.second != -1)
        {
            return freeSpotCol;
        }
    }
    // check diagonal
    int count = 0;
    freeSpot.first = -1;
    freeSpot.second = -1;
    for (int diag = 0; diag < 3; ++diag)
    {
        if (game[diag][diag] == mark)
        {
            count++;
        }
        else if(game[diag][diag] == ' ')
        {
            freeSpot.first = diag;
            freeSpot.second = diag;
        }
    }
    
    if (count == targetCount && freeSpot.first != -1 && freeSpot.second != -1)
    {
        return freeSpot;
    }

    count = 0;
    freeSpot.first = -1;
    freeSpot.second = -1;
    std::vector<int> rowValues = {2, 1, 0};
    std::vector<int> colValues = {0, 1, 2};

    for (int i = 0; i < 3; ++i)
    {
        char test = game[rowValues[i]][colValues[i]];
        if (test== mark)
        {
            count++;
        }
        else if(test == ' ')
        {
            freeSpot.first = rowValues[i];
            freeSpot.second = colValues[i];
        }
    }
    if (count == targetCount && freeSpot.first != -1 && freeSpot.second != -1)
    {
        return freeSpot;
    }

    freeSpot.first = -1;
    freeSpot.second = -1;
    return freeSpot;
}

std::vector<std::pair<int, int>> find_random_empty_spot(char game[][3])
{
    std::vector<std::pair<int, int>> spots;

    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if(game[row][col] == ' ')
            {
                std::pair<int, int> freeSpot;
                freeSpot.first = row;
                freeSpot.second = col;
                spots.push_back(freeSpot);
            }
        }
    }
    return spots;
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

//#define TWO_PLAYERS
void make_move(char game[][3], char mark){ 
    #ifdef TWO_PLAYERS
    ask_for_move(game,mark);
    #else
    
    // check if can win first
    auto move = find_blocking_move(game, mark);
    if (move.first != -1 && move.second != -1)
    {
        game[move.first][move.second] = mark;
    }
    else
    {
        // check if blocking move
        char oppositeMark = (mark == 'X')? 'O' : 'X';
        move = find_blocking_move(game, oppositeMark);
        if (move.first != -1 && move.second != -1)
        {
            game[move.first][move.second] = mark;
        }

    }
    // no winning or blocking move so random move
    if (move.first == -1 && move.second == -1)
    {
        auto freeSpots = find_random_empty_spot(game);
        if (freeSpots.size() > 0)
        {
            int random = rand() % freeSpots.size();
            move = freeSpots[random];
            game[move.first][move.second] = mark;
        }

    }

    #endif
    return;
}


char check_rows_and_cols(char game[][3])
{
    int currXCountRow = 0;
    int currOCountRow = 0;
    int currXCountCol = 0;
    int currOCountCol = 0;
    for (int row = 0; row < 3; ++row)
    {
        currXCountRow = 0;
        currOCountRow = 0;
        currXCountCol = 0;
        currOCountCol = 0;
        for (int col = 0; col < 3; ++col)
        {
            if (game[row][col] == 'X')
            {
                currXCountRow++;
            }
            else if (game[row][col] == 'O')
            {
                currOCountRow++;
            }
            if (game[col][row] == 'X')
            {
                currXCountCol++;
            }
            else if (game[col][row] == 'O')
            {
                currOCountCol++;
            }
        }
        if (currOCountRow == 3 || currOCountCol == 3)
        {
            return 'O';
        }
        else if (currXCountRow == 3 || currXCountCol == 3)
        {
            return 'X';
        }
    }
    return '-';
}

char check_diagonals(char game[][3])
{
    int currXCount = 0;
    int currOCount = 0;
    for (int diag = 0; diag < 3; ++diag)
    {
        if (game[diag][diag] == 'X')
        {
            currXCount++;
        }
        else if (game[diag][diag] == 'O')
        {
            currOCount++;
        }
    }
    if (currOCount == 3)
    {
        return 'O';
    }
    else if (currXCount == 3)
    {
        return 'X';
    }
    currXCount = 0;
    currOCount = 0;
    std::vector<int> rowValues = {2, 1, 0};
    std::vector<int> colValues = {0, 1, 2};

    for (int i = 0; i < 3; ++i)
    {
        char test = game[rowValues[i]][colValues[i]];
        if (test == 'X')
        {
            currXCount++;
        }
        else if (test == 'O')
        {
            currOCount++;
        }
    }
    if (currOCount == 3)
    {
        return 'O';
    }
    else if (currXCount == 3)
    {
        return 'X';
    }
    return '-';
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
char game_state(char game[][3]){

    char result = check_rows_and_cols(game);
    if (result == 'X' || result == 'O')
    {
        return result;
    }
    
    result = check_diagonals(game);
    if (result == 'X' || result == 'O')
    {
        return result;
    }
    int emptyCount = 0;

    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if(game[row][col] == ' ')
            {
                emptyCount++;
            }
        }
    }
    if (emptyCount == 0)
    {
        return 't';
    }
    return 'a';
}

// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3]){
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int main(){
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o'){
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(game_state(game)=='a'){
        std::cout << turn << "'s turn...\n";    
        if(turn==user_mark)
            ask_for_move(game,user_mark);
        else
            make_move(game,ai_mark);
        print_game(game);
        turn = turn == 'X' ? 'O' : 'X';
    }
    if(game_state(game)=='t')
        std::cout << "It's a tie.\n\n";
    else    
        std::cout << game_state(game) << " is the winner.\n\n";
    std::cout << std::flush;
    return 0;
}
