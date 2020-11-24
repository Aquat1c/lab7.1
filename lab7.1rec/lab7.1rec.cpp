
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip>

using namespace std;
void Create(int** y, const int row, const int col, const int low, const int high, int i, int j);
void Print(int** y, const int row, const int col, int i, int j);
void Sort(int** y, const int row, const int col, int i, int j);
int Count(int** y, const int row, const int col, int i, int j, int k);
void Change2(int** y, const int row, const int col, int i, int j);
int Sum(int** y, const int row, const int col, int i, int j, int S);
void Change(int** y, const int row0, const int row1, const int col);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int low = 11;
    int high = 64;

    int row = 8;
    int col = 5;
    int** y = new int* [row];
    for (int i = 0; i < row; i++)
        y[i] = new int[col];
    cout << setw(21) << "ќриг≥нальна матриц€" << endl;
    Create(y, row, col, low, high, 0, 0); cout << endl;
    Print(y, row, col, 0, 0); cout << endl;
    cout << setw(23) << "¬≥дсортована матриц€" << endl; cout << endl;
    Print(y, row, col, 0, 0); cout << endl;
    cout << "\n ≥льк≥сть елемент≥в, €к≥ задов≥льн€ють умову: ";
    cout << Count(y, row, col, 0, 0, 0) << endl; cout << endl;
    cout << "њх сума: " << Sum(y, row, col, 0, 0, 0) << endl; cout << endl;
    cout << setw(23) << "ћодиф≥кована матриц€" << endl; cout << endl;
    Change2(y, row, col, 0, 0); cout << endl; cout << endl;


    for (int i = 0; i < row; i++)
        delete[] y[i];
    delete[] y;

    return 0;
}
void Create(int** y, const int row, const int col, const int low, const int high, int i, int j)
{
    if (j < col)
    {
        y[i][j] = low + rand() % (high - low + 1);
        return Create(y, row, col, low, high, i, j + 1);
    }
    if (i < row - 1)
        return Create(y, row, col, low, high, i + 1, 0);
}
void Print(int** y, const int row, const int col, int i, int j)
{
    if (j < col)
    {
        cout << setw(4) << y[i][j];
        return Print(y, row, col, i, j + 1);
    }
    cout << endl;
    if (i < row - 1)
        return Print(y, row, col, i + 1, 0);
}
int Count(int** y, const int row, const int col, int i, int j, int k)
{
    if (j < col)
        if (((y[i][j] < 0) && !(y[i][j] % 4 == 0)))
        {
            k++;
            return Count(y, row, col, i, j + 1, k);
        }
        else
            return Count(y, row, col, i, j + 1, k);
    if (i < row - 1)
        return Count(y, row, col, i + 1, 0, k);
    return k;
}
void Change2(int** y, const int row, const int col, int i, int j)
{
    if (j < col)
    {
        if (y[i][j] % 2 != 0 && !(y[i][j] % 3 == 0))
            cout << setw(4) << 0;
        else
            cout << setw(4) << y[i][j];
        return Change2(y, row, col, i, j + 1);
    }
    if (i < row - 1)
    {
        cout << endl;
        return Change2(y, row, col, i + 1, 0);
    }
}
int Sum(int** y, const int row, const int col, int i, int j, int S)
{
    if (j < col)
        if (y[i][j] % 2 != 0 && !(y[i][j] % 3 == 0))
        {
            S += y[i][j];
            return Sum(y, row, col, i, j + 1, S);
        }
        else
            return Sum(y, row, col, i, j + 1, S);
    if (i < row - 1)
        return Sum(y, row, col, i + 1, 0, S);
    return S;
}
void Sort(int** y, const int row, const int col, int i, int j)
{
    if (j < col)
    {
        if ((y[j][0] < y[j + 1][0])
            ||
            (y[j][0] == y[j + 1][0] &&
                y[j][1] < y[j + 1][1])
            ||
            (y[j][0] == y[j + 1][0] &&
                y[j][1] == y[j + 1][1] &&
                y[j][2] < y[j + 1][2]))
            Change(y, j, j + 1, col);
        return Sort(y, row, col, i, j + 1);
    }
    if (i < row - 1)
        return Sort(y, row, col, i + 1, 0);
}
void Change(int** y, const int row0, const int row1, const int col)
{
    int temp;
    for (int k = 0; k < col; k++)
    {
        temp = y[row0][k];
        y[row0][k] = y[row1][k];
        y[row1][k] = temp;
    }
}
