#include <iostream>
using namespace std;

int ChickenDinner(int arr[], int Maxxx)
{
    int Winner = arr[0];

    for (int i = 1; i < Maxxx; i++)
    {
        if (arr[i] > Winner)
            Winner = arr[i];
    }
    return Winner;
}

int main()
{
    int data[4] = {6, 9, 67, 420};
    cout << " The maximum number isssss: " << ChickenDinner(data, 4);
    return 0;
}
