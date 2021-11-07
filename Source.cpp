#include <iostream>
using namespace std;


class ArrClass
{

    int len;
    int* array;
    int* new_arr;
public:
//конструктор
    ArrClass(int size)
    {
        len = size;
        array = new int[size];
        new_arr = new int[size + 1];
    }
    //конструктор копирования
    ArrClass(const ArrClass& obj)
    {
        len = obj.len;
        array = new int[len];

        for (int i = 0; i < len; i++)
        {
            array[i] = obj.array[i];
        }
    }
    //деструктор
    ~ArrClass()
    {
        delete[] array;
    }
    //сеттер
    void set(int number, int val)
    {
        if ((number >= 0) && (number < len))
        {
            if ((val > -100) && (val < 100))
            {
                array[number] = val;
            }
            else
            {
                cout << "Error " << endl;
            }
        }
        else
        {
            cout << "Error " << endl;
        }

    }
    //геттер
    int get(int number)
    {
        if ((number >= 0) && (number < len))
        {
            return array[number];
        }
        else
        {
            cout << "Error" << endl;
        }
    }
    //добавления значения в конец массива
    void add_element(int val)
    {
        for (int i = 0; i < len; i++) 
        {
            cout << array[i]<< "\t";
        }
        cout << endl;
        if (val >= -100 && val <= 100)
        {
            for (int i = 0; i < len; i++)
            {
                new_arr[i] = array[i];
            }
            new_arr[len] = val;
            len++;
            delete[] array;
            array = new_arr;
        }
        else cout << "Error" << endl;
        for (int i = 0; i < len; i++)
        {
            cout << array[i] << "\t";
        }
    }
    //сложение для массивов
    void sum(const ArrClass& obj)
    {
        for (int i = 0; i < len; i++)
        {
            array[i] += obj.array[i];
        }
    }
    //вычитание для массивов
    void sub(const ArrClass& obj)
    {
        for (int i = 0; i < len; i++)
        {
            array[i] -= obj.array[i];
        }
    }
      
};
int main()
{
    ArrClass u(3);
    u.add_element(5);
    return 0;
}