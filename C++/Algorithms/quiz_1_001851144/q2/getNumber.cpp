#include <array>
#include <iostream>

using namespace std;

int getNumberEqual(const int x[], int n, int desiredValue) {
int count = 0;
if (n <= 0)
    return 0;
else {
    if (x[n - 1] == desiredValue)
    count = 1;
    return getNumberEqual(x, n - 1, desiredValue) + count;
} // end else
} // end getNumberEqual

int main() {
    int m[] = {1, 3, 5, 9, 20, 25, 30, 30, 29, 30, 1, 30};
    cout << getNumberEqual(m, 12, 1);
}
