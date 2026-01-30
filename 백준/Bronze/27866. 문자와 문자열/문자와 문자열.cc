#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;  // 최대 1000
  int i;

  getline(cin, s);
  cin >> i;

  cout << s[i - 1];
}