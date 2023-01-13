#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Задание 1
    // -- Все переменные типа float
    float a_f=100, b_f= 0.001;
    
    // ---- Промежуточные вычисления
    float V1_f = pow(a_f + b_f, 4), // функция pow(x,y) из библиотеки cmath нужна для возведения x в степень y
          V2_f = pow(a_f,4) + 4*pow(a_f,3)*b_f + 6*pow(a_f,2)*pow(b_f,2),
          V3_f = 4*a_f*pow(b_f,3) + pow(b_f,4);
    
    // ---- Вычисление результата
    float res_f = (V1_f - V2_f) / V3_f;

    //printf("float A: %g\n", a_f);     // Более точный вывод
    //printf("float B: %g\n", b_f);     // 
    //printf("float V1: %.8f\n", V1_f); // 
    //printf("float V2: %.8f\n", V2_f); // 
    //printf("float V3: %.13f\n", V3_f); // 
    //printf("float Result: %.16f\n\n", res_f); // 
    
    cout << "FLOAT"<< endl;
    cout << "A: "  <<  a_f << endl;
    cout << "B: "  <<  b_f << endl;
    cout << "V1: " << V1_f << endl;
    cout << "V2: " << V2_f << endl;
    cout << "V3: " << V3_f << endl;
    cout << "Result: " << res_f << "\n\n";
    //

    // -- Все переменные типа double
    double a_d=100, b_d=0.001;

    // ---- Промежуточные вычисления
    double V1_d = pow(a_d + b_d, 4), // функция pow(x,y) из библиотеки cmath нужна для возведения x в степень y
           V2_d = pow(a_d,4) + 4*pow(a_d,3)*b_d + 6*pow(a_d,2)*pow(b_d,2),
           V3_d = 4*a_d*pow(b_d,3) + pow(b_d,4);

    // ---- Вычисление результата
    double res_d = (V1_d - V2_d)/V3_d;

    //printf("double A: %g\n", a_d);     // Более точный вывод
    //printf("double B: %g\n", b_d);     // 
    //printf("double V1: %.8f\n", V1_d); // 
    //printf("double V2: %.8f\n", V2_d); // 
    //printf("double V3: %.13f\n", V3_d); // 
    //printf("double Result: %.16f\n\n", res_d); // 

    cout <<"DOUBLE"<< endl;
    cout << "A: "  <<  a_d << endl;
    cout << "B: "  <<  b_d << endl;
    cout << "V1: " << V1_d << endl;
    cout << "V2: " << V2_d << endl;
    cout << "V3: " << V3_d << endl;
    cout << "Result: " << res_d << "\n\n";

    // Разнецу между Float и Double можно объяснить разным "размер" выделяемой памяти (Double > float)...
    // Из-за этого и разная точность вычислений...
    // А может и не только это.





    // Задание 2
    int n,m;
    n=0; m=0; printf("n++ - m = %d\n", n++-m);  // если написать n++ - m, то сначала выполнится "-", а уже после "++"(постфиксная операция увеличивает операнд после его использования)
    n=0; m=0; printf("m-- > n = %d\n", m-- >n); // если написать n-- > m, то сначала выполнится ">", а уже после "--"(постфиксная операция увеличивает операнд после его использования)
    n=0; m=0; printf("n-- > m = %d\n", n-- >m); // подобно предудыдущему



    return 0;
}