// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

#define N 10
#define M 10


int count_neighbours(int row, int col, char game [N][M])
{
    std::vector<int> delta = {-1, 0, 1};
    int count = 0;
    for (int r = 0; r < delta.size(); ++r)
    {
        for (int c = 0; c < delta.size(); ++c)
        {
            if (delta[r] == 0 && delta[c] == 0)
            {
                continue;
            }
            int currRow = row + delta[r];
            int currCol = col + delta[c];
            if (currRow >= N) currRow = 0;
            if (currCol >= M) currCol = 0;
            if (currRow < 0) currRow = N - 1;
            if (currCol < 0) currCol = M - 1;
            if (game[currRow][currCol] == 'X') count++;
        }
    }

    return count;
}
// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    int generation = 0;
    char new_game[N][M];
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        std::memcpy(new_game,game,N*M);
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < M; c++)
            {
                int count = count_neighbours(r, c, game);
                // Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                bool alive = game[r][c] == 'X';
                if (alive && count < 2)
                {
                    new_game[r][c] = '-';
                }

                // Any live cell with two or three live neighbors lives on to the next generation.
                //if (alive && (count == 2 || count == 3))
                //{
                    // live on
                //}

                // Any live cell with more than three live neighbors dies, as if by overpopulation.
                if (alive && count > 3)
                {
                    new_game[r][c] = '-';
                }
                // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                if (!alive && count == 3)
                {
                    new_game[r][c] = 'X';
                }
                
            }
        }
        std::memcpy(game, new_game, N * M);
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
