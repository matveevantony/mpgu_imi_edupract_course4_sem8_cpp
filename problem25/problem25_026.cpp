#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a = 600000;
    int count = 0;
    int x = a;
    while (count < 5) {
        for (int i = 2; i <= x / 2; i++) {
            if (x % i == 0 && (i % 10 == 7 && i != 7)) {
                cout << x << " " << i << endl;
                count++;
                break;
            }
        }
        x++;
    }
    return 0;
}
