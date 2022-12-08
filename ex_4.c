/******************************************
*Student name: Ori Levy
*Student ID: 318501897
*Exercise name: ex4
******************************************/

#include <stdio.h>

#define SIZE 4
#define SLOTS 64

/************************************************************************
* function name: printTable
* The Input: array=the game table
* The output: prints the game table
* The Function operation: using loops to print the game table as required
 * in the assigment
*************************************************************************/
void printTable(char table[SIZE][SIZE][SIZE]) {
    int side, times, row, column, column1;
    //loop that print row by row whats needed
    for (side = 0; side < SIZE; side++) {
        row = 0;
        for (times = 0; times < SIZE; times++) {
            printf("\n");
            column1 = 0;
            //first printing the coordinates of the game as required
            while (column1 < SIZE) {
                printf("(%d %d %d) ", side, row, column1);
                column1++;
            }
            row++;
            //printing the game table X's and O's
            for (column = 0; column < SIZE; column++) {
                printf("%c ", table[side][times][column]);
            }
        }
        printf("\n");
    }
}
/************************************************************************
* function name: checkScore
* The Input: array= the game table
* The output: game winning situation,win or not win and for who
* The Function operation: check using for loops the game table to spot
 * if there is a 4 streak for any side, if there is returning it and
 * stopping the game
*************************************************************************/
/*I tried doing my best explaining how i checked for win situations, but its
 * quite hard doing so because its very abstract, hope you'll get it*/
char checkScore(char array[SIZE][SIZE][SIZE]) {
    int side, row, column;
    int countX, countO;
    //loop that checks reverse diagonal in the same side
    for (side = 0; side < SIZE; side++) {
        /*initializing counters after every side change because were checking
        streak at the same side*/
        countX = 0;
        countO = 0;
        for (row = 0; row < SIZE; row++) {
            for (column = 0; column < SIZE; column++) {
                if (row + column == SIZE - 1) {
                    if (array[side][row][column] == 'X') {
                        countX++;
                        if (countX == SIZE) {
                            return 'X';
                        }
                    }
                    if (array[side][row][column] == 'O') {
                        countO++;
                        if (countO == SIZE) {
                            return '0';
                        }
                    }
                }
            }
        }
    }
    // loop that checks the "wide" "low" diagonal that starts on the left side
    /*initializing counters only at start because were checking
        streak in the same whole table*/
    countX = 0;
    countO = 0;
    for (side = 0; side < SIZE; side++) {
        for (row = 0; row < SIZE; row++) {
            if (side + row == SIZE - 1) {
                if (array[side][row][side] == 'X')
                    countX++;
                if (countX == SIZE) {
                    return 'X';
                }
            }
            if (side + row == SIZE - 1) {
                if (array[side][row][side] == 'O')
                    countO++;
                if (countO == SIZE) {
                    return 'O';
                }
            }
        }
    }
    //loop that checks "wide" "low" diagonal that starts on the right side
    /*initializing counters only at start because were checking for streak at
    the whole table*/
    column = SIZE - 1;
    countO = 0;
    countX = 0;
    while (column >= 0) {
        for (side = 0; side < SIZE; side++) {
            for (row = 0; row < SIZE; row++) {
                if (side + row == SIZE - 1) {
                    if (array[side][row][column] == 'X')
                        countX++;
                    if (countX == SIZE) {
                        return 'X';
                    }
                }
                if (side + row == SIZE - 1) {
                    if (array[side][row][column] == 'O')
                        countO++;
                    if (countO == SIZE) {
                        return 'O';
                    }
                }
            }
            column--;
        }
    }
    //loop that checks "wide" "high" diagonal in reverse way
    /*initializing counters only at start because were checking
        streak in the same whole table*/
    column = SIZE - 1;
    countX = 0;
    countO = 0;
    for (side = 0; side < SIZE; side++) {
        if (array[side][side][column] == 'X') {
            countX++;
            if (countX == SIZE) {
                return 'X';
            }
        }
        if (array[side][side][column] == 'O') {
            countO++;
            if (countO == SIZE) {
                return 'O';
            }
        }
        column--;

    }
    //loop that checks "wide" normal  diagonal from left to the right
    /*initializing counters only at start because were checking
       streak in the same whole table*/
    countX = 0;
    countO = 0;
    for (side = 0; side < SIZE; side++) {
        for (row = 0; row < SIZE; row++) {
            for (column = 0; column < SIZE; column++) {
                if (side == row && side == column) {
                    if (array[side][side][side] == 'O')
                        countX++;
                    if (countX == SIZE) {
                        return 'O';
                    }
                    if (array[side][side][side] == 'X') {
                        countO++;
                        if (countO == SIZE) {
                            return 'X';
                        }
                    }
                }
            }
        }
    }
    //loop that checks column at the same side
    for (side = 0; side < SIZE; side++) {
        for (column = 0; column < SIZE; column++) {
            /*initializing counters after every side change because were checking
       streak at the same side*/
            countX = 0;
            countO = 0;
            for (row = 0; row < SIZE; row++) {
                if (array[side][row][column] == 'X') {
                    countX++;
                    if (countX == SIZE) {
                        return 'X';
                    }
                    if (array[side][row][column] == 'O') {
                        countO++;
                        if (countO == SIZE) {
                            return 'O';
                        }
                    }

                }
            }
        }
    }
//loop that checks row in the same side
    for (side = 0; side < SIZE; side++) {
        for (row = 0; row < SIZE; row++) {
            /*initializing counters after every side change because were checking
       streak in the same side*/
            countO = 0;
            countX = 0;
            for (column = 0; column < SIZE; column++) {
                if ((array[side][row][column]) == 'O') {
                    countO++;
                    if (countO == SIZE) {
                        return 'O';
                    }
                }
                if (array[side][row][column] == 'X') {
                    countX++;
                    if (countX == SIZE) {
                        return 'X';
                    }
                }
            }
        }
    }
//loop that checks diagonal in the same side
    for (side = 0; side < SIZE; side++) {
        /*initializing counters after every side change because were checking
       streak in the same side*/
        countX = 0;
        countO = 0;
        for (row = 0; row < SIZE; row++) {
            if (array[side][row][row] == 'X') {
                countX++;
                if (countX == SIZE) {
                    return 'X';
                }
            }
            if (array[side][row][row] == 'O') {
                countO++;
                if (countO == SIZE) {
                    return 'O';

                }
            }
        }
    }
    //loop that checks "wide" column all over the board
    for (row = 0; row < SIZE; row++) {
        for (column = 0; column < SIZE; column++) {
            //initializing counters here because were moving to the next column
            countX = 0;
            countO = 0;
            for (side = 0; side < SIZE; side++) {
                if (array[side][row][column] == 'X')
                    countX++;
                if (countX == SIZE) {
                    return 'X';
                }
                if (array[side][row][column] == 'O')
                    countO++;
                if (countO == SIZE) {
                    return 'O';
                }
            }
        }
    }
//loop that checks rows
    for (side = 0; side < SIZE; side++) {
        /*initializing counters after every side change because were checking
       streak in the same side*/
        countX = 0;
        countO = 0;
        for (row = 0; row < SIZE; row++) {
            for (column = 0; column < SIZE; column++) {
                if (row + side == SIZE - 1) {
                    if (array[side][row][column] == 'X') {
                        countX++;
                        if (countX == SIZE) {
                            return 'X';
                        }
                    }
                    if (array[side][row][column] == 'O') {
                        countO++;
                        if (countO == SIZE) {
                            return 'O';
                        }
                    }
                }
            }
        }
    }
}

/************************************************************************
* function name: ticTacToe
* The Input: officially nothing but actually taking the user input
* The output: the game result, win tie, or incorrect input if there was
* The Function operation: the fucntion "runs" the game, it takes the input
 * from the user, checks if its valid, if it is so it makes the play and
 * call the checkWin function if it is a win or an tie the function will print
 * it and end the game,else it will keep taking input from the user untill it
 * will get to a final situation(win tie or an incorrect input).
*************************************************************************/
int ticTacToe() {
    printf("\nPlease enter your game sequence.");
    //initializing array to contain the game sequence
    char array[SIZE][SIZE][SIZE] = {};
    int side, row, column;
    //filling the array with stars as needed
    for (side = 0; side < SIZE; side++) {
        for (row = 0; row < SIZE; row++) {
            for (column = 0; column < SIZE; column++) {
                array[side][row][column] = '*';
            }
        }
    }
    int index = 0;
    //taking user input until all the slots are full
    while (index <= SLOTS) {
        scanf(" %d", &side);
        scanf(" %d", &row);
        scanf(" %d", &column);
        //checking if input valid-between 0 and 3
        if (side < 0 || row < 0 || column < 0) {
            printf("\nInput incorrect.");
            return 0;
        }
        if (side >= SIZE || row >= SIZE || column >= SIZE) {
            printf("\nInput incorrect.");
            return 0;
        }
        //checking if the slot that the user wanna fill is free and not taken
        if (array[side][row][column] != '*') {
            printf("\nInput incorrect.");
            return 0;
        }
        /*first turn always for X so checking whos turn it is each time to know
        what to fill*/
        if (index % 2 == 1) {
            array[side][row][column] = 'O';
        } else {
            array[side][row][column] = 'X';
        }
        index++;
        char score;
        //checking if the game is over
        score = checkScore(array);
        if (score == 'X') {
            printf("\nX is the winner.");
            //printing the game table as needed
            printTable(array);
            return 0;
        }
        if (score == 'O') {
            printf("\nO is the winner.");
            //printing the game table as needed
            printTable(array);
            return 0;
        }
        if (index == SLOTS) {
            //if all the slots are full and there is no win declaring it an tie
            printf("\nTie.");
            printTable(array);
            return 0;
        }

    }
}

int main() {
    printf("Would you like to start? (y/n)");
    char input;
    //taking user input as long as its not an no
    while (1) {
        scanf(" %c", &input);
        if (input == 'y') {
            //calling the function thats run the game
            ticTacToe();
            printf("\nWould you like to continue? (y/n)");
        }
        //ending program if needed
        if (input == 'n') {
            printf("\nYEET");
            break;

        }
    }
    return 0;
}
