#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a = 201455;
    int b = 201470;
    vector<int> divisors;
    for (int x = a; x <= b; x++) {
        divisors.clear();
        int count = 0;
        for (int i = 1; i <= x / 2; i++) {
            if (x % i == 0 && count <= 4) {
                count++;
                divisors.push_back(i);
            }
        }
        divisors.push_back(x);
        count++;
        if (count == 4) {
            for (auto i = divisors.begin(); i != divisors.end(); i++) {
                cout << *i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
