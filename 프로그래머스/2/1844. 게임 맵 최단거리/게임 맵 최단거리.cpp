#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int row = maps.size(); // 행 개수
    int col = maps[0].size(); // 열 개수

    int dr[] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
    int dc[] = {0, 0, -1, 1};
    
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<vector<int>> dist(row, vector<int>(col, 0));
    
    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = true;
    
    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        if(r == row - 1 && c == col - 1) {
            return dist[r][c];
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            
            if (nr >= 0 && nr < row && nc >= 0 && nc < col && maps[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    return -1;
}

