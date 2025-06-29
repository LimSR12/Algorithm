#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {

    int k, n, s, d;
    
    /*
    * n: 배의 수 (0 ≤ n ≤ 200)
    * s: 배의 속도 (하루에 몇 마일 가는지, 1 ≤ s ≤ 100)
    * d: 계약의 마감일까지 남은 일수 (1 ≤ d ≤ 365)
    */
    int dataSetIndex = 1;
    cin >> k;
    while (k--) {
        cin >> n >> s >> d;

        int di, vi;
        /*
        * di: 해당 배가 베니스까지 떨어진 거리 (0 ≤ di ≤ 10000)
        * vi: 해당 배가 실어오는 화물의 가치 (0 ≤ vi ≤ 100000)
        */
        int ducats = 0;
        while (n--) {
            cin >> di >> vi;
            if (di <= s * d) {
                ducats += vi;
            }
        }
        cout << "Data Set " << dataSetIndex++ << ":\n";
        cout << ducats << "\n\n";

    }

    return 0;
}