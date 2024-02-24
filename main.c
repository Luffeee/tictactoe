#include <stdio.h>

void displayBoard(char board[3][3]);
int playerInput(char board[3][3], char player, int choice);
int checkWin(char board[3][3]);

int main() {
  char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
  };

  int player = 1;
  int choice;
  int gameStatus;

  do {
    displayBoard(board);

    do {
      printf("Player %d, enter your choice: ", player);
      scanf("%d", &choice);
    } while (!playerInput(board, (player==1) ? 'X' : 'O', choice));

  gameStatus = checkWin(board);
  if (gameStatus != -1 || gameStatus == 0) {
    break;
  }
  player = (player%2) + 1;

  } while (1);

  if (gameStatus == 1) {
    displayBoard(board);
    printf("Player %d wins!\n", (player == 1) ? 1 : 2);
  } else {
    displayBoard(board);
    printf("Tie!\n");
  } 

  return 0;
}

void displayBoard(char board[3][3]) {
  printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int playerInput(char board[3][3], char player, int choice) {
  if (choice < 1 || choice > 9) {
    printf("\nInvalid move, try again.\n");
    return 0;
  }
  int row, col;

  choice--;
  row = choice / 3;
  col = choice % 3;

  if (board[row][col] != 'X' && board[row][col] != 'O') {
    board[row][col] = player;
    return 1;
  } else {
    printf("\nInvalid move, try again.\n");
    return 0;
  }
}

int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return -1;
            }
        }
    }

    return 0;
} 