#include <iostream>
#include <cstring>


using namespace std;





int main()
{
    char string[256];
    cout << "Enter text: ";
    gets(string);
    
    int length = strlen(string);
    int Count=0;

    // Проходим по Всей Строке
    for (int i=0; i < length; i++)
        // Если Символ находится в таблице между 0 - 9 (включительно)..
        if (string[i] >= '0' && string[i] <= '9')
            // То увеличиваем счётчик
            Count++;
    
    

    int LastChanged = -1;
    for (int i = 0; i < Count; i++)
    {
        // Заменяемый элемент
        int target = -1;
        // Заменяющий элемент
        int source = target;
        // Проверка изменялся ли source
        bool flag = false;
        for (int c = LastChanged+1; c < length; c++)
        {
            if (string[c] >= '0' && string[c] <= '9')
            {
                if (target == -1){
                    target = c;
                }
                else if (source == -1){
                    source = c;
                    flag = true;
                }
                else if (string[source] <= string[c] && string[target] <= string[c]){
                    source = c;
                    flag = true;
                }
            }
            
        }

        if (flag)
        {
            // Память
            int tmp = string[target];
            // Обмен между source и target
            string[target] = string[source];
            string[source] = tmp;
            LastChanged = target;
        }
        
    }
    cout << "Changed string:\n" << string;
    return 0;
}