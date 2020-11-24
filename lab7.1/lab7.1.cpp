#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** y, const int row, const int col, const int Low, const int High);
void Print(int** y, const int row, const int col);
void Sort(int** y, const int row, const int col);
void Change(int** y, const int row1, const int row2, const int col);
void Sum(int** y, const int row, const int col, int& S);
void Count(int** y, const int row, const int col, int& S, int& k);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = 11;
	int High = 64;
	int row = 8;
	int col = 5;

	int** y = new int* [row];
	for (int i = 0; i < row; i++)
		y[i] = new int[col];


	int** x = new int* [row];
	for (int i = 0; i < row; i++)
		x[i] = new int[col];

	cout << "Оригінальний масив" << endl;
	Create(x, row, col, Low, High);
	Print(x, row, col);

	cout << "Відсортований массив" << endl;
	Sort(x, row, col);
	Print(x, row, col);

	int S = 0;
	int k = 0;

	Sum(x, row, col, S);
	cout << "Сума = " << S << endl;
	Count(x, row, col, S, k);
	cout << "Кількість елементів, які задовільняють умову = " << k << endl;
	cout << endl;

	cout << "Модифікована матриця" << endl;
	Print(x, row, col);

	for (int i = 0; i < row; i++)
		delete[] x[i];
	delete[] x;

	system("pause");
	return 0;
}

void Create(int** y, const int row, const int col, const int Low,
	const int High)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			y[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** y, const int row, const int col)
{
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << setw(4) << y[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** y, const int row, const int col)
{
	for (int i0 = 0; i0 < row - 1; i0++)
		for (int i1 = 0; i1 < row - i0 - 1; i1++)
			if ((y[i1][0] > y[i1 + 1][0])
				||
				(y[i1][0] == y[i1 + 1][0] &&
					y[i1][1] > y[i1 + 1][1])
				||
				(y[i1][0] == y[i1 + 1][0] &&
					y[i1][1] == y[i1 + 1][1] &&
					y[i1][3] > y[i1 + 1][3]))
				Change(y, i1, i1 + 1, col);
}

void Change(int** y, const int row1, const int row2, const int col)
{
	int tmp;
	for (int j = 0; j < col; j++)
	{
		tmp = y[row1][j];
		y[row1][j] = y[row2][j];
		y[row2][j] = tmp;
	}
}

void Sum(int** y, const int row, const int col, int& S)
{
	S = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (y[i][j] % 2 != 0 && !(y[i][j] % 3 == 0))
			{
				S += y[i][j];
				y[i][j] = 0;
			}
}

void Count(int** y, const int row, const int col, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (y[i][j] % 2  != 0 || !(y[i][j] % 3 == 0))
			{
				S += y[i][j];
				k++;
				y[i][j] = 0;
			}
}
