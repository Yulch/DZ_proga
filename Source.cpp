#include <iostream>
using namespace std;


class ArrClass
{

    int len;
    int* array;
    int* new_arr;
public:
//�����������
    ArrClass(int size)
    {
        len = size;
        array = new int[size];
        new_arr = new int[size + 1];
    }
    //����������� �����������
    ArrClass(const ArrClass& obj)
    {
        len = obj.len;
        array = new int[len];

        for (int i = 0; i < len; i++)
        {
            array[i] = obj.array[i];
        }
    }
    //����������
    ~ArrClass()
    {
        delete[] array;
    }
    //������
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
    //������
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
    //���������� �������� � ����� �������
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
    //�������� ��� ��������
    void sum(const ArrClass& obj)
    {
        for (int i = 0; i < len; i++)
        {
            array[i] += obj.array[i];
        }
    }
    //��������� ��� ��������
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