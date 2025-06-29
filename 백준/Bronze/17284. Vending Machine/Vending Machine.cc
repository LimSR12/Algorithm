#include <iostream>
#include <string>

using namespace std;

int main() {

    int money = 5000;
    string choice;
    getline(cin, choice);

    for (int i = 0; i < choice.length(); i+=2) {
        //cout << choice[i] << endl;
        if (choice[i] == '1') {
            money -= 500;
        }
        else if (choice[i] == '2') {
            money -= 800;
        }
        else if (choice[i] == '3') {
            money -= 1000;
        }
    }
    cout << money;

    return 0;
}