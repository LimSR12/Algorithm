#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    cin >> str;

    int ones = 0, zeros = 0;
    char prev = 'a';
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != prev) {
            if (str[i] == '1') {
                ones++;
            }
            else if(str[i] == '0') {
                zeros++;
            }
        }
        prev = str[i];
    }
    if (ones < zeros) 
        cout << ones;
    else 
        cout << zeros;

    return 0;
}