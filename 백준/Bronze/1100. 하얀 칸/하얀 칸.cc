#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main() {
    
    vector<vector<char>> plate(8, vector<char>(8));

    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            plate[i][j] = s[j];
        }
    }

    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0 && plate[i][j] == 'F') {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}