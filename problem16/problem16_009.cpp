#include <iostream>
using namespace std;

int lucas(int n) {
    if (n > 2) {
        return lucas(n - 2) + lucas(n - 1);
    }
    if (n == 1) return 2;
    return 1;
}

int main() {
    cout << lucas(10) << endl;
    return 0;
}
