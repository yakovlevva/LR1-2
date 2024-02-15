#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double task(double* arr, int n)
{
    double sum = 0;

    int first = 0, second = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            first = i;
            break;
        }
    }

    for (int i = n; i >=0; i--)
    {
        if (arr[i] == 0)
        {
            second = i;
            break;
        }
    }

    if (second != 0)
    {
        for (int i = first; i < second; i++)
            sum += arr[i];
    }
    else
        cout << "Sum is empty!\n";

    return sum;

}

double checkelem(int n)
{
    double elem;

    cout << "Type element: ";

    while (true)
    {
        try
        {
            if (!(cin >> elem))
            {
                cin.clear();

                while (cin.get() != '\n');

                throw "element is non digit!";
            }
            else
                break;
        }

        catch (const char* exception)
        {
            cout << exception << '\n';

            cout << "Type new element: ";
        }
    }
    return elem;
}


int sizechecker(int n)
{
    while (true)
    {
        try
        {
            if (!(cin >> n)) // проверка на букву или спец.символы
            {
                cin.clear();

                while (cin.get() != '\n');

                throw "Size is non digit!";
            }
            else
                if (n <= 0 || n > 10)
                    throw "Size is out of range!";
                else
                    break;

        }

        catch (const char* exception)
        {
            cout << exception << '\n';

            cout << "Type new size: ";
        }
    }
    return n;
}

int main()
{
    int n = 0;

    double t;

    cout << "Type size of the array: ";

    n = sizechecker(n);

    double* arr = new double[n];

    cout << "Type elements of the array: \n";

    for (int i = 0; i < n; i++)
        arr[i] = checkelem(n);

    t = task(arr, n);

    cout << "Sum: " << t;

    delete[] arr;

    return 0;
}
