#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerscore = 0, comscore = 0, temp;
char playerChar, compChar;

// Function to generate a random number
int generateRandNo(int n) {
    return rand() % n;
}

// Function to determine the winner and increment the score
void scoreinc(int greater) {
    if (greater == -1) {
        playerscore += 1;
    } else if (greater == 1) {
        comscore += 1;
    } else {
        printf("It's a draw\n");
    }
}

// Function to determine the result of the game
int greater(char c1, char c2) {
    if (c1 == 'r' && c2 == 'p') return 1;
    else if (c1 == 'r' && c2 == 's') return -1;
    else if (c1 == 'p' && c2 == 'r') return -1;
    else if (c1 == 'p' && c2 == 's') return 1;
    else if (c1 == 's' && c2 == 'r') return 1;
    else if (c1 == 's' && c2 == 'p') return -1;
    else return 0; // draw
}

int main() {
    srand(time(0)); // Seed the random number generator

    char arr[3] = {'r', 'p', 's'};
    printf("Welcome to rock, paper, scissor\n");
    
    for (size_t i = 0; i < 3; i++) {
        printf("Player 1's turn\n");
        printf("Choose 1 for rock, 2 for paper, 3 for scissor: ");
        scanf("%d", &temp);
        
        if (temp < 1 || temp > 3) {
            printf("Invalid choice\n");
            i--;
            continue;
        }

        playerChar = arr[temp - 1];
        printf("You chose %c\n", playerChar);

        temp = generateRandNo(3);
        compChar = arr[temp];
        printf("CPU chose: %c\n", compChar);

        int result = greater(playerChar, compChar);
        scoreinc(result);

        printf("Player score: %d\n", playerscore);
        printf("Computer score: %d\n", comscore);
    }

    if (playerscore > comscore) {
        printf("You win!\n");
    } else if (comscore > playerscore) {
        printf("Computer wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
