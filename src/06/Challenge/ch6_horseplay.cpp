// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>
#include <set>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.

std::set<char> ranks = { '1', '2', '3', '4', '5', '6', '7', '8'};
std::set<char> files = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

std::vector<std::string> knight_moves(std::string knight)
{
    std::vector<std::string> moves;

    const char colCh = knight[0];
    const char rowCh = knight[1];
    if (ranks.find(rowCh) == ranks.end() || files.find(colCh) == files.end())
    {
        return moves;
    }
    // note a - h is 97 - 104
    const int aOffset = 'a' - 1;
    const int col = (int)knight[0] - aOffset;
    const int row = knight[1] - '0';
    const int maxsize = 8;
    const int minsize = 1;
    std::string new_loc = "  ";
    // left 2 up 1
    if (col - 2 >= minsize && row + 1 <= maxsize)
    {
        new_loc[0] = char(col - 2 + aOffset);
        new_loc[1] = char(row + 1 + '0');
        moves.push_back(new_loc);
    }
    // left 2 down 1
    if (col - 2 >= minsize && row - 1 >= minsize)
    {
        new_loc[0] = (char)(col - 2 + aOffset);
        new_loc[1] = (char)(row - 1 + '0');
        moves.push_back(new_loc);
    }
    // left 1 up 2
    if (col - 1 >= minsize && row + 2 <= maxsize)
    {
        new_loc[0] = (char)(col - 1 + aOffset);
        new_loc[1]= (char)(row + 2 + '0');
        moves.push_back(new_loc);
    }
    // left 1 down 2
    if (col - 1 >= minsize && row - 2 >= minsize)
    {
        new_loc[0] = (char)(col - 1 + aOffset);
        new_loc[1] = (char)(row - 2 + '0');
        moves.push_back(new_loc);
    }
    // right 2 up 1
    if (col + 2 <= maxsize && row + 1 <= maxsize)
    {
        new_loc[0] = (char)(col + 2 + aOffset);
        new_loc[1] = (char)(row + 1 + '0');
        moves.push_back(new_loc);
    }
    // right 2 down 1
    if (col + 2 <= maxsize && row - 1 >= minsize)
    {
        new_loc[0] = (char)(col + 2 + aOffset);
        new_loc[1] = (char)(row - 1 + '0');
        moves.push_back(new_loc);
    }
    // right 1 up 2
    if (col + 1 <= maxsize && row + 2 <= maxsize)
    {
        new_loc[0] = (char)(col + 1 + aOffset);
        new_loc[1] = (char)(row + 2 + '0');
        moves.push_back(new_loc);
    }
    // right 1 down 2
    if (col + 1 <= maxsize && row - 2 >= minsize)
    {
        new_loc[0] = (char)(col + 1 + aOffset);
        new_loc[1] = (char)(row - 2 + '0');
        moves.push_back(new_loc);
    }

    return moves;
}

// Main function
int main()
{
    std::string knight;
    
    // example d5 is all 8
    // example h7 is only 3
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << ", ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}