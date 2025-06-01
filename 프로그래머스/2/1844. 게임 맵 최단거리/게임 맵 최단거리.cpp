#include<string>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

int dn[] = {0, 1, 0, -1};
int dm[] = {1, 0, -1, 0};

void DFS(vector<vector<int>> &maps, vector<vector<bool>> &visited, int n, int m, int dist, int &min_dist){
    int row = maps.size();
    int col = maps[0].size();
    
    if(n == row - 1 && m == col - 1){
        min_dist = min(dist, min_dist);
        return;
    }
    
    visited[n][m] = true;
    
    for(int i = 0; i < 4; i++){
        int next_n = n + dn[i];
        int next_m = m + dm[i];
        if(next_n <= row - 1 && next_m <= col - 1 && next_n >= 0 && next_m >= 0 && 
           maps[next_n][next_m] == 1 && !visited[next_n][next_m]){
            DFS(maps, visited, next_n, next_m, dist + 1, min_dist);
        }
    }
    
    visited[n][m] = false;
}

int BFS(vector<vector<int>> &maps){
    int row = maps.size();
    int col = maps[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<vector<int>> dist(row, vector<int>(col, 0));
    
    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = true;
    dist[0][0] = 1;
    
    while(!q.empty()){
        auto [n, m] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int next_n = n + dn[i];
            int next_m = m + dm[i];
            if(next_n <= row - 1 && next_m <= col - 1 && next_n >= 0 && next_m >= 0 && 
                maps[next_n][next_m] == 1 && !visited[next_n][next_m]){
                visited[next_n][next_m] = true;
                dist[next_n][next_m] = dist[n][m] + 1;
                q.push({next_n, next_m});
            }
        }
    }
    
    if(dist[row - 1][col - 1] == 0){
        return -1;
    }else{
        return dist[row - 1][col - 1];
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    answer = BFS(maps);
    
    return answer;
}