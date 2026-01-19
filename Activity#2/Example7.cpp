    #include <iostream>
    using namespace std;

    float average(int arr[], int size)
    {
        int sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }

        return sum / (float)size;
    }

    int main()
    {
        int scores[6] = {80, 85, 90, 75, 95, 115};
        cout << "The average number is: " << average(scores, 6);
        return 0;
    }
