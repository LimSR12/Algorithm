#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;

    int count = 0;
    while (N--) {
        vector<int> alphabet(123, 0);
        int isGroupWord = 1;
        string word;
        cin >> word;

        for (int i = 0; i < word.length(); i++) {
            if (i > 0 && word[i] == word[i - 1]) continue;
            if (alphabet[(int)word[i]] == 0) {// word[i] == 'a' 라면 alphabet[97]
                alphabet[(int)word[i]] = 1;
            }
            else {
                isGroupWord = 0;
                break;
            }
        }
        if (isGroupWord) {
            count++;
        }
    }
    cout << count;

    return 0;
}