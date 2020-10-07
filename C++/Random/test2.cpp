#include <iostream>

using namespace std;

int main()
{
    int grades[50];
    int size=0;
    int i;
    int aGrade = 0;
    bool found = false;
    cout << "How many grades do you have?";
    cin >> size;
    for (i = 0; i < size; i++) {
    cout << "Enter a Grade between 0 and 100:";
    cin >> grades[i]; }
    insertionSort(grades, size);
    cout << "The grades sorted in ascending order:\n";
    for (i = 0; i < size; i++)
    cout << grades[i] <<endl;
    cout << "What grade do you want to find?";
    cin >> aGrade;
    found = binarySearch(grades, 0, size-1, aGrade);
    if (found) cout << "The grade was found.";
    else cout << "The grade was not found.";
}

void insertionSort(int A[], int sz)
{
for (int j = 1; j<sz; j++)
{
// At this point, theArray[0..j‐1] is sorted.
// Find the right position (i) in theArray[0..j‐1]
// for entry theArray[j], which is the first entry in
the
// unsorted region; shift, if necessary, to make room
if (A[j] < A[j ‐ 1]) {
int key = A[j];
int i = j ‐ 1;
while ((i >= 0) && (A[i] > key)) {
// Shift theArray[i] to the right
A[i + 1] = A[i];
i‐‐;
} // end while
A[i + 1] = key; // Insert key into sorted region
}
} // end for
} // end insertionSort

bool binarySearch(const int A[], int first, int last, int target)
{
int index;
if (first > last)
return false; // target not in original array
else {
// If target is in anArray, then
// anArray[first] <= target <= anArray[last]
int mid = first + (last ‐ first) / 2;
if (target == A[mid])
return true; // target found at anArray[mid]
else if (target < A[mid])
index = binarySearch(A, first, mid ‐ 1, target);
else
index = binarySearch(A, mid + 1, last, target);
} // end if
} // end binarySearch