#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> arr(9);
    int max = 0;
    int index = -1;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }

    cout << arr[index] << "\n" << index + 1;

    return 0;
}