#include <iostream>

using namespace std;

int main()
{
    int grades[50];
    int size = 0;

    cout << "How many grades do you have?";
    cin >> size;

    for (int i = 0; i < size; ++i)
    {
        cout << "Enter a Grade between 0 and 100:";
        cin >> grades[i];
        while (grades[i] < 0 || grades[i] > 100)
        {
            cout << "Please enter a grade within the correct range: ";
            cin >> grades[i];
        }
    }

    return 0;
}