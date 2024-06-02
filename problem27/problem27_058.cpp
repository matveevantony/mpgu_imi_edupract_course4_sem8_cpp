#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int k, n;
    int inp;
    ifstream inp_file("27.txt");
    inp_file >> k;
    inp_file >> n;
    int array[n];
    for (int i = 0; i <= k; i++) {
        array[i] = 0;
    }
    int count = 0;
    int max_space_sum = 0;
    int max_space_sum_members[2];
    int max_elements[3];
    int max_elements_members[3];
    for (int i = 0; i < 3; i++) {
        max_elements[i] = -10000001;
    }
    while (inp_file >> inp) {
        if (count <= 2 * k) {
            array[count] = inp;
            max_space_sum = array[0] + array[2 * k];
            max_space_sum_members[0] = 0;
            max_space_sum_members[1] = count;
        }
        else {
            array[count] = inp;
            if (max_space_sum < array[count - 2 * k] + array[count]) {
                max_space_sum = array[count - 2 * k] + array[count];
                max_space_sum_members[0] = count - 2 * k;
                max_space_sum_members[1] = count;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (inp >= max_elements[i]) {
                for (int j = i + 1; j < 3; j++) {
                    max_elements[j] = max_elements[j - 1];
                    max_elements_members[j] = max_elements_members[j - 1];
                }
                max_elements[i] = inp;
                max_elements_members[i] = count;
                break;
            }
        }
        count++;
    }
    int max_element;
    bool max_element_set = false;
    for (int i = 0; i < 3; i++) {
        if (!max_element_set && (max_elements_members[i] != max_space_sum_members[0] && max_elements_members[i] != max_space_sum_members[1])) {
            max_element = max_elements[i];
            max_element_set = true;
        }
        else {
            if (max_element <= max_elements[i] && (max_elements_members[i] != max_space_sum_members[0] && max_elements_members[i] != max_space_sum_members[1])) {
                max_element = max_elements[i];
            }
        }
    }
    cout << max_space_sum + max_element << endl;
    return 0;
}
