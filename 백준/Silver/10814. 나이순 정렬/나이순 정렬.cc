#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    
    vector<pair<int, string>> member;
    int N;
    cin >> N;

    while (N--) {
        int age;
        string name;

        cin >> age >> name;
        member.push_back({ age, name });
    }

    stable_sort(member.begin(), member.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        //if (a.first != b.first)
            return a.first < b.first; // age 오름차순
        //return a.second < b.second;   // 이름 알파벳순
        });

    for (auto& iter : member) {
        cout << iter.first << " " << iter.second << endl;
    }

    return 0;
}