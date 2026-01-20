#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <typename Func>
void measurePerformance(string taskName, Func func)
{
    auto start = chrono::high_resolution_clock::now();

    func();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\n[" << taskName << "] Execution time: " << duration.count() << " microseconds" << endl;
}

void insertionsort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void greet()
{
    cout << "\nHello from Jerick Dionisio Pogi! hehe";
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    measurePerformance("Insertion Sort", [&]()
                       { insertionsort(arr, n); });

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }

    measurePerformance("Greet Function", []()
                       { greet(); });

    return 0;
}