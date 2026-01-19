#include <iostream>
using namespace std;

void showArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int values[4] = {8, 0, 19, 11};
    showArray(values, 4);
    return 0;
}
