/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
bool impossible = false;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> counter(0, vector<int>(2));
vector<int> marked;
void DFS(int start, int mark){
visited[start] = true;
if (marked[start] != 0 && marked[start] != mark){
	impossible = true;
	return;
}
else if (marked[start] != 0)
	return;
counter[counter.size() - 1][mark - 1]++;
marked[start] = mark;
for (int i = 0; i < adj[start].size(); i++)
		DFS(adj[start][i], 3 - mark);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("decorate.in", "r", stdin); freopen("decorate.out", "w", stdout);
	int N, M, rv = 0;
	int a, b;
	cin >> N >> M;
	adj = vector<vector<int>> (N);
	visited = vector<bool>(N);
	marked = vector<int>(N);
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < N; i++)
		if (!visited[i]){
			counter.push_back(vector<int>(2));
			DFS(i, 1);
		}
	if (impossible)
		cout << -1;
	else{
		for (int i = 0; i < counter.size(); i++)
			rv += max(counter[i][0], counter[i][1]);
		cout << rv;
	}
	return 0;
}

