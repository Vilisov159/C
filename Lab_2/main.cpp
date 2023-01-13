#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Найти сумму ряда с точностью e=0.0001, общий член которого a=(2n-1)/2^n;
    double sum = 0,
             e = 0.0001;
    
    int n = 1;
    double a = (2*n-1)/pow(2,n);
    
    while (a >= e){
        // полученный из предудущей итерации a(n), добавляем в сумму если нужная точность ещё не достигнута
        sum += a;
        printf("a(%2i) = %.5f\n", n , a );
        
        // вычисляем элемент a(n+1)
        n++;
        a = (2*n-1)/pow(2,n);
    }

    // выводим сумму
    cout << "Sum: " << sum << endl;
    
    return 0;
}