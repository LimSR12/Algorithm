#include <string>
#include <vector>

using namespace std;

int visited[200];

void DFS(vector<vector<int>> &computers, int n, int index){
    visited[index] = 1;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0 && computers[index][i] == 1){
            DFS(computers, n, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            DFS(computers, n, i);
            answer++;
        }
    }
    
    return answer;
}