#include <iostream>
using namespace std;

int func(int n) {
    if (n == 1 || n == 2) return 5;
    return 5 * func(n - 1) - 4 * func(n - 2);
}

int main() {
    cout << func(13) << endl;
    return 0;
}