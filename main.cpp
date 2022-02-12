#include <iostream>
#include <cassert>

using namespace std;

class IntArray {
public:
    explicit IntArray(int sz = DefaultArray); // ����������� �� ��������� � ����� �����������
    IntArray(int *array,int array_size);// ����������� ��� �������� �������
    IntArray(IntArray &rhs);// ����������� ��� ����������� ��������
    ~IntArray() {delete[] ia;};// ���������� - ����������� ������
private:
    void init(int sz,int*array); // ������� ��� ������ � ��������
    static const int DefaultArray = 15; // �������� ������������ �� ���������
    int *ia; // ������
    int _size; // ������ �������

};
// �������� � ��������
void IntArray::init(int sz,int *array)
{
    _size = sz;
    ia = new int[_size];

    for(int i = 0;i < _size;i++)
    {

        if(!array) // ���� ������� �� ����������, �� �������� ������� ����� ����
        {
            ia[i] = 0;
            cout << ia[i] << endl;
        }
        else { // ���� ������ ����������, ����������� ��� ��������
            ia[i] = array[i];
            cout << ia[i] << endl;
        }
    }
}
// ��������� �������������
IntArray::IntArray(int sz) {init(sz,0);}
IntArray::IntArray(int *array,int sz){ init(sz,array);}
IntArray::IntArray(IntArray &rhs){ init(rhs._size,rhs.ia);}
class IntArrayRC // ��������������� ������ � ��������� ������ �������
{
    // � ����������
};

class IntSortedArray { // ������������� ������ ��� ��������
    // � ����������
};

int main()
{
    setlocale(LC_ALL,"Russian");
    int ia[10] = {0,1,2,3,4,5,6,7,8,9};
    cout << "������������������ ����� �� �������" << endl;
    IntArray array3(5);
    cout << "��������� ������ ��� ������������ ������" << endl;
    IntArray array1(ia,10);
    cout << "����������� ������� ������ �� ������ ������" << endl;
    IntArray array2(array1);


    return 0;
}
