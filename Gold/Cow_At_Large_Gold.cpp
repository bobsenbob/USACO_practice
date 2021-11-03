/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> depth;
vector<int> nearest;
vector<bool> visited;
vector<bool> exits;
int dfs(int start, int deep){
	int rv = INT_MAX;
	int temp = 1;
	visited[start] = true;
	depth[start] = deep;
	if (exits[start])
		rv = 0;
	for (int i = 0; i < adj[start].size(); i++){
		if (!visited[adj[start][i]]){
			temp = 1 + dfs(adj[start][i], deep + 1);
			rv = min(rv, temp);
		}
	}
	nearest[start] = rv;
	return rv;
}
int solve(int start){
	visited[start] = true;
	if (nearest[start] <= depth[start])
		return 1;
	int rv = 0;
	for (int i = 0; i < adj[start].size(); i++)
		if (!visited[adj[start][i]])
			rv += solve(adj[start][i]);
	return rv;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("atlarge.in", "r", stdin); freopen("atlarge.out", "w", stdout);
	int N, K, a, b;
	cin >> N >> K;
	adj = vector<vector<int>>(N, vector<int>(0));
	exits = vector<bool>(N);
	visited = vector<bool>(N);
	depth = vector<int>(N);
	nearest = vector<int>(N);
	for (int i = 0; i < N - 1; i++){
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < N; i++)
		if (adj[i].size() == 1)
			exits[i] = true;
	dfs(K - 1, 0);
	visited = vector<bool>(N, false);
	cout << solve(K - 1);
	return 0;
}

