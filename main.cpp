// Made by Damir Alyukov

#include <Windows.h>
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

char choosePlayer()
{
	srand(time(0));

	int temp = rand() % 2;

	return temp == 0 ? 'X' : 'O';
}

void Draw(char border[3][3])
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		cout << "| ";
		for (int j = 0; j < 3; j++)
			cout << border[i][j] << " | ";
		cout << endl;
	}
}

void Input(char border[3][3], int &turn, char *curretPlayer)
{
	cout << *curretPlayer << "'s turn: ";
	cin >> turn;

	if (turn >= 1 && turn <= 9)
	{
		if (turn == 1 && border[0][0] == '1')
			border[0][0] = *curretPlayer;
		else if (turn == 2 && border[0][1] == '2')
			border[0][1] = *curretPlayer;
		else if (turn == 3 && border[0][2] == '3')
			border[0][2] = *curretPlayer;
		else if (turn == 4 && border[1][0] == '4')
			border[1][0] = *curretPlayer;
		else if (turn == 5 && border[1][1] == '5')
			border[1][1] = *curretPlayer;
		else if (turn == 6 && border[1][2] == '6')
			border[1][2] = *curretPlayer;
		else if (turn == 7 && border[2][0] == '7')
			border[2][0] = *curretPlayer;
		else if (turn == 8 && border[2][1] == '8')
			border[2][1] = *curretPlayer;
		else if (turn == 9 && border[2][2] == '9')
			border[2][2] = *curretPlayer;
		else
		{
			cout << "This turn is already used!" << endl;
			Input(border, turn, curretPlayer);
		}
	}
	else
	{
		cout << "Unlegal turn!" << endl;
		Input(border, turn, curretPlayer);
	}
}

char Check(char border[3][3])
{
	if (border[0][0] == 'X' && border[0][1] == 'X' && border[0][2] == 'X')
		return 'X';
	if (border[1][0] == 'X' && border[1][1] == 'X' && border[1][2] == 'X')
		return 'X';
	if (border[2][0] == 'X' && border[2][1] == 'X' && border[2][2] == 'X')
		return 'X';
	if (border[0][0] == 'X' && border[1][0] == 'X' && border[2][0] == 'X')
		return 'X';
	if (border[0][1] == 'X' && border[1][1] == 'X' && border[2][1] == 'X')
		return 'X';
	if (border[0][2] == 'X' && border[1][2] == 'X' && border[2][2] == 'X')
		return 'X';
	if (border[0][0] == 'X' && border[1][1] == 'X' && border[2][2] == 'X')
		return 'X';
	if (border[0][2] == 'X' && border[1][1] == 'X' && border[2][0] == 'X')
		return 'X';
	if (border[0][0] == 'O' && border[0][1] == 'O' && border[0][2] == 'O')
		return 'O';
	if (border[1][0] == 'O' && border[1][1] == 'O' && border[1][2] == 'O')
		return 'O';
	if (border[2][0] == 'O' && border[2][1] == 'O' && border[2][2] == 'O')
		return 'O';
	if (border[0][0] == 'O' && border[1][0] == 'O' && border[2][0] == 'O')
		return 'O';
	if (border[0][1] == 'O' && border[1][1] == 'O' && border[2][1] == 'O')
		return 'O';
	if (border[0][2] == 'O' && border[1][2] == 'O' && border[2][2] == 'O')
		return 'O';
	if (border[0][0] == 'O' && border[1][1] == 'O' && border[2][2] == 'O')
		return 'O';
	if (border[0][2] == 'O' && border[1][1] == 'O' && border[2][0] == 'O')
		return 'O';
	if (border[0][0] != '1' && border[0][1] != '2' && border[0][2] != '3'
		&& border[1][0] != '4' && border[1][1] != '5' && border[1][2] != '6'
		&& border[2][0] != '7' && border[2][1] != '8' && border[2][2] != '9')
		return 'D';
}

void Toogle(char *curretPlayer)
{
	*curretPlayer == 'X' ? *curretPlayer = 'O' : *curretPlayer = 'X';
}

int main()
{
	SetConsoleTitle("Tic Tac Toe");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);

	char border[3][3] = {
		'1', '2', '3',
		'4', '5', '6',
		'7', '8', '9'
	};

	char curretPlayer = choosePlayer();
	int turn = 0;

	while (true)
	{
		Draw(border);
		Input(border, turn, &curretPlayer);
		if (Check(border) == 'X')
		{
			Draw(border);
			cout << "X wins!" << endl;
			break;
		}
		else if (Check(border) == 'O')
		{
			Draw(border);
			cout << "O wins!" << endl;
			break;
		}
		else if (Check(border) == 'D')
		{
			Draw(border);
			cout << "It's a draw!" << endl;
			break;
		}
		else
		{
			Toogle(&curretPlayer);
		}
	}
	
	return 0;
}