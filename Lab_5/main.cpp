#include <iostream>
#include <ctime>


using namespace std;

// ������� ��� ������ �������
void PrintMatrix(int** Matrix, int LineCount, int ColumnCount)
{
    for (int y = 0; y < LineCount; y++){
        for (int x = 0; x < ColumnCount; x++)
            cout << Matrix[y][x] << '\t';
        cout << endl;
    }
}

// ������� ��������������� ���������� �������
void AutoFill(int** Matrix, int LineCount, int ColumnCount)
{
    srand(time(0));
    for (int y = 0; y < LineCount; y++)
        for (int x = 0; x < ColumnCount; x++)
            Matrix[y][x] = rand() % 21;
}

// ������� ���������� ������� �������
void ManualFill(int** Matrix, int LineCount, int ColumnCount)
{
    for (int y = 0; y < LineCount; y++)
        for (int x = 0; x < ColumnCount; x++){
            cout << "Enter element[" << y << "][" << x << "]: ";
            cin >> Matrix[y][x];
        }
}

// ������� ���������� TargetMatrix �� SourceMatrix ������� ����������������.
void Transpond(int** SourceMatrix, int SourceLineCount, int SourceColumnCount, int** TargetMatrix){
    for (int i = 0; i < SourceLineCount; i++)
        for (int j = 0; j < SourceColumnCount; j++)
            TargetMatrix[j][i] = SourceMatrix[i][j];
}

// ������� �������� ���� ������� �� ��������������
bool IsMatrixSimetric(int** Matrix,          int LineCount,  int ColumnCount,
                      int** TranspondMatrix, int LineCountT, int ColumnCountT)
{
    // ���� ���������� ����� ��� ���������� �������� � �������� �� �����, �� ������� ����� �� ������������� (��������� ����)
    if (LineCount != LineCountT || ColumnCount != ColumnCountT) return false;

    // ���������� ������ ������� ������� � ����������������� �������
    for (int y = 0; y < LineCount; y++)
        for (int x = 0; x < LineCountT; x++)
            // ���� �������� �� �����, �� ������� ����� �� ������������� (��������� ����)
            if (Matrix[y][x] != TranspondMatrix[y][x]) return false;

    // ���� ��������� ����� �� ����� �������, �� ��� �������� ����� �..
    // ������� ������������� (��������� ������)
    return true;
}


int main()
{
    // ���������� ����� � �������
    int LineCount1;
    // ���������� �������� � �������
    int ColumnCount1;





    // ������ ���������� �����
    cout<< "Enter  lines  count: ";
    cin >> LineCount1;
    // ������ ���������� ��������
    cout<< "Enter columns count: ";
    cin >> ColumnCount1;





    // ������������ ������� (��������� �� ������ ����������)
    int **Matrix = new int* [LineCount1];
    for (int y = 0; y < LineCount1; y++){   // �������� �� ������� ��������� �� �������..
        Matrix[y] = new int [ColumnCount1]; // � ������ � ������������ ��������� ����� ������
    }




    
    // ������ ���������� ������� (������������� ��� �������)
    char method;
    cout<< "\nHow fill matrix?"
        << "\nA) Auto"
        << "\nM) Manual"
        << "\nEnter method (A/M): ";
    cin >> method;





    switch (method) // ���� method ��������� � ����� �� �������� ����� "case", �� �������� ��������� �������.
    {
    case 'M' : // ���� ���� "break;", �� ��������� �������� ���������� case, ���� �� ������� break;
    case 'm' :
        cout << "\n\nManual Fill:\n";
        ManualFill(Matrix, LineCount1, ColumnCount1);
        cout << "Complete\n";
        break;
    // ���� method �� ����� ���������� ����� � "case", �� ����������� ��������� �������� (default - �� ���������).
    default:
        cout << "\n\nAuto Fill:\n";
        AutoFill(Matrix, LineCount1, ColumnCount1);
        cout << "Complete\n";
        break;
    }





    // ������� �������
    cout << "\nCurrent Matrix:\n";
    PrintMatrix(Matrix, LineCount1, ColumnCount1);





    // ���������� ����� � ����������������� �������
    int LineCount2 = ColumnCount1;
    // ���������� �������� � ����������������� �������
    int ColumnCount2 = LineCount1;

    // ������������ ����������������� ������� (��������� �� ������ ����������)
    int **TranspondMatrix = new int* [LineCount2];
    for (int y = 0; y < LineCount2; y++){
        // ��������� ���������� 
        TranspondMatrix[y] = new int [ColumnCount2];
    }






    // ��������� ����������������� �������
    Transpond(Matrix,LineCount1,ColumnCount1,TranspondMatrix);
    // ������� ����������������� �������
    cout << "\nTranspond Matrix:\n";
    PrintMatrix(TranspondMatrix,LineCount2,ColumnCount2);





    // �������� �������� �� ������� ��������������
    if (IsMatrixSimetric(Matrix,          LineCount1, ColumnCount1,
                         TranspondMatrix, LineCount2, ColumnCount2))
    {
        cout << "The matrix is symmetric.\n";
    }
    else cout << "The matrix is not symmetric.\n";
    







    // �������� ����������� ������
    for (int y = 0; y < LineCount1; y++)
        // ������� ����������
        delete[] Matrix[y];
    // ������� �������� ������
    delete[] Matrix;




    for (int y = 0; y < LineCount2; y++)
        // ������� ����������
        delete[] TranspondMatrix[y];
    // ������� �������� ������
    delete[] TranspondMatrix;


    return 0;
}