#include <iostream>
#include <iomanip>
using namespace std;
class matrix
{
public:
    int **mat, r, c;
    matrix(int rows = 3, int cols = 3)
    {
        r = rows, c = cols;
        mat = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new int[cols];
        }
    }
    matrix(matrix &m)
    {
        mat = new int *[m.r];
        for (int i = 0; i < m.r; i++)
        {
            mat[i] = new int[m.c];
            for (int j = 0; j < c; j++)
            {
                mat[i][j] = m.mat[i][j];
            }
        }
    }
    void readmat(void)
    {
        cout << "Input matrix (size=" << r << "*" << c << "): " << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> mat[i][j];
            }
        }
    }
    void show(void)
    {
        cout << "showing method of matrix class" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~matrix()
    {
        for (int i = 0; i < r; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }
};
class matrixA : public matrix
{
public:
    void show(void)
    {
        cout << "showing method of matrix A class" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
class matrixB : public matrixA
{
public:
    void show(void)
    {
        cout << "showing method of matrixB class" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main(void)
{
    cout << "Creating matrix class object" << endl;
    matrix M;
    M.readmat();
    M.show();
    cout << "<" << setw(50) << setfill('*') << ">";
    cout << endl;
    cout << "Creating matrix A class object" << endl;
    matrixA MA;
    MA.readmat();
    MA.show();
    cout << setw(50) << setfill('*');
    cout << endl;
    cout << "Creating matrix B class object" << endl;
    matrixB MB;
    MB.readmat();
    MB.show();
}