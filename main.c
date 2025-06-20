#include <stdio.h>
#include <stdbool.h>

// #define ROWS 3
// #define COL 3

// array to hold 3x3 grid
//void display(int g[ROWS][COL]);

#define ROW 3
#define COL 3

bool game_done;
//bool success;


bool player_input(char g[ROW][COL]);

void player_turn(char g[ROW][COL]);

void display(char g[ROW][COL]);

bool end_conditions(char g[ROW][COL]);

bool computer_turn(char g[ROW][COL]);


int main(void) 
{
    // initialise 2d matrix
    // char so user can input x or o
   

    char grid[ROW][COL] = { {'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'} };
   
    


    while (!game_done) {
        player_turn(grid);
        display(grid);
        game_done = end_conditions(grid); 
        // stop the game after player wins
        if (game_done) {
            break;
        }
        computer_turn(grid);
        display(grid);
        game_done = end_conditions(grid);
    }

}

bool player_input(char g[ROW][COL])
{
    int row,col;
    int extra; 
    char buff[128]; // buffer for input



    printf("Player: Enter row and column: ");

    if(!fgets(buff, sizeof(buff), stdin)) {
        printf("Input error\n");
        return false;
    }

    if (sscanf(buff, "%d %d %d", &row, &col, &extra) == 2) {
        // 2 integets read, good input. 
        if ((row >= 0  && row < ROW) && (col >= 0 && col < COL)) {

            if (g[row][col] == '_') {
                g[row][col] = 'X';
                return true;
            }

            else {
                printf("Spot already taken\n");
                return false;
            }
        }  
        else {
            printf("Coordinates out of bounds\n");
            return false;
        }

    }

    else if (sscanf(buff, "%d %d %d", &row, &col, &extra) >= 3) {
        printf("Too many numbers inputted\n");
        return false;
    }

    else {
        printf("Invalid input, enter two numbers separated by a space\n");
        return false;
    }
    return false;
}

// manages the player turn
void player_turn(char g[ROW][COL])
{

    bool valid;


    do {

        valid = player_input(g);

    } while(!valid);

}

// display the grid
void display(char g[ROW][COL])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", g[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

bool end_conditions(char g[ROW][COL])
{
    // column win conditions
    if (g[0][0] != '_' && (g[0][0] == g[1][0]) && g[0][0] == g[2][0]) {
        if ((g[0][0] == g[1][0]) && g[0][0] == g[2][0]) {
            printf("Game has ended\n");
            game_done = true;
            return game_done;
        }

    }

    if (g[0][1] != '_' && (g[0][1] == g[1][1]) && g[0][1] == g[2][1]) {

        if ((g[0][1] == g[1][1]) && g[0][1] == g[2][1]) {
            printf("Game has ended\n");
            game_done = true;
            return game_done;
        }
    }
    if (g[0][2] != '_' && (g[0][2] == g[1][2]) && g[0][2] == g[2][2]) {

        if ((g[0][2] == g[1][2]) && g[0][2] == g[2][2]) {
            printf("Game has ended\n");
            game_done = true;
            return game_done;
        }
    }

    
    // row win conditions
    if (g[0][0] != '_' && (g[0][0] == g[0][1]) && g[0][0] == g[0][2]) {
        if ((g[0][0] == g[0][1]) && g[0][0] == g[0][2]) {
            printf("Game has ended\n");
            game_done = true;
            return game_done;
        } 

    }

    if (g[1][0] != '_' && (g[1][0] == g[1][1]) && g[1][0] == g[1][2]) {
        if ((g[1][0] == g[1][1]) && g[1][0] == g[1][2]) {
            printf("Game has ended\n");
            game_done = true;
            return game_done;
        } 

    }

    if (g[2][0] != '_' && (g[2][0] == g[2][1]) && g[2][0] == g[2][2]) {
        if ((g[2][0] == g[2][1]) && g[2][0] == g[2][2]) {
            printf("Game has ended\n");
            game_done = true;
            return game_done;
        } 

    }

    // diagonal win conditions
    if (g[0][0] != '_' && (g[0][0] == g[1][1]) && g[0][0] == g[2][2]) {
        if ((g[0][0] == g[1][1]) && g[0][0] == g[2][2]) {
            printf("Game has ended\n");
            game_done = true;
            return game_done;
        } 

    }

    if (g[2][0] != '_' && (g[2][0] == g[1][1]) && g[2][0] == g[0][2]) {
        if ((g[2][0] == g[1][1]) && g[2][0] == g[0][2]) {
            printf("Game has ended\n");
            game_done = true;
            return game_done;
        } 

    }

    return false;    
} 

bool computer_turn(char g[ROW][COL]) 
{
    printf("Computer turn:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if ((g[i][j]) == '_') {
                g[i][j] = 'O';
                return true;
            }
        }
    }
    return false;

}