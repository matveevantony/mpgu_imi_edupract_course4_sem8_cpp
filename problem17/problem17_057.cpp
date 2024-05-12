#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    int k = 0;
    vector<int> triplesSum;
    int maxEnd17 = 0;
    int countTriples = 0;
    int maxTripleSum = 0;
    int inp;
    int tripleInp[3];
    tripleInp[0] = 0;
    tripleInp[1] = 0;
    tripleInp[2] = 0;
    ifstream inp_file("17.txt");
    while (inp_file >> inp) {
        if (inp % 100 == 17 && inp > maxEnd17) {
            maxEnd17 = inp;
        }
        tripleInp[0] = tripleInp[1];
        tripleInp[1] = tripleInp[2];
        tripleInp[2] = inp;
        if (k > 1) {
            int countFourSign = 0;
            int countDivisibleBy5 = 0;
            for (int i = 0; i < 3; i++) {
                if (tripleInp[i] > 999 && tripleInp[i] < 10000) {
                    countFourSign++;
                }
                if (tripleInp[i] % 5 == 0) {
                    countDivisibleBy5++;
                }
            }
            if (countFourSign == 2 && countDivisibleBy5 > 0) {
                triplesSum.push_back(tripleInp[0] + tripleInp[1] + tripleInp[2]);
            }
        }
        k++;
    }
    for (auto i = triplesSum.begin(); i != triplesSum.end(); i++) {
        if (*i > maxEnd17) {
            countTriples++;
            if (*i > maxTripleSum) {
                maxTripleSum = *i;
            }
        }
    }
    cout << countTriples << " " << maxTripleSum << endl;
    return 0;
}
