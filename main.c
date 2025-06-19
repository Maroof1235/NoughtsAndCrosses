#include <stdio.h>
#include <stdbool.h>

// #define ROWS 3
// #define COL 3

// array to hold 3x3 grid
//void display(int g[ROWS][COL]);

#define ROW 3
#define COL 3

bool game_done;


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
        computer_turn(grid);
        display(grid);
        game_done = end_conditions(grid);
    }

}

// manages the player turn
void player_turn(char g[ROW][COL])
{
    int row,col;

    
    do {

        printf("Player: Enter row and column: ");
        scanf("%d %d", &row, &col);
        if (g[row][col] == '_') {
            g[row][col] = 'X';
            return;
        }

        else {
            printf("You can't place an X there!\n");
            display(g);
            return;
        }
    } while (g[row][col] != 'X' || g[row][col] != '_');

    

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