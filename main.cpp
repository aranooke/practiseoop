#include <iostream>
#include <cassert>

using namespace std;

class IntArray {
public:
    explicit IntArray(int sz = DefaultArray); // Конструктор по умолчанию с одним параментром
    IntArray(int *array,int array_size);// Конструктор для создания массива
    IntArray(IntArray &rhs);// Конструктор для копирования обьектов
    ~IntArray() {delete[] ia;};// Деструктор - освобождаем память
private:
    void init(int sz,int*array); // Функция для работы с массивом
    static const int DefaultArray = 15; // Значения конструктора по умолчанию
    int *ia; // Массив
    int _size; // Размер массива

};
// Работаем с массивом
void IntArray::init(int sz,int *array)
{
    _size = sz;
    ia = new int[_size];

    for(int i = 0;i < _size;i++)
    {

        if(!array) // Если массива не существует, то элементы массива равны нулю
        {
            ia[i] = 0;
            cout << ia[i] << endl;
        }
        else { // Если массив существует, присваиваем ему значения
            ia[i] = array[i];
            cout << ia[i] << endl;
        }
    }
}
// Интерфейс конструкторов
IntArray::IntArray(int sz) {init(sz,0);}
IntArray::IntArray(int *array,int sz){ init(sz,array);}
IntArray::IntArray(IntArray &rhs){ init(rhs._size,rhs.ia);}
class IntArrayRC // Неупорядоченный массив с проверкой границ индекса
{
    // В разработке
};

class IntSortedArray { // Упорядоченный массив без проверки
    // В разработке
};

int main()
{
    setlocale(LC_ALL,"Russian");
    int ia[10] = {0,1,2,3,4,5,6,7,8,9};
    cout << "Последовательность нулей по дефолту" << endl;
    IntArray array3(5);
    cout << "Выделение память под динамический массив" << endl;
    IntArray array1(ia,10);
    cout << "Копирование обьекта класса во второй объект" << endl;
    IntArray array2(array1);


    return 0;
}
