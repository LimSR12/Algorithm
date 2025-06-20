#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    
    int N;
    cin >> N;

    int cnt = 0;
    for (int title = 666; ; title++) {
        string str_title = to_string(title);
        if (str_title.find("666") != -1) {
            cnt++;
            if (cnt == N) {
                cout << title; 
                break;
            }
        }
    }
    
    return 0;
}