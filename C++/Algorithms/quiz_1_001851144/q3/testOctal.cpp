#include <iostream>

using namespace std;

void displayOctal(int n) {
if (n > 0) {
    if (n / 8 > 0)
    displayOctal(n / 8);
    cout << n % 8;
} // end if
} // end displayOctal

int main() {
    int num = 78;
    displayOctal(num);
}
