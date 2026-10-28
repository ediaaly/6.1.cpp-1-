#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Формування масиву
void Create(int* t, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        t[i] = Low + rand() % (High - Low + 1);
}

// Виведення масиву
void Print(int* t, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << t[i];

    cout << endl;
}

// Перевірка умови
bool Check(const int x)
{
    return x <= 0 && x % 5 != 0;
}

// Обчислення кількості елементів
int Count(int* t, const int size)
{
    int k = 0;

    for (int i = 0; i < size; i++)
    {
        if (Check(t[i]))
            k++;
    }

    return k;
}

// Обчислення суми елементів
int Sum(int* t, const int size)
{
    int s = 0;

    for (int i = 0; i < size; i++)
    {
        if (Check(t[i]))
            s += t[i];
    }

    return s;
}

// Заміна елементів нулями
void Replace(int* t, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (Check(t[i]))
            t[i] = 0;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int size = 22;
    int t[size];

    const int Low = -20;
    const int High = 37;

    Create(t, size, Low, High);

    cout << "Original array:" << endl;
    Print(t, size);

    int k = Count(t, size);
    int s = Sum(t, size);

    cout << "Count = " << k << endl;
    cout << "Sum = " << s << endl;

    Replace(t, size);

    cout << "Modified array:" << endl;
    Print(t, size);

    return 0;
}