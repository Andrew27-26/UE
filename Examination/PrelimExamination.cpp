#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <chrono>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
void countsort(vector<int> &arr) {
    int n = arr.size();
    int maxval = 0;
    for (int i = 0; i < n; i++) maxval = max(maxval, arr[i]);
    vector<int> count(maxval + 1, 0);
    for (int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 1; i <= maxval; i++) count[i] += count[i - 1];
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) arr[i] = ans[i];
}
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}
void insertionsort(vector<int> &arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

stack<int> Stack;
queue<int> Queue;
vector<int> merged;
int arr[10] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

int main()
{
    cout << "Array elements: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
        Stack.push(arr[i]);
        Queue.push(arr[i]);
    }
    cout << endl;

    cout << endl;

    cout << "Popped from Stack: ";
    for (int i = 0; i < 3; i++)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;

    cout << "Popped from Queue: ";
    for (int i = 0; i < 3; i++)
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
    cout << endl;

    cout << "Remaining Stack: ";
    stack<int> tempS = Stack;
    if (tempS.empty())
    {
        cout << "ERROR: Stack is empty!" << endl;
    }
    else
    {
        while (!tempS.empty())
        {
            cout << tempS.top() << " ";
            tempS.pop();
        }
        cout << endl;
    }

    cout << "Remaining Queue: ";
    queue<int> tempQ = Queue;
    if (tempQ.empty())
    {
        cout << "ERROR: Queue is empty!" << endl;
    }
    else
    {
        while (!tempQ.empty())
        {
            cout << tempQ.front() << " ";
            tempQ.pop();
        }
        cout << endl;
    }

    tempS = Stack;
    while (!tempS.empty())
    {
        merged.push_back(tempS.top());
        tempS.pop();
    }

    tempQ = Queue;
    while (!tempQ.empty())
    {
        merged.push_back(tempQ.front());
        tempQ.pop();
    }

    cout << "\nCombination: ";
    for (int num : merged)
        cout << num << " ";
    cout << endl
         << endl;

    vector<int> work;

    work = merged;
    auto start1 = chrono::high_resolution_clock::now();
    bubbleSort(work);
    cout << "\nBubbleSort: ";
    for (int num : work)
        cout << num << " ";
    cout << endl;

    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1);
    double ns1 = duration1.count();
    cout << "Time complexity of bubble: " << ns1 / 1000000.0 << " ms" << endl
         << endl;

    work = merged;
    auto start2 = chrono::high_resolution_clock::now();
    countsort(work);
    cout << "\nCountSort: ";
    for (int num : work)
        cout << num << " ";
    cout << endl;

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);
    double ns2 = duration2.count();
    cout << "Time complexity of count: " << ns2 / 1000000.0 << " ms" << endl
         << endl;

    work = merged;
    auto start3 = chrono::high_resolution_clock::now();
    insertionsort(work, work.size());
    cout << "\nInsertion Sort: ";
    for (int num : work)
        cout << num << " ";
    cout << endl;

    auto end3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::nanoseconds>(end3 - start3);
    double ns3 = duration3.count();
    cout << "Time complexity of insertion: " << ns3 / 1000000.0 << " ms" << endl
         << endl;

    work = merged;
    auto start4 = chrono::high_resolution_clock::now();
    selectionSort(work);
    cout << "\nSelection Sort: ";
    for (int num : work)
        cout << num << " ";
    cout << endl;

    auto end4 = chrono::high_resolution_clock::now();
    auto duration4 = chrono::duration_cast<chrono::nanoseconds>(end4 - start4);
    double ns4 = duration4.count();
    cout << "Time complexity of selection: " << ns4 / 1000000.0 << " ms" << endl;

    return 0;
}
