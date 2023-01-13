#include <iostream>
#include <ctime>


using namespace std;

// Функция для вывода Матрицы
void PrintMatrix(int** Matrix, int LineCount, int ColumnCount)
{
    for (int y = 0; y < LineCount; y++){
        for (int x = 0; x < ColumnCount; x++)
            cout << Matrix[y][x] << '\t';
        cout << endl;
    }
}

// Функция Автоматического заполнения Матрицы
void AutoFill(int** Matrix, int LineCount, int ColumnCount)
{
    srand(time(0));
    for (int y = 0; y < LineCount; y++)
        for (int x = 0; x < ColumnCount; x++)
            Matrix[y][x] = rand() % 21;
}

// Функция заполнения Матрицы Вручную
void ManualFill(int** Matrix, int LineCount, int ColumnCount)
{
    for (int y = 0; y < LineCount; y++)
        for (int x = 0; x < ColumnCount; x++){
            cout << "Enter element[" << y << "][" << x << "]: ";
            cin >> Matrix[y][x];
        }
}

// Функция заполнения TargetMatrix из SourceMatrix методом транспонирования.
void Transpond(int** SourceMatrix, int SourceLineCount, int SourceColumnCount, int** TargetMatrix){
    for (int i = 0; i < SourceLineCount; i++)
        for (int j = 0; j < SourceColumnCount; j++)
            TargetMatrix[j][i] = SourceMatrix[i][j];
}

// Функция проверки двух Матрицы на Симметричность
bool IsMatrixSimetric(int** Matrix,          int LineCount,  int ColumnCount,
                      int** TranspondMatrix, int LineCountT, int ColumnCountT)
{
    // Если количество строк или количество столбцов в матрицах не равны, то Матрица точно не симетрическая (Результат ЛОЖЬ)
    if (LineCount != LineCountT || ColumnCount != ColumnCountT) return false;

    // сравниваем каждый элемент Матрицы и транспонированной матрицы
    for (int y = 0; y < LineCount; y++)
        for (int x = 0; x < LineCountT; x++)
            // Если элименты не равны, то Матрица точно не симетрическая (Результат ЛОЖЬ)
            if (Matrix[y][x] != TranspondMatrix[y][x]) return false;

    // Если программа дошла до этого момента, то все элементы равны и..
    // Матрица симетрическая (Результат ИСТИНА)
    return true;
}


int main()
{
    // Количество Строк в Массиве
    int LineCount1;
    // Количество Столбцов в Массиве
    int ColumnCount1;





    // Вводим количество строк
    cout<< "Enter  lines  count: ";
    cin >> LineCount1;
    // Вводим количество столбцов
    cout<< "Enter columns count: ";
    cin >> ColumnCount1;





    // Динамическая Матрица (указатель на массив указателей)
    int **Matrix = new int* [LineCount1];
    for (int y = 0; y < LineCount1; y++){   // проходим по каждому указателю из массива..
        Matrix[y] = new int [ColumnCount1]; // и ставим в соответствие указателю новый массив
    }




    
    // Метода заполнения массива (автоматически или вручную)
    char method;
    cout<< "\nHow fill matrix?"
        << "\nA) Auto"
        << "\nM) Manual"
        << "\nEnter method (A/M): ";
    cin >> method;





    switch (method) // Если method совпадает с одним из значений после "case", то начинает выполнять функции.
    {
    case 'M' : // если нету "break;", то выполняет операции следующего case, пока не втретит break;
    case 'm' :
        cout << "\n\nManual Fill:\n";
        ManualFill(Matrix, LineCount1, ColumnCount1);
        cout << "Complete\n";
        break;
    // если method не нашёл совпадений после в "case", то выполняется следующее действие (default - по умолчанию).
    default:
        cout << "\n\nAuto Fill:\n";
        AutoFill(Matrix, LineCount1, ColumnCount1);
        cout << "Complete\n";
        break;
    }





    // Выводим Матрицу
    cout << "\nCurrent Matrix:\n";
    PrintMatrix(Matrix, LineCount1, ColumnCount1);





    // Количество Строк в Транспонированном Массиве
    int LineCount2 = ColumnCount1;
    // Количество Столбцов в Транспонированном Массиве
    int ColumnCount2 = LineCount1;

    // Динамическая Транспонированная Матрица (указатель на массив указателей)
    int **TranspondMatrix = new int* [LineCount2];
    for (int y = 0; y < LineCount2; y++){
        // Объявляем подмассивы 
        TranspondMatrix[y] = new int [ColumnCount2];
    }






    // Заполняем Транспонированную Матрицу
    Transpond(Matrix,LineCount1,ColumnCount1,TranspondMatrix);
    // Выводим Транспонированную Матрицу
    cout << "\nTranspond Matrix:\n";
    PrintMatrix(TranspondMatrix,LineCount2,ColumnCount2);





    // Проверка Является Ли Матрица Симметрической
    if (IsMatrixSimetric(Matrix,          LineCount1, ColumnCount1,
                         TranspondMatrix, LineCount2, ColumnCount2))
    {
        cout << "The matrix is symmetric.\n";
    }
    else cout << "The matrix is not symmetric.\n";
    







    // Очистека оперативной памяти
    for (int y = 0; y < LineCount1; y++)
        // Удаляем Подмассивы
        delete[] Matrix[y];
    // Удаляем Основной массив
    delete[] Matrix;




    for (int y = 0; y < LineCount2; y++)
        // Удаляем Подмассивы
        delete[] TranspondMatrix[y];
    // Удаляем Основной массив
    delete[] TranspondMatrix;


    return 0;
}