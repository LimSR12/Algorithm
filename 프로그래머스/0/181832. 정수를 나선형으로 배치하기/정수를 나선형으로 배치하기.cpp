#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0)); // n * n 
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int direction = 0; // 방향(0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위)
    int x = 0, y = 0;
    
    for(int i = 1; i <= n * n; i++){
        answer[x][y] = i;
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || answer[nx][ny] != 0){
            direction = (direction + 1) % 4;
            nx = x + dx[direction];
            ny = y + dy[direction];
        }
        x = nx;
        y = ny;
    }
    
    return answer;
}