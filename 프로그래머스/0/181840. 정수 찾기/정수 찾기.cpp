#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;
    
    if (find(num_list.begin(), num_list.end(), n) != num_list.end()) {
        answer = 1;
    }
    
    return answer;
}