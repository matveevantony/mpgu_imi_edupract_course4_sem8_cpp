#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int d = 126;
    int r[d];
    int maxEl[d];
    int prevMaxEl0 = 0;
    int prevMaxElDdiv2 = 0;
    for (int i = 0; i < d; i++) {
        r[i] = 0;
        maxEl[i] = 0;
    }
    int count = 0;
    int maxSum = 0;
    int inp;
    ifstream inp_file("17.txt");
    while (inp_file >> inp) {
        r[inp % d]++;
        if (maxEl[inp % d] < inp) {
            if (inp % d == 0) {
                prevMaxEl0 = maxEl[0];
            }
            if ((d % 2 == 0) && (inp % d == d / 2)) {
                prevMaxElDdiv2 = maxEl[d / 2];
            }
            maxEl[inp % d] = inp;
        }
    }
    for (int i = 0; i <= d / 2; i++) {
        if ((i == 0) || ((d % 2 == 0) && (i == d / 2))) {
            count += r[i] * (r[(d - i) % d] - 1) / 2;
        }
        else {
            count += r[i] * r[d - i];
            if (maxEl[i] + maxEl[d - i] > maxSum) {
                maxSum = maxEl[i] + maxEl[d - i];
            }
        }
    }
    if ((maxEl[0] + prevMaxEl0 > maxSum) && prevMaxEl0 != 0) {
        maxSum = maxEl[0] + prevMaxEl0;
    }
    if (d % 2 == 0 && (maxEl[d / 2] + prevMaxElDdiv2 > maxSum && prevMaxElDdiv2 != 0)) {
        maxSum = maxEl[d / 2] + prevMaxElDdiv2;
    }
    cout << count << " " << maxSum << endl;
    return 0;
}
