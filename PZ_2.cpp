#include <iostream>
using namespace std;

template <class T>
class MasNazvanie
{
    int len;
    T* arr;
public:
   MasNazvanie(int lenght)
   {
       len = lenght;
       arr = new T[len];
   }
   MasNazvanie(const MasNazvanie& obj)
   {
       len = obj.len;
       arr = new T[len];

       for (int i = 0; i < len; i++)
       {
           arr[i] = obj.arr[i];
       }
   }
   ~MasNazvanie()
   {
       delete[] arr;
   }
   void setArray(int num, T value)
   {
       if ((num < 0) || (num >= len)) throw out_of_range("out of array (set)");
       arr[num] = value;
   }
   T getArray(int num)
   {
       if ((num < 0) || (num >= len)) throw out_of_range("out of array (get)");
       return arr[num];
   }
   void Sum(const MasNazvanie& obj, const MasNazvanie& obj1)
   {
       T* newArray;
       if (obj.len < obj1.len)
       {
           len = obj1.len;
           newArray = new T[obj1.len];
           for (int i = 0; i < obj.len; i++)
           {
               newArray[i] = obj.arr[i] + obj1.arr[i];
           }
           for (int i = obj.len; i < obj1.len; i++)
           {
               newArray[i] = obj1.arr[i];
           }
       }
       else
       {
           len = obj.len;
           newArray = new T[obj.len];
           for (int i = 0; i < obj1.len; i++)
           {
               newArray[i] = obj1.arr[i] + obj1.arr[i];
           }
           for (int i = obj1.len; i < obj.len; i++)
           {
               newArray[i] = obj.arr[i];
           }
       }
       delete[] arr;
       arr = newArray;
   }
   void Sub(const MasNazvanie& obj, const MasNazvanie& obj1)
   {
       T* newArray;
       if (obj.len < obj1.len)
       {
           len = obj1.len;
           newArray = new T[obj1.len];
           for (int i = 0; i < obj.len; i++)
           {
               newArray[i] = obj.arr[i] - obj1.arr[i];
           }
           for (int i = obj.len; i < obj1.len; i++)
           {
               newArray[i] = obj1.arr[i];
           }
       }
       else
       {
           len = obj.len;
           newArray = new T[obj.len];
           for (int i = 0; i < obj1.len; i++)
           {
               newArray[i] = obj1.arr[i] - obj1.arr[i];
           }
           for (int i = obj1.len; i < obj.len; i++)
           {
               newArray[i] = obj.arr[i];
           }
       }
       delete[] arr;
       arr = newArray;
   }
   void random()
   {
       for (int i = 0; i < len; i++)
       {
           arr[i] = rand() % 100;
       }
   }
   void push_back(int value)
   {
       if (value >= -100 && value <= 100)
       {
           T* newArray = new T[len + 1];
           for (int i = 0; i < len; i++)
           {
               newArray[i] = arr[i];
           }
           newArray[len] = value;
           len++;
           delete[] arr;
           arr = newArray;
       }
       else cout << "Error" << endl;
   }
   void output()
   {
       for (int i = 0; i < len; i++)
       {
           cout << arr[i] << "\t";
       }
       cout << endl;
   }
   MasNazvanie& operator=(const MasNazvanie& obj);
   template <class T>
   friend ostream& operator<<(ostream& out,MasNazvanie<T>& obj);
   template <class T>
   friend double distance(const MasNazvanie<T>& obj1, const MasNazvanie<T>& obj2);
};


template <class T>
MasNazvanie<T>& MasNazvanie<T>::operator=(const MasNazvanie& obj)
{
    if (this == &obj)
    {
        return *this;
    }
    if (arr)
    {
        delete[] arr;
    }
    len = obj.len;
    arr = new T[obj.len];
    for (int i = 0; i < obj.len; i++)
    {
        arr[i] = obj.arr[i];
    }
    return *this;
}


template <class T>
ostream& operator<<(ostream& out,MasNazvanie<T>& obj)
{
    out << "Длина массива: " << obj.len << endl << "Элементы: ";

    for (int i = 0; i < obj.len; i++)
    {
        out << obj.arr[i] << "\t";
    }
    out << endl;
    return out;
}


template <class T>
double distance(const MasNazvanie<T>& obj1, const MasNazvanie<T>& obj2)
{
    throw logic_error("Массив должен быть int");
}
template <>
double distance(const MasNazvanie<int>& obj1, const MasNazvanie<int>& obj2)
{
    if (obj1.len != obj2.len)
    {
        cout << "Размера массивов не равны!" << endl;
    }
    else
    {
        double dist = 0.0;
        for (int i = 0; i < obj1.len; i++)
        {
            dist += (obj1.arr[i] - obj2.arr[i]) * (obj1.arr[i] - obj2.arr[i]);
        }
        cout << "Расстояние между массивами: " << sqrt(dist) << endl;
        return sqrt(dist);
    }
}


template <>
void MasNazvanie<int>::setArray(int num, int value)
{
    if ((num < 0) || (num >= len)) throw out_of_range("out of array");
    if ((value < -100) || (value > 100)) throw invalid_argument("out of borders");
    arr[num] = value;
}

int main()
{
    setlocale(LC_ALL, "ru");
    try 
    {
        MasNazvanie<int> arr1(5), arr2(8), arr3(11);
        arr1.random();
        arr2.random();
        arr3.random();
        arr1.setArray(1, 5);
        arr2.getArray(4);
        arr2.push_back(3);
        arr3.Sum(arr1, arr2);
        arr3.Sub(arr1, arr2);
        arr1.output();
        arr2.output();
        arr3.output();
        arr3 = arr1;
        arr3.output();
        cout << arr3 << endl;
        distance(arr1, arr2);
    }
    catch (bad_alloc exception)
    {
        cerr << exception.what() << endl;
    }
    catch (out_of_range exception)
    {
        cerr << exception.what() << endl;
    }
    catch (invalid_argument exception)
    {
        cerr << exception.what() << endl;
    }
    catch (logic_error exception)
    {
        cerr << exception.what() << endl;
    }
    return 0;
}
