/*RU
Дана шахматная доска размером 8*8. На шахматной доске стоят белые и чёрные 
фигуры, текущий ход белого игрока. Вам необходимо по состоянию доски 
определить, находится ли БЕЛЫЙ король под шахом. Доска задана матрицей 
символов размеров 8 на 8, в каждой клетке которой находится:
“.” - если клетка пустая
“p” или “P” - если в клетке стоит чёрная или белая пешка соответственно
“r” или “R” - если в клетке стоит чёрная или белая ладья соответственно
“k” или “K” - если в клетке стоит чёрный или белый конь соответственно
“o” или “O” - если в клетке стоит чёрный или белый слон соответственно
“q” или “Q” - если в клетке стоит чёрный или белый ферзь соответственно
“x” или ”X” - если в клетке стоит чёрный или белый король соответственно


ENG
Given a chessboard measuring 8*8. There are white and black on the chessboard
pieces, white player's current move. You need according to the state of the board
determine whether the WHITE king is in check. The board is defined by a matrix
symbols measuring 8 by 8, each cell of which contains:
“.” - if the cell is empty
“p” or “P” - if there is a black or white pawn in the cell, respectively
“r” or “R” - if there is a black or white rook in the cell, respectively
“k” or “K” - if there is a black or white knight in the cell, respectively
“o” or “O” - if there is a black or white bishop in the cell, respectively
“q” or “Q” - if there is a black or white queen in the cell, respectively
“x” or “X” - if the cell contains a black or white king, respectively*/

#include <iostream> //импортируем библиотеку заголовочных файлов  import the library of header files
#include <vector> //импортируем библиотеку векторов  import the vector library
using namespace std; //использование имен объектов и переменных из стандартной библиотеки  using object and variable names from the standard library

/*функция KingCheck принимает состояние доски в виде двумерного массива 
(матрицы) и возвращает значение - находится король под шахом или нет 
the KingCheck function takes the state of the board as a two-dimensional array
(matrices) and returns the value - whether the king is in check or not*/

bool KingCheck(const vector < vector < char >> & board) {
	int kingRow = -1;
	int kingCol = -1;
	//данные переменные используются для хранения позиции короля на доске  
    //these variables are used to store the position of the king on the board

	// Находим позицию белого короля на доске
    //Finding the position of the white king on the board
	// цикл который ищет позицию белого короля на доске и после его нахождения сохраняет найденные значения в переменных
    //a loop that searches for the position of the white king on the board and, after finding it, stores the found values ​​in variables

	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			if (board[row][col] == 'K' || board[row][col] == 'X') {
				kingRow = row;
				kingCol = col;
				break;
			}
		}
		if (kingRow != -1) {
			break;
		}
	}

	// Проверяем есть ли угроза от пешек
    //Checking whether there is a threat from pawns
	//проверяет две клетки по диагонали от короля и если в одной из этих клеток находится черная пешка то он под угрозой
    //checks two squares diagonally from the king and if there is a black pawn in one of these squares then it is under threat

	if (kingRow > 0 && kingCol > 0 && (board[kingRow - 1][kingCol - 1] == 'p' || board[kingRow - 1][kingCol - 1] == 'P')) {
		return true;
	}
	if (kingRow > 0 && kingCol < 7 && (board[kingRow - 1][kingCol + 1] == 'p' || board[kingRow - 1][kingCol + 1] == 'P')) {
		return true;
	}

	// Проверяем есть ли угроза от ладей, ферзя или слонов
    //We check whether there is a threat from rooks, queens or bishops

	int directionRow[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int directionCol[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int i = 0; i < 8; ++i) {
		for (int j = 1; j < 8; ++j) {
			int newRow = kingRow + j * directionRow[i];
			int newCol = kingCol + j * directionCol[i];

			if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8) {
				break;
			}

			char currentPiece = board[newRow][newCol];

			if (currentPiece == 'r' || currentPiece == 'R' || currentPiece == 'q' || currentPiece == 'Q') {
				return true;
			}

			if (currentPiece != '.') {
				break;
			}
		}
	}

	// Проверяем есть ли угроза от коней
    //Checking whether there is a threat from horses
    
	int knightMovesRow[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
	int knightMovesCol[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

	for (int i = 0; i < 8; ++i) {
		int newRow = kingRow + knightMovesRow[i];
		int newCol = kingCol + knightMovesCol[i];

		if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && (board[newRow][newCol] == 'k' || board[newRow][newCol] == 'K')) {
			return true;
		}
	}

	return false;
}

int main() {
	//Вывод значения.В данном примере королю шах не угрожает и по этому выводится The white king isn't in check
    //Output of the value. In this example, the king is not threatened by check and therefore the output is The white king isn't in check
    
	vector < vector < char >> board = {
	{'p', '.', '.', '.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', '.', '.', '.', '.'},
	{'.', '.', 'K', '.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', 'r', '.', '.', '.'},
	{'.', '.', '.', '.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', '.', '.', '.', '.'}
	};

	bool Check = KingCheck(board);
	if (Check) {
		cout << "The white king is in check";
	}
	else {
		cout << "The white king isn't in check";
	}

	return 0;
}