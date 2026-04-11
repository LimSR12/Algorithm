#include <iostream>
#include <vector>
using namespace std;

#define MINT_CHOCO_MILK 111
#define MINT_CHOCO 110
#define MINT_MILK 101
#define CHOCO_MILK 11
#define MINT 100
#define CHOCO 10
#define MILK 1

int N, T;
vector<vector<int>> F;
vector<vector<int>> B;

vector<vector<bool>> visited; // 순회에 사용
vector<vector<bool>> leaderMap; // 리더 표시에 사용

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct Leader {
    int row;
    int col;
    int food;
    int belief;
    int rank; // 1: 단일 2: 이중 3: 삼중
};

void morning();
void lunch();
void dinner();
void dfs(int row, int col, vector<pair<int,int>>& group);
bool comp(const Leader& a, const Leader& b);
int mergeFood(int a, int b);
void printTest();
void printAnswer();

int main() {
    /*
    T: mint 100
    C: choco 10
    M: milk   1

    N*N 배열, 
    초기 신봉 : F(i,j) (영향을 받아 변할 수 있다, 3C3)
    초기 신앙심 : B(i, j)
    */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;
    F.resize(N, vector<int>(N));
    B.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));
    leaderMap.resize(N, vector<bool>(N, false));

    // 초기 신봉 음식 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if(c == 'T') F[i][j] = MINT;
            else if (c == 'C') F[i][j] = CHOCO;
            else if (c == 'M') F[i][j] = MILK;
        }
    }

    // 초기 신앙심 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    // 메인 로직
    for (int i = 0; i < T; i++) {
        // 아침, 점심, 저녁 순서로
        morning();
        lunch();
        dinner();
        // printTest();
        // break;
        printAnswer();
    }

    return 0;
}

void morning() {
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { 
            B[i][j]++;
        }
    }
}

void lunch() {
    // 신봉 음식이 같으면 그룹 형성
    // 이때 상하좌우 붙어있을때만 그룹 가능
    // ---
    // 100 100 101
    // 100 10  1
    // 1   10  10
    // ---
    // 이러면 100끼리 그룹, 10끼리 그룹, 1은 그룹 x, 101도 그룹 x
    // 그러면 여기서 그룹을 어떻게 표현할 것인가??
    // 이미 그룹이 표현되어있다? 탐색하면서 무언가를 할텐데 "탐색 가능 조건"으로 신봉 음식 같은 경우를 걸어주자
    visited.assign(N, vector<bool>(N, false));
    leaderMap.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;

            vector<pair<int,int>> group;
            dfs(i, j, group);

            // group 하나 완성
            // 여기서 대표자 찾고 B 갱신
            // group = {(0,0), (0,1), (1,0)}

            pair<int,int> candidate;
            int max = 0;
            for (auto student: group) {
                int row = student.first;
                int col = student.second;

                if(B[row][col] > max || (B[row][col] == max && (row < candidate.first || (row == candidate.first && col < candidate.second)))) {
                    candidate = {row, col};
                    max = B[row][col];
                }
            }

            leaderMap[candidate.first][candidate.second] = true;

            // 이제 group 의 학생들은 leader에게 신앙심 1 넘긴다
            for (auto student: group) {
                int row = student.first;
                int col = student.second;

                if (candidate.first == row && candidate.second == col) continue;

                B[row][col]--;
                B[candidate.first][candidate.second]++;
            }
        }
    }

};

void dfs(int row, int col, vector<pair<int,int>>& group) {
    visited[row][col] = true;
    group.push_back({row, col});

    for (int i = 0; i < 4; i++) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];

        if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= N) continue;
        if (visited[nextRow][nextCol]) continue;
        if (F[nextRow][nextCol] != F[row][col]) continue;

        dfs(nextRow, nextCol, group);
    }
}

void dinner() {
    // 모든 그룹의 대표자들이 신앙을 전파한다.
    // leaderMap 벡터에 저장되어있고,
    // 전파하는 순서는 단일 음식 먼저, 그다음 이중, 그 다음 삼중인데
    // 또 그 안에서의 우선 순위는 대표자의 신앙심 높은 순, 동일하면 row/col 번호 작은 순

    vector<Leader> leaders;
    vector<vector<bool>> defense(N, vector<bool>(N, false));

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (leaderMap[row][col]) { 
                if (F[row][col] == 100 || F[row][col] == 10 || F[row][col] == 1){
                    leaders.push_back({row, col, F[row][col], B[row][col], 1}); 
                }
                if (F[row][col] == 101 || F[row][col] == 110 || F[row][col] == 11){
                    leaders.push_back({row, col, F[row][col], B[row][col], 2}); 
                }
                if (F[row][col] == 111) {
                    leaders.push_back({row, col, F[row][col], B[row][col], 3}); 
                }
            }
        }
    }

    sort(leaders.begin(), leaders.end(), comp);
    
    // 리더들 정보 넣었고, 이제 전파 시작
    vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (auto& leader: leaders) {
        // 리더의 현재 위치 저장용
        int row = leader.row;
        int col = leader.col;

        // 리더가 방어상태라면 전파하지 않음
        if (defense[row][col]) continue;

        int dirIndex = leader.belief % 4; // 0: 위, 1: 아래, 2: 왼쪽, 3: 오른쪽
        int please = leader.belief - 1; // x = B - 1
        leader.belief = 1;
        B[leader.row][leader.col] = 1;

        while(true) {
            row += dir[dirIndex].first;
            col += dir[dirIndex].second;

            // 다음 전파 위치가 칸을 벗어나거나 간절함이 0이면 종료
            if (row >= N || col >= N || row < 0 || col < 0) break;
            if (please == 0) break;

            // 이미 같은 음식 신봉중이면 스킵
            if (F[row][col] == leader.food) continue;

            if (please > B[row][col]) {
                // 강한 전파
                // 대상은 리더와 동일한 음식
                // 리더는 간절함이 y + 1만큼 깎이고 대상의 신앙심은 + 1
                F[row][col] = leader.food;
                please -= (B[row][col] + 1);
                B[row][col]++;
            }
            else {
                // 약한 전파
                // 기존 음식 || 리더 음식
                // 101 + 11 -> 111
                
                F[row][col] = mergeFood(leader.food, F[row][col]);
                B[row][col] += please;
                please = 0;
            }

            if (leaderMap[row][col]) defense[row][col] = true;
            if (please <= 0) break;
        }
    }
};

bool comp(const Leader& a, const Leader& b) {
    if (a.rank != b.rank) return a.rank < b.rank;
    if (a.belief != b.belief) return a.belief > b.belief;
    if (a.row != b.row) return a.row < b.row;
    return a.col < b.col;
}

int mergeFood(int a, int b) {
    int result = 0;

    if (a / 100 > 0 || b / 100 > 0) result += 100;      // 민트
    if ((a / 10) % 10 > 0 || (b / 10) % 10 > 0) result += 10; // 초코
    if (a % 10 > 0 || b % 10 > 0) result += 1;          // 우유

    return result;
}

void printTest() {
    // 출력 (테스트용)
    cout << "\n---F 출력---" << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << F[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n---B 출력---" << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n---leader 출력---" << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << leaderMap[i][j] << " ";
        }
        cout << "\n";
    }
}

void printAnswer() {
    int sum[MINT_CHOCO_MILK + 1] = { 0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum[F[i][j]] += B[i][j];
        }
    }
    int index[7] = { MINT_CHOCO_MILK, MINT_CHOCO, MINT_MILK, CHOCO_MILK, MILK, CHOCO, MINT }; 
    for (int i = 0; i < 7; i++){
        cout << sum[index[i]] << " ";
    }
    cout << "\n";
}
