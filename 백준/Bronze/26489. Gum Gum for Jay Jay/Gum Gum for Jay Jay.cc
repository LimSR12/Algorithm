#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    int count = 0;
    while (getline(cin, str)) {
        if (str == "gum gum for jay jay") {
            count++;
        }
    }

    cout << count;

    return 0;
}