#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // ��������� ��� �������� ����������
    double beg = 0.1, // a
           end = 0.8, // b
           k = 10,
           e = 0.0001;// ��������
    int    n = 40;
    
    for (double x = beg; x < end; x+=(end-beg)/k)
    {
        // ��������� ����� ����
        double SN=0,
               SE=0;
        

        // ��������� ����� �� ��������� ���������� ���������
        for (int i = 1; i <= n; i++){
            SN += pow(x,i)*sin(i*M_PI/4);
        }


        // ��������� ����� �� �������� ��������
        int j = 1;
        do{
            SE += pow(x,j)*sin(j*M_PI/4);
            j++;
        }while (abs(pow(x,j)*sin(j*M_PI/4)) >= e/10 || abs(pow(x,j+1)*sin((j+1)*M_PI/4)) >= e/10);
        // X���� ��������� ��� � �������� e �����, ����� A(j) �������� ����� ��� �� e/10
        // ��� ��� �� ����� ���� � ��������������, ����� ��������� �� ������ ��������� �������, �� � ��������� �� ���������.



        // ��������� �������� �� �������� �������
        double y = (x*sin(M_PI/4))/(1-2*x*cos(M_PI/4)+x*x);
        


        // �����
        cout << " X = "    << x
             << "\tSN = " << SN
             << "\tSE = " << SE
             << "\tY = "  << y 
             << endl;
        
    }
    


    return 0;
}