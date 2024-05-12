#include <iostream>
using namespace std;

int func(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return n + func(n - 1);
    return 2 * func(n - 2);
}

int main() {
    cout << func(24) << endl;
    return 0;
}