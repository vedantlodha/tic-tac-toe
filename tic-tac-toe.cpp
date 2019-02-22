#include <iostream>
void printBoard(char board[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j == 1)
			{
				std::cout << "|" << board[i][j] << "|";
			}
			else
			{
				std::cout << board[i][j];
			}
		}
		std::cout << std::endl;
		if (i != 2)
			std::cout << "- - -" << std::endl;
	}
}
bool terminalPosition(char board[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i][j] == ' ')
			return false;
		}
	}
	return true;
}
int checkBoard(char board[3][3]){
	for (int i = 0; i < 3; i++){
		if (((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board [i] [0] != ' ') || ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) && board[1][i] != ' '){
			std::cout << "Row/column returned" << std::endl;
			return 1;
		}
	}
	if ((((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) ) || ((board[0][2] == board[1][1]) && board[1][1] == board[2][0]) && board[1][1] != ' '){
		std::cout << "diagonal returned" << std::endl;
		return 1;
	}
	return 0;
}
void nextTurn(int *player1, int *player2)
{
	*player1 = !(*player1);
	*player2 = !(*player2);
}
void game(char board[3][3], int player1, int player2)
{
	while (1)
	{
		int gameVal = 0;
		nextTurn(&player1, &player2);
		printBoard(board);
		int nextPlayer = (player1 == 1) ? 1 : 2;
		int movechar = (nextPlayer == 1) ? 'X' : 'O';
		std::cout << "player " << nextPlayer << "'s turn:\n";
		int m, n;
		while (1)
		{
			if (terminalPosition(board))
			{
				std::cout << "Its a tie";
				return;
			}
			std::cout << "\nEnter the location for the move:";
			std::cin >> m >> n;
			m--;
			n--;
			if(m<0 || m>2 || n<0 || n>2){
				std::cout<<"Invalid Entry. Please try again.\n";
			}
			else if (board[m][n] != ' ')
			{
				std::cout << "sorry, That is not an empty box\n";
			}
			else
			{
				board[m][n] = movechar;
				//noOfMoves++;

				break;
			}
		}
		gameVal = checkBoard(board);
		if (gameVal == 1)
		{
			std::cout<<"\n\n\n";
			printBoard(board);
			std::cout << "The winner is player " << nextPlayer << "\nGame Ends\n";
			return;
		}
	}
}
int main()
{
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	int player1, player2;
	player1 = 0;
	player2 = 1;
	std::cout<<"Player 1 ---> X\nPlayer 2 ---> O\n";
	game(board, player1, player2);
}
