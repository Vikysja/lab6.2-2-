// lab 6.2(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// варіант 24

#include <iostream>
#include <iomanip>

using namespace std;
void Print(int* a, const int size, int i);
void Sort(int* a, const int size, int i, int j, int& k);
void Create(int* a, const int size, const int High, int i);

int main()
{
    srand((unsigned)time(0));
    int k = 0; // показник, чи були обміни
    const int n = 20; // кількість елементів масиву
    int a[n];
    Create(a, n, 100, 0); // створюємо масив
    cout << "start array = ";
    Print(a, n, 0); // виводимо
    Sort(a, n, 1, 0, k); // сортуємо
    cout << "sorted array = ";
    Print(a, n, 0); // виводимо

    getchar();
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

void Sort(int* a, const int size, int i, int j, int& k) // метод бульбашки (модифікований)
{
    if (a[j] < a[j + 1]) // якщо порушено порядок
    { // міняємо елементи місцями
        int tmp = a[j + 1];
        a[j + 1] = a[j];
        a[j] = tmp;
        k = 1;
    }
    if (j < size - i - 1) // j - номер поточного елемента
        Sort(a, size, i, j + 1, k); // перехід до наступного елемента
    if (k == 0) // якщо обмінів - не було,
        return; // то припиняємо процес
    if (i < size - 1) // i - лічильник ітерацій
    {
        k = 0; // показник, чи були обміни
        Sort(a, size, i + 1, 0, k); // перехід до наступної ітерації
    }
}

void Create(int* a, const int size, const int High, int i)
{
    if (i < size)
    {
        a[i] = rand() % High;
        Create(a, size, 100, i + 1);
    }
}