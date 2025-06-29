#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int b_x, b_y;   // 베시는 8방향
    int d_x, d_y;   // 데이지는 4방향
    int j_x, j_y;

    cin >> b_x >> b_y;
    cin >> d_x >> d_y;
    cin >> j_x >> j_y;

    int daisy = abs(j_x - d_x) + abs(j_y - d_y);
    int bessie = max(abs(j_x - b_x), abs(j_y - b_y));

    if (daisy > bessie) {
        cout << "bessie";
    }
    else if (daisy < bessie) {
        cout << "daisy";
    }
    else {
        cout << "tie";
    }

    return 0;
}