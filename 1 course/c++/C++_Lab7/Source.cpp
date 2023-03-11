#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
template<class T>
class Matrix
{
private:
    T** m_iArr;
    int size_row;
    int size_col;
public:
    //конструктор за замовчуванням
    Matrix()
    {
        size_col = 0;
        size_row = 0;
        m_iArr = new T * [size_row];
        for (int i = 0; i < size_row; i++)
        {
            m_iArr[i] = new T[size_col];
            for (int j = 0; j < size_col; j++)
            {
                m_iArr[i][j] = 0;
            }
        }

    };
    //конструктор з параметрами
    Matrix(int size_row_BuUser, int size_col_BuUser)
    {

        size_row = size_row_BuUser;
        size_col = size_col_BuUser;
        m_iArr = new T * [size_row];
        for (int i = 0; i < size_row; i++)
        {
            m_iArr[i] = new T[size_col];
            for (int j = 0; j < size_col; j++)
            {
                m_iArr[i][j] = 0;
            }
        }
        cout << "RANDOM->1\nManual->2" << endl << endl;
        cout << "Please enter: ";
        int l = 1;
        cin >> l;
        cout << endl;
        int value = 0;
        system("cls");
        switch (l)
        {
        case 1:
            srand(time(NULL));
            for (int i = 0; i < size_row; i++)
                for (int j = 0; j < size_col; j++)
                {
                    m_iArr[i][j] = (rand() % 100) - 10;
                } 
            cout << "MARTIX" << endl;
            for (int i = 0; i < size_row; i++)
            {
                for (int j = 0; j < size_col; j++)
                {
                    cout << setw(5) << m_iArr[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 2:
            for (int i = 0; i < size_row; i++)
                for (int j = 0; j < size_col; j++)
                {
                    cout << "a[" << i + 1 << "]" << "[" << j + 1 << "]" << "= ";
                    cin >> m_iArr[i][j];
                }
            cout << "\tMATRIX" << endl;
            for (int i = 0; i < size_row; i++)
            {
                for (int j = 0; j < size_col; j++)
                {
                    cout << m_iArr[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
    };

    //деструктор
    ~Matrix()
    {
        for (int j = 0; j < size_row; j++)
        {
            delete m_iArr[j];
        }
        delete[] m_iArr;
    };


    //підрахунок знакозмінності і визначення в якому рядку найбільше і виведення на екран
    void foo24()
    {
        int max = 0;
        int counter = 0;
        int *dyn = new int [size_row];
        for (int i = 0; i < size_row; i++)
        {
            dyn[i] = 0;
        }
        for (int i = 0; i < size_row; i++)
        {
            for (int j = 0; j < size_col; j++)
            {
                if (m_iArr[i][j] >= 0 && m_iArr[i][j] % 2 == 1)
                {
                    dyn[i]++;
                    continue;
                }
                else break;
            }
        }
        for (int i = 0; i < size_row; i++)
        {
            if (dyn[i] > max) 
            { 
                max = dyn[i]; 
                counter = i;
            }
            cout << "Count of identical positive odd elements - "<< dyn[i] << " of " << i <<" series" << endl;
        }
        cout << "\n->>The longest series of identical positive odd elements - " << ++counter << endl;
        delete[] dyn;
    };
};

int main(void)
{
    int row, col;
    cout << "Rows = ";
    cin >> row;
    cout << endl;
    cout << "Columns = ";
    cin >> col;
    cout << endl;
    Matrix<int> m(row, col);
    m.foo24();
    return 0;
}
