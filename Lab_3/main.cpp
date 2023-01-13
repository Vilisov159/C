#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Объявляем все заданные переменные
    double beg = 0.1, // a
           end = 0.8, // b
           k = 10,
           e = 0.0001;// точность
    int    n = 40;
    
    for (double x = beg; x < end; x+=(end-beg)/k)
    {
        // Объявляем суммы ряда
        double SN=0,
               SE=0;
        

        // Вычисляем сумму по заданному количеству элементов
        for (int i = 1; i <= n; i++){
            SN += pow(x,i)*sin(i*M_PI/4);
        }


        // Вычисляем сумму по заданной точности
        int j = 1;
        do{
            SE += pow(x,j)*sin(j*M_PI/4);
            j++;
        }while (abs(pow(x,j)*sin(j*M_PI/4)) >= e/10 || abs(pow(x,j+1)*sin((j+1)*M_PI/4)) >= e/10);
        // Xтобы результат был с точностю e нужно, чтобы A(j) менялось менее чем на e/10
        // Так как мы имеем дело с тригонометрией, лучше проверять не только следующий элемент, но и следующий за мледующим.



        // Вычисляем значение по заданной функции
        double y = (x*sin(M_PI/4))/(1-2*x*cos(M_PI/4)+x*x);
        


        // Вывод
        cout << " X = "    << x
             << "\tSN = " << SN
             << "\tSE = " << SE
             << "\tY = "  << y 
             << endl;
        
    }
    


    return 0;
}