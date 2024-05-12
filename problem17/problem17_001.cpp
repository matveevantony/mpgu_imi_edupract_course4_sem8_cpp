#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int k = 0;
    int count = 0;
    int maxPairSum = -20001;
    int inp;
    int prevInp;
    ifstream inp_file("17.txt");
    while (inp_file >> inp) {
        if (k > 0) {
            if ((inp % 3 == 0) || (prevInp % 3 == 0)) {
                count++;
                if (maxPairSum < inp + prevInp) {
                    maxPairSum = inp + prevInp;
                }
            }
        }
        prevInp = inp;
        k++;
    }
    cout << count << " " << maxPairSum << endl;
    return 0;
}
