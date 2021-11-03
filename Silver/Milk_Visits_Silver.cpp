/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> component;
vector<vector<int>> adj;
string demands;
int currComp = 1;
void DFS(int start){
	if (component[start])
		return;
	component[start] = currComp;
	for (int i = 0; i < adj[start].size(); i++)
		if (demands.at(adj[start][i]) == demands.at(start))
			DFS(adj[start][i]);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milkvisits.in", "r", stdin); freopen("milkvisits.out", "w", stdout);
	int N, M, a, b;
	char query;
	cin >> N >> M >> demands;
	adj = vector<vector<int>> (N, vector<int>(0));
	component = vector<int> (N);
	visited = vector<bool>(N, false);
	for (int i = 0; i < N - 1; i++){
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < N; i++)
		if (!component[i]){
			DFS(i);
			currComp++;
		}
	/*for (int i = 0; i < N; i++)
		cout << "i: " << i << " component: " << component[i] << "\n";*/
	for (int i = 0; i < M; i++){
		cin >> a >> b >> query;
		if (component[a - 1] != component[b - 1])
		cout << 1;
		else if (demands.at(a - 1) == query)
		cout << 1;
		else
		cout << 0; 
	}
	return 0;
}

