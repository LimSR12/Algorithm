#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int min = 1000000, max = -1000000;
    while (n--) {
        int num;
        cin >> num;
        if (num > max)max = num;
        if (num < min)min = num;
    }
    cout << min << " " << max;

    return 0;
}