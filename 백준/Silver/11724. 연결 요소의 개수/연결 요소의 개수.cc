#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int node) {
	if (visited[node]) {
		return;
	}

	visited[node] = true;
	
	for (int next : graph[node]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cnt = 0;	
	for (int i = 1; i < n + 1; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;

	return 0;
}