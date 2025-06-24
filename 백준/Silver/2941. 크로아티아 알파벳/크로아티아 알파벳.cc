#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {

    vector<string> croatia = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

    string s;
    cin >> s;

    for (auto& iter : croatia) {
        size_t pos;
        while ((pos = s.find(iter)) != string::npos) {
            s.replace(pos, iter.length(), "*"); // 크로아티아 문자 위치를 *로 치환해버리면 마지막에 문자열 수 세면 됨
        }
    }
    
    cout << s.length() << '\n';

    return 0;
}