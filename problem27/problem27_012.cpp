#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    int inp, prev_inp;\
    bool n_entered = false;
    bool even = false;
    int sum = 0;
    int r1[2] = {-1, -1};
    int r2[2] = {-1, -1};
    ifstream inp_file("27.txt");
    while (inp_file >> inp) {
        if (!n_entered) {
            n = inp;
            n_entered = true;
            continue;
        }
        if (even) {
            sum += max(prev_inp, inp);
            int dif = abs(inp - prev_inp);
            if (dif % 3 == 1) {
                if (dif < r1[0] || r1[0] == -1) {
                    r1[1] = r1[0];
                    r1[0] = dif;
                }
                else {
                    if (dif < r1[1] || r1[1] == -1) {
                        r1[1] = dif;
                    }
                }
            }
            if (dif % 3 == 2) {
                if (dif < r2[0] || r2[0] == -1) {
                    r2[1] = r2[0];
                    r2[0] = dif;
                }
                else {
                    if (dif < r2[1] || r2[1] == -1) {
                        r2[1] = dif;
                    }
                }
            }
            even = false;
        }
        else {
            prev_inp = inp;
            even = true;
        }
    }
    if (sum % 3 == 0) {
        cout << sum << endl;
        return 0;
    }
    if (sum % 3 == 1) {
        if (r1[0] < r2[0] + r2[1]) {
            cout << sum - r1[0] << endl;
            return 0;
        }
        cout << sum - (r2[0] + r2[1]) << endl;
        return 0;
    }
    if (r2[0] < r1[0] + r1[1]) {
        cout << sum - r2[0] << endl;
        return 0;
    }
    cout << sum - (r1[0] + r1[1]) << endl;
    return 0;
}
